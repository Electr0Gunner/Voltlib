#include "App.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Backend/ResourceRegistry.hpp"
#include "Input/InputSystem.hpp"
#include "Logic/SceneManager.hpp"
#include "imgui/ImGuiManager.hpp"
#include <SDL3/SDL.h>
#include "Rendering/RenderFrontend.hpp"
#include "Debug/Debug.hpp"

using namespace Volt;
App* Volt::g_App = nullptr;


App::App()
{
    g_App = this;

    SDL_Init(SDL_INIT_VIDEO);
    
    m_Width = 1280;
    m_Height = 720;
    m_Title = "Voltlib";
    m_ResourcePath = "assets";
    m_Window = nullptr;
    m_Renderer = nullptr;
    m_ResourceRegistry = nullptr;

    m_ShouldShutdown = false;

    m_DebugMode = false;
}

App::~App()
{
    SDL_Quit();
}

void App::Init()
{
    m_Window = std::make_unique<Window>(m_Width, m_Height, m_Title);
    m_Renderer = std::make_unique<Renderer>(m_Window.get());
    Input::Init();
    m_ResourceRegistry = std::make_unique<ResourceRegistry>();
    m_ResourceRegistry->LoadResources(m_ResourcePath + "/Res.json");
    m_SceneManager = std::make_unique<SceneManager>();

    m_ImGuiManager = std::make_unique<ImGuiManager>();

    LOG_INFO("INITIATED ALL SYSTEMS");
}

void App::Start()
{
    DoMainLoop();
}

void App::DoMainLoop()
{
    Uint64 previousTime = SDL_GetTicks();

    while(!m_ShouldShutdown)
    {
        Uint64 currentTime  = SDL_GetTicks();
        m_DeltaTime = (currentTime - previousTime) / 1000.0; // seconds

        previousTime = currentTime;

        ParseEvents();
        Input::Update();
        m_SceneManager->Update();
        m_SceneManager->Draw();
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
        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_KEY_UP:
            Input::OnEvent(event);
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