#ifndef APP_H
#define APP_H

#include <SDL3/SDL.h>
#include <string>
#include "NarrativeEngine.h"

class App
{
public:
    App();
    ~App();
    void Run();

private:
    void handleEvents();
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    NarrativeEngine engine;
    std::string StoryText;
};

#endif
