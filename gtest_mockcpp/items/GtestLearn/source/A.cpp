#include "A.h"
A::A( int a ){
    this->_a = a;
}
A::~A( ){
}
void A::addA( int a ){
    this->_a += a;
}
int A::getA( ){
    return this->_a;
}