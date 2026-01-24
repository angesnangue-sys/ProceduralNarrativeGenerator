#include "Story.h"

std::string Story::toString() const {
    std::string result;
    for (const auto& p : paragraphs) {
        result += p + "\n";
    }
    return result;
}