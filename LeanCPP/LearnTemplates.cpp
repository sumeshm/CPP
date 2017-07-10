#include "LearnTemplates.h"

LearnTemplates::LearnTemplates()
{
    //ctor
}

LearnTemplates::~LearnTemplates()
{
    //dtor
}

void LearnTemplates::testTemplateFunction()
{
    string l_msgA = "abc";
    string l_msgB = "xyz";

    cout << "Template-Function addition (only one template):" << endl;
    cout << "\t Add(2, 4)=" << addition(2, 4) << endl;
    cout << "\t Add(2.20, 4.50)=" << addition(2.2, 4.5) << endl;
    cout << "\t Add(123456789, 1)=" << addition(123456789, 1) << endl;
    cout << "\t Add('A', 'Z')=" << addition('A', 'Z') << endl;
    cout << "\t Add(\"abc\", \"xyz\")=" << addition(l_msgA, l_msgB) << endl;

    cout << "Template-Function get-smaller (two types of template):" << endl;
    cout << "\t GetSmaller(2, 4)=" << getSmaller(2, 4) << endl;
    cout << "\t GetSmaller(2.20, 4.50)=" << getSmaller(2.2, 4.5) << endl;
    cout << "\t GetSmaller(123456789, 1)=" << getSmaller(123456789, 1) << endl;
    cout << "\t GetSmaller('A', 'Z')=" << getSmaller('A', 'Z') << endl;
    cout << "\t GetSmaller(\"abc\", \"xyz\")=" << getSmaller(l_msgA, l_msgB) << endl;
}

void LearnTemplates::testTemplateClass()
{
    cout << "Template-class addition (only one template):" << endl;
    //TemplateClass<int> l_tempInstance(1, 2);
    //
    //cout << "\t TemplateClass.GetSmaller(1, 2)=" << l_tempInstance.getSmaller() << endl;

}


template <class Data>
Data MyUtil<Data>::add(Data t1, Data t2)
{
    return (t1 + t2);
}


// --------------- Custom Stack --------------- //

template <typename T>
void StackTemplate<T>::push(T& t)
{
    sList.push_front(t);
}

template <typename T>
T& StackTemplate<T>::peek()
{
    return *sList.begin();
}

template <typename T>
T& StackTemplate<T>::pop()
{
    T& retVal = *sList.begin();
    sList.pop_front();
    return retVal;
}

void StackTemplate<string>::push(string t)
{
    sList.push_front(t);
}

string StackTemplate<string>::peek()
{
    return *sList.begin();
}

string StackTemplate<string>::pop()
{
    string retVal = *sList.begin();
    sList.pop_front();
    return retVal;
}





int LearnTemplates::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    string l_msg = p_msg + "TEMPLATES";
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\n" << l_msg << endl;
        cout << "Welcome to STL!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Function Templates" << endl;
        cout << "2. Class Templates" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {
                testTemplateFunction();
                break;
            }
        case '2':
            {
                testTemplateClass();
                break;
            }
        case '3':
            {
                break;
            }
        case '4':
            {
                break;
            }
        case '5':
            {
                break;
            }
        case '6':
            {
                break;
            }
        case 'b':
            l_retVal = 0;
            break;
        case 'q':
            l_retVal = 0;
            l_feedBack = 0;
            break;
        default:
            cout << "'" << l_data[0] << "' is an invalid choice.....try again" << endl;
            break;
        }

        cout << endl;
    }

    return l_feedBack;
}

