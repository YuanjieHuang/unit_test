#include <mockcpp/mockcpp.hpp>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
/*
check约束关键字的用法。 约束关键字中，有很多都是对入参进行检查的，比如eq、neq、lt、gt等等，但它们都只实现了非常简单的检查。
 如果用户想做一个定制化的检查，那么就可以用check。 
 例1：假设用户想检查入参p指向的结构的字段b是不是10，那么可以如下这样写：
*/
struct AA 
{
    int a;
    int b;
};

void func(int in, AA *p)
{
}

// 实现一个检查函数，入参类型跟要检查的入参相同，返回值为bool，返回true表示检查通过。
bool check_func(AA *p)
{
    if ( p->b == 10)
    {
        return true;
    }
    return false;
}

TEST(sample, test)
{
    MOCKER(func)
        .stubs()
        .with(any(), check(check_func));
    func(in, p);
}


// 例2：如果需要检查b是否小于某个给定的数，而且有多个用例，每个用例中与b比较的数不同，则可以使用仿函数的方式。

// 实现一个仿函数类，即重载“()”运算符的类。
struct CheckFunctor 
{
    CheckFunctor(int _base) : base(_base){}
    bool operator ()(AA *p)
    {
        if (p->b < base)
               return true;
        return false;
    }
    int base;
};

TEST(keyword_check less_than_100)
{
    MOCKER(func)
        .stubs()
        .with(any(), check(CheckFunctor(100)));
    func(in, p);
}

TEST(keyword_check less_than_200)
{
    MOCKER(func)
        .stubs()
        .with(any(), check(CheckFunctor(200)));
    func(in, p);
}
// 带有返回值的函数，MOCKER后面必须有will，否则mockcpp认为无返回值，校验时会发现返回类型不匹配。