#ifndef NARRATIVEENGINE_H
#define NARRATIVEENGINE_H

#include <string>
#include "Theme.h"

//moteur narratif qui genere une histoire a partir d'un theme
class NarrativeEngine
{
public:
    std::string generateStory(Theme theme);
};

#endif
