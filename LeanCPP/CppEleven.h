#ifndef CPPELEVEN_H
#define CPPELEVEN_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class CppEleven
{
    public:
        CppEleven();
        virtual ~CppEleven();

        virtual int printOptions(string p_msg = " <> ");

    protected:
        vector<int> m_dataArray;

        virtual void reBuild();

    private:
};

#endif // CPPELEVEN_H
