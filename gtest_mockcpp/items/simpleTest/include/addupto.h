#pragma once  
   
inline unsigned NaiveAddUpTo(unsigned n) {  
    unsigned sum = 0;  
    for(unsigned i = 1; i <= n; ++i) sum += i;  
    return sum;  
}  
   
inline unsigned FastAddUpTo(unsigned n) {  
    return n*(n+1)/2;  
} 