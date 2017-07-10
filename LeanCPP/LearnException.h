#ifndef LEARNEXCEPTION_H
#define LEARNEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

class LearnException
{
    public:
        LearnException();
        virtual ~LearnException();

        virtual int printOptions(string p_msg = " <> ");

    protected:
    private:
};

class MyException : public exception
{
    public:
    const char * what () const throw ()
    {
        return "MyException: well there you go..";
    }
};

#endif // LEARNEXCEPTION_H
