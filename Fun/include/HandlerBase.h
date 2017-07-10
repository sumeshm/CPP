#ifndef HandlerBase_H
#define HandlerBase_H

#include <vector>
#include <string>
#include "Menu.h"
#include "IMenuHandler.h"

using namespace std;
using namespace fun::common;

namespace fun { namespace common {

class HandlerBase : public IMenuHandler
{
    public:
        HandlerBase() : m_menu("Empty Menu") {}
        virtual ~HandlerBase() {}

        virtual void handleChoice(int choice) {}

    protected:
        vector<string> m_options;
        Menu m_menu;
};

}}
#endif // SORTINGHANDLER_H
