#ifndef STORY_GENERATOR_H
#define STORY_GENERATOR_H

#include <string>
#include <vector>
#include "Character.h"
#include <map>



class StoryGenerator
{
public:
    StoryGenerator();
    std::string Generateparagraph();

private:
    std::vector<Character> personnages;

    template<typename T>
    const T& pickRandom(const std::vector<T>& list) const ;

    void saveToFile(const std::string& text);
    void loadDefaultCharacter();
};

#endif
