#pragma once

#include <memory>
#include <string>

namespace Volt
{
    class ResourceRegistry;
    class Renderer;
    class Window;
    class ImGuiManager;
    class SceneManager;

    class Application
    {
    public:
        std::string appTitle;
        int appWidth;
        int appHeight;
        std::string resourcePath;

        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<ResourceRegistry> resourceRegistry;
        std::unique_ptr<Window> window;
        std::unique_ptr<ImGuiManager> imGuiManager;
        std::unique_ptr<SceneManager> sceneManager;

        bool debugMode;

        float deltaTime;

    private:
        bool shouldShutdown;

    private:
        void DoMainLoop();
        void ParseEvents();
    public:
        Application(/* args */);
        ~Application();

        void Init();
        void Start();
        void Shutdown();

        static inline Application* Instance()
        {
            return s_Instance;
        }

        static Application* s_Instance;
    };
}
