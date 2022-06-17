#include "add.h"  
#include <gtest/gtest.h>  
   
TEST(Add, negtive) {  
 EXPECT_EQ(Add(-1,-2), -3);  
 EXPECT_GT(Add(-4,-5), -6); // 故意的  
}  
   
TEST(Add, positive) {  
 EXPECT_EQ(Add(1,2), 3);  
 EXPECT_GT(Add(4,5), 6);  
//  ASSERT_EQ(M[i], N[j]) << "i = " << i << ", j = " << j;
} 