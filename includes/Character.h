#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

// represente un personnage de l'histoire
struct Character
{
    std::string name;//son nom
    std::string location;//le lieu principal de l'histoire
    std::string weapon;//son arme
    Theme theme;//le theme dans lequel il se trouve
};

#endif