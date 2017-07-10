#include <iostream>
#include "SortingHandler.h"

namespace fun { namespace sorting {

SortingHandler::SortingHandler(Menu& previous) : m_menu("Sorting Menu", &previous)
{
    m_options.push_back("Heap");
    m_options.push_back("Bubble");
    m_options.push_back("Quick");
    m_options.push_back("Binary");

    m_menu.printMenu(m_options, this);
}

void SortingHandler::handleChoice(int choice)
{
    //0cout << "SortingHandler::handleChoice = " << choice << endl;

    switch (choice)
    {
    case 0:
        {
            cout << "\t-->" << m_options.at(choice) << endl;
            break;
        }
    case 1:
        {
            cout << "\t-->" << m_options.at(choice) << endl;
            break;
        }
    default:
        {
            cout << "XXXX Wrong choice, please re-try" << endl;
            break;
        }
    }
}

}}
