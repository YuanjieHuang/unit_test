#include <stdio.h>
#include "ex_func.h"

int ex_get_value(int *a)
{
    if (a == NULL) {
        printf("get null pointer %p\n", a);
        return 0xFFFF;
    }
    *a = 1011;
    printf("run stub func, get value %d\n", *a);
    return *a;
}
