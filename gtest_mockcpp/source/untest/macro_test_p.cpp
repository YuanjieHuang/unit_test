// #include <stdio.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
//Step1:申明一个呼叫参数类，该类主要用于TEST_P宏中实现的测试逻辑使用
class CallArgs
{
public:
  CallArgs(bool hasAudio,bool hasVideo):
    _hasAudio(hasAudio),_hasVideo(hasVideo){}

  bool audio(){ return _hasAudio;}
  bool video(){ return _hasVideo;}

private:
  bool _hasAudio;
  bool _hasVideo;
};

//Step2:申明一个呼叫类，该类同时也是TEST_P宏的第一个参数test_case_name
//      该类继承了TestWithParam<CallArgs>模版类，从而使得CallArgs类与Call类进行了关联。
class Call: public ::testing::TestWithParam<CallArgs>
{
};

//Step3: 使用INSTANTIATE_TEST_CASE_P宏，对Call类进行类相关多个的参数设置
//       这里只添加了两个参数CallArgs(true,true)和CallArgs(true,false)，事实上，可以添加多大50个参数。
//       这里使用参数生成器::testing::Values，GTest定义了了很多参数生成器。
INSTANTIATE_TEST_CASE_P(VOIP, Call, ::testing::Values(
    CallArgs(true,true),
    CallArgs(true,false)
    ) );

//Step4: 编写了使用TEST_P宏实现的测试用例
//       使用了TestWithParam<CallArgs>类的GetParam()接口获取参数CallArgs
//       实际上这是两个测试用例，即该代码段会执行两个，参数分别为CallArgs(true,true)和CallArgs(true,false)
TEST_P( Call, makeCall)
{
  CallArgs args = GetParam();
  ASSERT_TRUE( makeCall(args.audio(),args.video()) );
}


template <typename T>
class TestWithParam : public Test, public WithParamInterface<T> 
{
};

template <typename T>
class WithParamInterface 
{
public:
  typedef T ParamType;
  virtual ~WithParamInterface() {}

  const ParamType& GetParam() const 
  {
    GTEST_CHECK_(parameter_ != NULL)
        << "GetParam() can only be called inside a value-parameterized test "
        << "-- did you intend to write TEST_P instead of TEST_F?";
    return *parameter_;
  }

 private:
  static void SetParam(const ParamType* parameter) 
  {
    parameter_ = parameter;
  }

  //不太理解为何声明为static，可能是为了节约内存的考虑？
  //申明为static后，需要保证每次运行到不同的测试用例时，其值能够匹配。
  static const ParamType* parameter_;

  //申明了友元类ParameterizedTestFactory，使得其可以修改调用SetParam()
  template <class TestClass> friend class internal::ParameterizedTestFactory;
};

template <typename T>
const T* WithParamInterface<T>::parameter_ = NULL;

#define INSTANTIATE_TEST_CASE_P(VOIP, Call, Values,... ) ) 

ParamGenerator<CallArgs> gtest_VOIPCall_EvalGenerator_() { return ValueArray2(); } 

std::string gtest_VOIPCall_EvalGenerateName_(const TestParamInfo<CallArgs>& info) 
{ 
  return GetParamNameGen<CallArgs>(info); 
} 

int gtest_VOIPCall_dummy_  = 
  UnitTest::GetInstance()->parameterized_test_registry(). 
    GetTestCasePatternHolder<Call>(Call, CodeLocation(__FILE__, __LINE__))->
      AddTestCaseInstantiation(VOIP,
                    &gtest_VOIPCall_EvalGenerator_, 
                    &gtest_VOIPCall_EvalGenerateName_, 
                    __FILE__, __LINE__)

//Values
template <typename T1, typename T2>
internal::ValueArray2<T1, T2> Values(T1 v1, T2 v2) {
  return internal::ValueArray2<T1, T2>(v1, v2);
}

//ValueArray2 模版类
//重载了operator ParamGenerator<T>() const；
template <typename T1, typename T2>
class ValueArray2 
{
public:
  ValueArray2(T1 v1, T2 v2) : v1_(v1), v2_(v2) {}

  template <typename T>
  operator ParamGenerator<T>() const 
  {
    const T array[] = {static_cast<T>(v1_), static_cast<T>(v2_)};
    return ValuesIn(array);
  }

 private:

  void operator=(const ValueArray2& other);

  const T1 v1_;
  const T2 v2_;
};

template<typename T>
class ParamGenerator 
{
public:
  typedef ParamIterator<T> iterator;

  explicit ParamGenerator(ParamGeneratorInterface<T>* impl) : impl_(impl) {}

  ParamGenerator(const ParamGenerator& other) : impl_(other.impl_) {}

  ParamGenerator& operator=(const ParamGenerator& other) 
  {
    impl_ = other.impl_;
    return *this;
  }

  iterator begin() const { return iterator(impl_->Begin()); }
  iterator end() const { return iterator(impl_->End()); }

private:
  linked_ptr<const ParamGeneratorInterface<T> > impl_;
};


// ParamGeneratorInterface模版类

template <typename T>
class ParamGeneratorInterface 
{
public:
  typedef T ParamType;

  virtual ~ParamGeneratorInterface() {}

  virtual ParamIteratorInterface<T>* Begin() const = 0;
  virtual ParamIteratorInterface<T>* End() const = 0;
};

template <class ParamType>
struct TestParamInfo 
{
  TestParamInfo(const ParamType& a_param, size_t an_index) :
    param(a_param),
    index(an_index) {}

  ParamType param;
  size_t index;
};

//默认生成包含索引的字符串
template <class ParamType>
std::string DefaultParamName(const TestParamInfo<ParamType>& info) {
  Message name_stream;
  name_stream << info.index;
  return name_stream.GetString();
}

template <class ParamType, class ParamNameGenFunctor>
ParamNameGenFunctor GetParamNameGen(ParamNameGenFunctor func) {
  return func;
}

template <class ParamType>
struct ParamNameGenFunc 
{
  typedef std::string Type(const TestParamInfo<ParamType>&);
};

template <class ParamType>
typename ParamNameGenFunc<ParamType>::Type *GetParamNameGen() 
{
  return DefaultParamName;
}


struct PrintToStringParamName 
{
  template <class ParamType>
  std::string operator()(const TestParamInfo<ParamType>& info) const 
  {
    return PrintToString(info.param);
  }
};

