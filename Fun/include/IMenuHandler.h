#ifndef IMENUHANDLER_H
#define IMENUHANDLER_H

namespace fun { namespace common {

class IMenuHandler
{
    public:
        virtual void handleChoice(int choice) = 0;
};

}}

#endif // IMENUHANDLER_H
