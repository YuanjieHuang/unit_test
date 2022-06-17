#include <stdio.h>
#include "ex_func.h"
#include "func.h"

int add(int a, int b)
{
    printf("start to compute the sum of a %d and b %d\n", a, b);
    return a + b;
}

int multi(int a, int b)
{
    printf("start to compute the multi of a %d and b %d\n", a, b);
    return a * b;
}

int add_struct(struct test_t *test)
{
    int sum = 0;
    int multi_v = 0;

    printf("start to compute the sum of a %d and b %d\n", test->a, test->b);

    sum = test->a + test->b;
    multi_v = multi(test->a, test->b);
    if (sum > multi_v) {
        return sum;
    }

    return multi_v;
}

int test_struct_func(struct test_t *test)
{
    if (test->p_func == NULL) {
        printf("get null func pointer\n");
        return 0xFFFF;
    }
    printf("start ro run test_struct_func with a %d b %d\n", test->a, test->b);
    return test->p_func(test);
}

int test_stub_func()
{
    int ret;
    int a = 0;

    ret = ex_get_value(&a);
    if (ret == 0xFFFF) {
        printf("get extern value failed, ret %d\n", ret);
        return 666;
    }

    printf("get extern value succeed, ex value %d\n", a);
    return ret;
}

int test_my_div(int a, int b)
{
    printf("a:%d/b:%d=%c ",a, b, a/b);
    return a/b;
}
