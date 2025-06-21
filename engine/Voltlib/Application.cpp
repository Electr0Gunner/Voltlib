#include "Application.hpp"
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
Application* Application::s_Instance = nullptr;

Application::Application()
{
    s_Instance = this;

    SDL_Init(SDL_INIT_VIDEO);
    
    appWidth = 1280;
    appHeight = 720;
    appTitle = "Voltlib";
    resourcePath = "assets";
    window = nullptr;
    renderer = nullptr;
    resourceRegistry = nullptr;

    shouldShutdown = false;

    debugMode = false;
}

Application::~Application()
{
    SDL_Quit();
}

void Application::Init()
{
    window = std::make_unique<Window>(appWidth, appHeight, appTitle);
    renderer = std::make_unique<Renderer>(window.get());
    Input::Init();
    sceneManager = std::make_unique<SceneManager>();
    imGuiManager = std::make_unique<ImGuiManager>();
    resourceRegistry = std::make_unique<ResourceRegistry>();
    resourceRegistry->LoadResources(resourcePath + "/Res.json");

    LOG_INFO("INITIATED ALL SYSTEMS");
}

void Application::Start()
{
    DoMainLoop();
}

void Application::DoMainLoop()
{
    Uint64 previousTime = SDL_GetTicks();

    while(!shouldShutdown)
    {
        Uint64 currentTime  = SDL_GetTicks();
        deltaTime = (currentTime - previousTime) / 1000.0; // seconds

        previousTime = currentTime;

        ParseEvents();
        Input::Update();
        sceneManager->Update();
        sceneManager->Draw();
        renderer->Render();
    }
}

void Application::ParseEvents()
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

        if (shouldShutdown)
            break;
    }
    
}

void Application::Shutdown()
{
    shouldShutdown = true;
}