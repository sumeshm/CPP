#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

#include "IMenuHandler.h"

using namespace std;

namespace fun { namespace common
{
    //typedef void (*menu_selection)(int);

    class Menu
    {
        public:
            Menu(string title, Menu* previous = NULL);
            virtual ~Menu();

            void printMenu(vector<string> menu_items, IMenuHandler* handler);

            string getTitle() { return m_title; }

        protected:
            void rePrintMenu();

        private:
            Menu* m_previous;
            vector<string>* m_menuItems;
            //menu_selection m_handler;
            string m_title;
            IMenuHandler* m_handler;
    };
}
}


#endif // MENU_H
