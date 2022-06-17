#pragma once  
#include <stdexcept>  
   
int divide(int dividend, int divisor) {  
 if(!divisor) {  
    throw std::length_error("can't be divided by 0"); // 故意的  
 }  
 return dividend / divisor;  
}