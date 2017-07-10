#include "SearchHandler.h"

namespace fun { namespace searching {


SearchHandler::SearchHandler(Menu& previous) : m_menu("Searching Menu", &previous)
{
    m_options.push_back("Binary");
    m_options.push_back("Linear");

    m_menu.printMenu(m_options, this);
}

void SearchHandler::handleChoice(int choice)
{
    //cout << "SearchHandler::handleChoice = " << choice << endl;

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
