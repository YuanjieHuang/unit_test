#include <gtest/gtest.h>  
#include "addupto.h"  
   
class AddUpToTest : public testing::TestWithParam<unsigned>  
{  
public:  
    AddUpToTest() { n_ = GetParam(); }  
protected:  
    unsigned n_;  
};  
   
TEST_P(AddUpToTest, Calibration) {  
    EXPECT_EQ(NaiveAddUpTo(n_), FastAddUpTo(n_));  
}  
   
INSTANTIATE_TEST_CASE_P(  
    NaiveAndFast, // prefix  
    AddUpToTest,   // test case name  
    testing::Range(1u, 1000u) // parameters  
); 