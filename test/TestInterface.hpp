#ifndef __TEST_INTERFACE__
#define __TEST_INTERFACE__


#include <iostream>

class TestInterface{
private:
   std::string errorMsg;
public:
    TestInterface(std::string msg);
    virtual void runTests() = 0;
};


#endif
