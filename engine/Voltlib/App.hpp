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

    class App
    {
    public:
        std::string m_Title;
        int m_Width;
        int m_Height;
        std::string m_ResourcePath;

        std::unique_ptr<Renderer> m_Renderer;
        std::unique_ptr<ResourceRegistry> m_ResourceRegistry;
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<ImGuiManager> m_ImGuiManager;
        std::unique_ptr<SceneManager> m_SceneManager;

        bool m_DebugMode;

        float m_DeltaTime;

    private:
        bool m_ShouldShutdown;

    private:
        void DoMainLoop();
        void ParseEvents();
    public:
        App(/* args */);
        ~App();

        void Init();
        void Start();
        void Shutdown();
    };

    extern App* g_App;
}
