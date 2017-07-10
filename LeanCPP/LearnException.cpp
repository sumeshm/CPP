#include "LearnException.h"

LearnException::LearnException()
{
    exception e1;
    MyException e2;

    try
    {
        throw e1;
    }
    catch(...)
    {
        cout << "Caught exception:" << endl;
    }


    try
    {
        throw e2;
    }
    catch(MyException& e)
    {
        cout << "Caught MyException: " << e.what() << endl;
    }
    catch(exception& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}

LearnException::~LearnException()
{
    //dtor
}

int LearnException::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    string l_msg = p_msg + "EXCEPTIONS";
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\n" << l_msg << endl;
        cout << "nWelcome to Exception!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Throw-Catch" << endl;

        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {

                break;
            }
        case '2':
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
