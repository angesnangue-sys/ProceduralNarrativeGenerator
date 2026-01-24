#ifndef THEME_DATA_H
#define THEME_DATA_H

#include <vector>
#include <string>

struct ThemeData
{
    std::vector<std::string> names;
    std::vector<std::string> loctaions;
    std::vector<std::string> weapons;
    std::vector<std::string> events;
    std::vector<std::string> introTemplates;
    std::vector<std::string> eventTemplates;
    std::vector<std::string> conclusionTemplates;
};

#endif
