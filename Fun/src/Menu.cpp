#include "Menu.h"

using namespace std;
using namespace fun::common;

namespace fun { namespace common {

Menu::Menu(string title, Menu* previous) : m_menuItems(NULL), m_title(title), m_previous(previous)
{
}

Menu::~Menu()
{
    if (m_menuItems != NULL)
    {
        delete m_menuItems;
    }
}

void Menu::printMenu(vector<string> menu_items, IMenuHandler* handler)
{
    m_handler = handler;
    m_menuItems = new vector<string>(menu_items);

    char choise;
    while (true)
    {
        string currentTitle;
        if (m_previous != NULL && m_previous->getTitle().length() > 0)
        {
            currentTitle.append(m_previous->getTitle());
            currentTitle.append(" <> ");
        }
        currentTitle.append(m_title);

        int index = 0;
        cout << "\n\n----------------------------------------------------- " << endl;
        cout << " " << currentTitle << endl;
        cout << "----------------------------------------------------- " << endl;

        for (string item : menu_items)
        {
            cout << " " << index << " - " << item << endl;
            index++;
        }
        cout << endl;
        cout << " b - go back" << endl;
        cout << endl;
        cout << " Choose an option from above" << endl;
        cout << "----------------------------------------------------- \n\n" << endl;

        cin >> choise;
        if (choise == 'b')
        {
            if (m_previous != NULL)
            {
                //cout << "reprint" << endl;
                m_previous->rePrintMenu();
            }
            else
            {
                // quit
                //cout << "pass on BACK to handler" << endl;
                m_handler->handleChoice(-1);
            }

            break;
        }

        if (choise < '0' || choise > '9')
        {
            cout << "XXXX Wrong choice, please re-try" << endl;
            continue;
        }
        else
        {
            // notify caller
            m_handler->handleChoice(choise - '0');
        }
    }
}

void Menu::rePrintMenu()
{
    if (!m_menuItems->empty())
    {
        printMenu(*m_menuItems, m_handler);
    }
}


}}
