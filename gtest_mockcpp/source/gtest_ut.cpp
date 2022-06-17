extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "ex_func.h"
#include "sort.h"
}

#include <limits.h>
#include <mockcpp/mockcpp.hpp>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <string>

// using namespace std;
using namespace testing;

// void func(int var)
// {
// }
// void test()
// {
//     int var = 10;
//     func(var);
// }
// TEST(sample test)
// {
//     int var;
//     MOCKER(func)
//         .stubs()
//         .with(spy(var));
//         .with(eq(10));

//     test();
//     ASSERT_EQ(var, 10);    
// }

bool print_helloworld(void)
{
    printf("mockcpp helloworld\n");
    return true;
}

bool print_fake_helloworld(void)
{
    printf("Fake mockcpp helloworld\n");
    return false;
}

bool mockcpp_helloworld(void)
{
    return print_helloworld();
}

TEST(mockercpp, helloworld) {
    bool ret;
    MOCKER(print_helloworld)
        .stubs()
        .will(invoke(print_fake_helloworld));
    ret = mockcpp_helloworld();
    EXPECT_EQ(false, ret);
}

TEST(StringMothodTest, strcmp) {
    const char *cmp0 = "hello";
    const char *cmp1 = "hello";
    EXPECT_EQ(strcmp(cmp0, cmp1), 0);
}
// TEST(sort, swap)
// {
//     int a = 1, b = 2;
//     swap(&a, &b);
//     EXPECT_EQ(a, 2);
// }

// TEST(sample, addTest)
// {
//     MOCKER(add)
//         .expects(once())
//         .with(eq(1), eq(2))
//         .will(returnValue(100));

//     ASSERT_EQ(100, add(1, 2));
//     ASSERT_EQ(50, add(2, 3));
// }
class GtestUt : public testing::Test
{
protected:
    void SetUp() override
    {
        std::cout << "--------------------Gtest_Ut SetUP-------------------" << std::endl;
    }

    void TearDown() override
    {
        std::cout << "--------------------Gtest_Ut TearDown----------------" << std::endl;
        GlobalMockObject::verify();
    }
    
};

class Mock_FOO {
public:
    MOCK_METHOD1(mock_test_struct_func, int(struct test_t *test));
}mocker;


int mock_test_struct_func(struct test_t *test)
{
    return mocker.mock_test_struct_func(test);
}

TEST_F(GtestUt, ut_add_01)
{
    int ret;

    ret = add(1, 2);
    EXPECT_EQ(3, ret);
}

TEST_F(GtestUt, ut_add_02)
{
    int ret;
    struct test_t test;

    test.a = 1;
    test.b = 1;

    MOCKER(multi)
    .expects(atMost(20))
    .will(returnValue(100));
    ret = add_struct(&test);
    EXPECT_EQ(ret, 100);
}

TEST_F(GtestUt, ut_add_03)
{
    int ret;
    struct test_t test;

    test.a = 10;
    test.b = 11;

    MOCKER(multi)
    // .expects(atMost(20))
    .stubs()
    .will(returnValue(30));
    // .id(1);
    ret = add_struct(&test);
    EXPECT_EQ(ret, 30);

    // MOCKER(multi)
    // .expects(atMost(20))
    // .will(returnValue(100));
    // ret = add_struct(&test);
    // EXPECT_EQ(ret, 21);
}

TEST_F(GtestUt, ut_add_04)
{
    int ret;
    int a, b;
    struct test_t test;

    test.a = 10;
    test.b = 11;
    test.p_func = mock_test_struct_func;
    EXPECT_CALL(mocker, mock_test_struct_func(&test)).WillRepeatedly(Return(10));

    ret = test_struct_func(&test);
    EXPECT_EQ(ret, 10);
}

TEST_F(GtestUt, ut_add_05)
{
    int ret,ret2;
    int ex_value;
    MOCKER(ex_get_value)
    .expects(exactly(1))
    .will(returnValue(1));
    // .then(returnValue(0xFFFF));
    ret = test_stub_func();
    EXPECT_EQ(ret, 1);

    // MOCKER(ex_get_value)
    // .stubs()
    // .will(returnValue(0xFFFF));
    // ret2 = test_stub_func();
    // EXPECT_EQ(ret2, 666);
}

TEST_F(GtestUt, test06)
{
    int i=0,repeat_cnt = 20,expect_var = 100;
    //入参1,2:前repeat_cnt次，返回值为expect_var；第repeat_cnt+1次，返回值expect_var+1
    MOCKER(add)
        .defaults()
        .with(eq(1), eq(2))
        .will(repeat(expect_var, repeat_cnt))
        .then(returnValue(expect_var+1));
    //入参3,4:第一次返回值为expect_var；第2,3,4....次，返回值expect_var+1
    MOCKER(add)
        .defaults()
        .with(eq(3), eq(4))
        .will(returnValue(expect_var))
        .then(returnValue(expect_var+1));
 
 
    for(i = 0; i < repeat_cnt; i++)
    {
      EXPECT_EQ(expect_var, add(1,2));  
    }
    EXPECT_EQ(expect_var + 1, add(1,2));
    
    EXPECT_EQ(expect_var, add(3,4));
    EXPECT_EQ(expect_var+1, add(3,4));//之后的返回值均为expect_var+1
    EXPECT_EQ(expect_var+1, add(3,4));//第3次
}

void testMtehodParaInOut(int input,int *p_output)
{
    *p_output = input +1;
}
TEST(return_pointer, outBoundP_test07)
{
    int in_var = 10,expect_var = 12,real_var1 = 0; 
    MOCKER(testMtehodParaInOut)
        .stubs()
        .with(eq(in_var),outBoundP(&expect_var,sizeof(expect_var))); //指定出参的指针内容为12
    testMtehodParaInOut(in_var,&real_var1);//调用后，real_var1的指针内容为12
    EXPECT_EQ(expect_var, real_var1);
}

TEST_F(GtestUt, my_div)
{
    int ret;

    ret = test_my_div(6, 3);
    EXPECT_EQ(2, ret);
}

