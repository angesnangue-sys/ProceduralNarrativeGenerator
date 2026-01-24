#include "includes/App.h"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>



App::App()
    : IsRunning(true), window(nullptr), renderer(nullptr), selectedTheme(0){
        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow(
            "Procedural Narrative Generator",
            800, 600,
            SDL_WINDOW_RESIZABLE
        );

        renderer = SDL_CreateRenderer(window, nullptr);
        
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer3_Init(renderer);
    }

App::~App(){
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::run(){
    while (isRunning)
    {
        processEvents();

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        renderUI();

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);

        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }
}

void App::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);
        if (event.type == SDL_EVENT_QUIT){
            IsRunning = false;
        }
    }
}

void App::renderUI(){
    ImGui::Begin("Generateur d'histoires");

    const char* themes[] = {
        "Feerrique",
        "Medieval",
        "Vampire"
    };

    ImGui::Combo("Theme", &selectedTheme, themes, 3);

    if (ImGui::Button("Generer l'histoire")) {
        Theme theme = static_cast<Theme>(selectedTheme);
        Story story = engine.generateStory(theme);
        storyText = story.toString();
    }

    ImGui::Separator();

    ImGui::InputTextMultiline(
        "Histoire",
        storyText.data(),
        storyText.capacity() + 1,
        imvec2(-1, 300),
        ImGuiInputTextFlags_ReadOnly
    );

    ImGui::End();
}
