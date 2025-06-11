#include "App.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Backend/ResourceRegistry.hpp"
#include "imgui/ImGuiManager.hpp"
#include <SDL3/SDL.h>

using namespace Volt;

App::App()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    m_Title = "Voltlib";
    m_Window = nullptr;
    m_Renderer = nullptr;
    m_ResourceRegistry = nullptr;

    m_ShouldShutdown = false;
}

App::~App()
{
    SDL_Quit();
}

void App::Init()
{
    m_Window = std::make_unique<Window>(1280, 720, m_Title);
    m_Renderer = std::make_unique<Renderer>(m_Window.get());
    m_ResourceRegistry = std::make_unique<ResourceRegistry>();
    m_ImGuiManager = std::make_unique<ImGuiManager>();
}

void App::Start()
{
    DoMainLoop();
}

void App::DoMainLoop()
{
    while(!m_ShouldShutdown)
    {
        ParseEvents();

        m_Renderer->Render();
    }
}

void App::ParseEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL3_ProcessEvent(&event);

        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            Shutdown();
            break;
        
        default:
            break;
        }
    }
    
}

void App::Shutdown()
{
    m_ShouldShutdown = true;
}