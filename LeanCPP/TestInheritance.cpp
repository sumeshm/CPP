#include "TestInheritance.h"

TestInheritance::TestInheritance()
{
    Parent* obj = new Child();
    obj->dummyFunction();
    delete obj;

    Child* obj2 = new Child();
    obj2->a = 10;
    obj2->dummyFunction();
    delete obj2;
}

TestInheritance::~TestInheritance()
{
    //dtor
}
