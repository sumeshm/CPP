#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "IMenuHandler.h"
#include "SortingHandler.h"
#include "SearchHandler.h"

using namespace std;
using namespace fun::common;
using namespace fun::sorting;
using namespace fun::searching;

class MainMenu : public IMenuHandler
{
public:
    MainMenu() : menu("Main Menu")
    {
        vector<string> options;
        options.push_back("Sorting");
        options.push_back("Searching");

        menu.printMenu(options, this);
    }

    void handleChoice(int choice)
    {
        //cout << "MainMenu::handleChoice = " << choice << endl;

        switch (choice)
        {
        case 0:
            {
                SortingHandler sortHandler(menu);
                break;
            }
        case 1:
            {
                SearchHandler searchHandler(menu);
                break;
            }
        default:
            {
                cout << "...... Bye Bye!" << endl;
                exit(0);
            }
        }
    }

private:
    Menu menu;
};

int main(int arg, char** argv)
{
    cout << "Welcome to FUN" << endl;
    MainMenu mainMenu;
}
