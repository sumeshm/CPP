#include <iostream>

#include "Child.h"
#include "Child.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Parent* p = new Child();
    cout << "data=" << p->m_data << endl;

    Child* c = new Child();
    cout << "data=" << c->m_data << endl;

    return 0;
}
