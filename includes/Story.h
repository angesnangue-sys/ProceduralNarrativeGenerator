#ifndef STORY_H
#define STORY_H

#include <vector>
#include <string>

struct Story
{
    std::vector<std::string> paragraphs;

    std::string toString() const;
};

#endif
