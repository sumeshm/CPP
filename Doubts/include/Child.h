#ifndef CHILD_H
#define CHILD_H

#include "Parent.h"


class Child : public Parent
{
    public:
        Child()
        {
            ::Parent();
        }
        virtual ~Child() {}

        //int m_data;
    protected:

    private:
};

#endif // CHILD_H
