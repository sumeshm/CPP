#ifndef SORTINGHANDLER_H
#define SORTINGHANDLER_H

#include <vector>
#include <string>
#include "Menu.h"
#include "IMenuHandler.h"

using namespace std;
using namespace fun::common;

namespace fun { namespace sorting {

class SortingHandler : public IMenuHandler
{
    public:
        SortingHandler(Menu& previous);
        virtual ~SortingHandler() {}

        virtual void handleChoice(int choice);

    protected:
        vector<string> m_options;
        Menu m_menu;
};

}}
#endif // SORTINGHANDLER_H
