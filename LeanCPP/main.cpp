#include "LinkedList.h"
#include "BTree.h"
#include "LearnThreads.h"
#include "CppEleven.h"
#include "SortAlgos.h"
#include "ProblemSolving.h"
#include "LearnCpp.h"
#include "interval_map.h"
#include "PayPal.h"

#include <iostream>

using namespace std;

int printOptions();


const string msg = "MAIN <> ";


int main(int argLen, char** dataArr)
{
    cout << "Hello world!" << endl;
    // PayPal payPal;
    // payPal.paypal();
    printOptions();

    return 0;
}

int printOptions()
{
    int l_retVal = 1;
    char l_data[20] = "";

    while (l_retVal)
    {
        cout << "Menu:" << endl;
        cout << "---------------------------------" << endl;
        cout << "0. Problem Solving" << endl;
        cout << "1. Test B-Tree" << endl;
        cout << "2. CPP (STL, Templates, Exceptions, Inheritance)" << endl;
        cout << "3. " << endl;
        cout << "4. Test Linked List" << endl;
        cout << "5. Test Threads" << endl;
        cout << "6. C++ 11" << endl;
        cout << "7. " << endl;
        cout << "8. Sorting" << endl;
        cout << "9. " << endl;
        cout << "\nq. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;

        switch (l_data[0])
        {
        case '0':
            {
                ProblemSolving l_problemSolving;
                l_retVal = l_problemSolving.printOptions(msg);
                break;
            }
        case '1':
            {
                BTree l_binaryTree;
                l_retVal = l_binaryTree.printOptions(msg);
                break;
            }
        case '2':
            {
                LearnCpp l_learnCpp;
                l_retVal = l_learnCpp.printOptions(msg);
            }
            break;
        case '3':
            {
                break;
            }
        case '4':
            {
                LinkedList l_list;
                l_retVal = l_list.printOptions(msg);
                break;
            }
        case '5':
            {
                LearnThreads learnThreads;
                l_retVal = learnThreads.printOptions(msg);
                break;
            }
        case '6':
            {
                CppEleven l_cppEleven;
                l_retVal = l_cppEleven.printOptions(msg);
                break;
            }
        case '7':
            {
                break;
            }
        case '8':
            {
                SortAlgos l_sortAlgos;
                l_retVal = l_sortAlgos.printOptions(msg);
                break;
            }
        case '9':
            {
                break;
            }
        case 'q':
            l_retVal = 0;
           break;
        default:
            cout << "'" << l_data[0] << "' is an invalid choice.....try again" << endl;
            break;
        }

        cout << endl;
    }

    return 1;
}

