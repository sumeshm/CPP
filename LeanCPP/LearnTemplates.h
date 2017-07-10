#ifndef LEARNSTL_H
#define LEARNSTL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class LearnTemplates
{
    public:
        LearnTemplates();
        virtual ~LearnTemplates();

        virtual int printOptions(string p_msg = " <> ");

    protected:
        void testTemplateFunction();
        void testTemplateClass();

        template <class T>
        T addition(T a, T b) { return (a+b); }

        template <class T1, class T2>
        T1 getSmaller(T1 a, T2 b) { return ((a > b) ? b : a); }

    private:
};


template <class T3>
class TemplateClass
{
    private:
        T3 m_data1, m_data2;

    public:
        TemplateClass(T3 a, T3 b);
        T3 getSmaller();
};

template <class T3>
T3 TemplateClass<T3>::getSmaller()
{
    return ((m_data1 > m_data2) ? m_data2 : m_data1);
}

template <class Data>
class MyUtil
{
    public:
    MyUtil();
    ~MyUtil();

    Data add(Data t1, Data t2);
};




// --------------- Custom Stack --------------- //

template <typename T>
class StackTemplate
{
    list<T> sList;
public:
    T& pop();
    void push(T& t);
    T& peek();
};


// the template specialized for std::string
template <>
class StackTemplate<string>
{
    list<string> sList;
public:
    string pop();
    void push(string t);
    string peek();
};



#endif // LEARNSTL_H
