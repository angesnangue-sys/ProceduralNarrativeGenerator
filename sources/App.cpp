#include "includes/App.h"


App::App()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Story Generator",
        800,
        600,
        SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(window, nullptr);
    running = true;

    // generation initiale
    StoryText = engine.generateStory(Theme::FEERIQUE);
}

App::~App()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::run()
{
    while (running)
    {
        handleEvents();
        render();
    }
}

void App::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
            running = false;
        
        if (event.type == SDL_EVENT_KEY_DOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                //Generer une nouvelle histoire
                StoryText = engine.generateStory(Theme::FEERIQUE);
            }
        }
    }
}

void App::render()
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);
    SDL_RenderDebugText(
        renderer,
        20,
        20,
        StoryText.c_str()
    );

    SDL_RenderPresent(renderer);
}