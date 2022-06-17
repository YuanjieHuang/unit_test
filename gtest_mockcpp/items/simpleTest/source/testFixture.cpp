#include "add.h"  
#include <stdio.h>  
#include <gtest/gtest.h>  
   
class AddTest: public testing::Test  
{  
public:  
 virtual void SetUp()    { puts("SetUp()"); }  
 virtual void TearDown() { puts("TearDown()"); }  
};  
   
TEST_F(AddTest, 正数) {  
 ASSERT_GT(Add(1,2), 3); // 故意的  
 ASSERT_EQ(Add(4,5), 6); // 也是故意的  
} 