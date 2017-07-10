#ifndef TESTINHERITANCE_H
#define TESTINHERITANCE_H

#include <iostream>

using namespace std;

class Parent
{
protected:
    int a;
public:
        Parent()            { cout << "Parent()" << endl; a = 0;    }
        virtual ~Parent()   { cout << "~Parent()" << endl;          }

        Parent(const Parent& p_parent)              { cout << "Parent(copy_constructor)" << endl;  }
        void operator = (const Parent& p_parent) { cout << "Parent(= operator)" << endl;  }

        virtual void dummyFunction() { cout << "Parent: dummyFunction: a=" << a << endl; }

        enum class ParentEnum {parent_one, parent_two};
};

class Child : public Parent
{
  public:
        Child()            { cout << "Child()" << endl;   }
        virtual ~Child()   { cout << "~Child()" << endl;  }

        virtual void dummyFunction() override final { cout << "Child: dummyFunction: a=" << a << endl; }
        virtual void someFunction() final {};

        using Parent::a;
};

class TestInheritance
{
    public:
        TestInheritance();
        virtual ~TestInheritance();
    protected:
    private:
};

#endif // TESTINHERITANCE_H
