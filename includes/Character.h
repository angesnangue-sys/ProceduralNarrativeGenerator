#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Theme.h"


struct Character
{
    std::string name;
    std::string location;
    std::string weapon;
    Theme theme;
};

#endif