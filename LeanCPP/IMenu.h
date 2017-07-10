#ifndef IMENU_H_INCLUDED
#define IMENU_H_INCLUDED

#include <string>

class IMenu
{
    public:
        virtual ~IMenu() {}

        virtual int printOptions(std::string p_msg) = 0;
};

#endif // IMENU_H_INCLUDED
