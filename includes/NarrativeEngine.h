#ifndef NARRATIVE_ENGINE_H
#define NARRATIVE_ENGINE_H

#include <map>
#include <string>
#include "Theme.h"
#include "ThemeData.h"
#include "Character.h"
#include "Story.h"

class NarrativeEngine
{
public:
    NarrativeEngine();
    Story generateStory(Theme theme);

private:
    std::map<Theme, ThemeData> database;

    Character createCharacter(Theme theme);
    std::string applyTemplate(
        std::string tpl,
        const Character& c,
        const std::string& event
    );

    const std::string& randomFrom(const std::vector<std::string>& v);
};

#endif
