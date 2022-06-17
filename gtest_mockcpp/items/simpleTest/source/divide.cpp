#include <gtest/gtest.h>  
#include "divide.h"  
   
TEST(Divide, ByZero) {  
 EXPECT_NO_THROW(divide(-1, 2));  
   
 EXPECT_ANY_THROW({  
    int k = 0;  
    divide(k, k);  
 });  
   
 EXPECT_THROW(divide(100000, 0), std::invalid_argument);  
} 