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
    void processEvents();
    void renderUI();

    bool mIsRunning;

    SDL_Window* window;
    SDL_Renderer* renderer;

    NarrativeEngine engine;

    int selectedTheme;
    std::string storyText;
};

#endif
