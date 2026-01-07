#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>


struct Character
{
    std::string name;
    std::vector<std::string> introduction;
    std::vector<std::string> actions;
    std::vector<std::string> obstacles;
    std::vector<std::string> conclusion;
};

#endif