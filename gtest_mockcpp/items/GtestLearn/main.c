#include <stdio.h>
#include "include/func.h"
 
int main(int argc, char **argv) {
    int ret = 0;
    struct test_t test;

     ret = add(1, 2);
     printf("Get add result: %d\n", ret);
 
     test.a = 10;
     test.b = 12;
     ret = add_struct(&test);
     printf("Get add struct result: %d\n", ret);
 
     test.p_func = NULL;
     ret = test_struct_func(&test);
     printf("Get test struct result: %d\n", ret);
 
     ret = test_stub_func();
     printf("Get test stub func result: %d\n", ret);
 
     return 0;
}