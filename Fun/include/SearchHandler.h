#ifndef SEARCHHANDLER_H
#define SEARCHHANDLER_H

#include <vector>
#include <string>
#include "Menu.h"
#include "IMenuHandler.h"

using namespace std;
using namespace fun::common;

namespace fun { namespace searching {

class SearchHandler : public IMenuHandler
{
    public:
        SearchHandler(Menu& previous);
        virtual ~SearchHandler() {}

        virtual void handleChoice(int choice);

    protected:
        vector<string> m_options;
        Menu m_menu;
};

}}

#endif // SEARCHHANDLER_H
