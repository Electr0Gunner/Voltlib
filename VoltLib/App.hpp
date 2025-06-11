#pragma once

#include <memory>
#include <string>

namespace Volt
{
    class ResourceRegistry;
    class Renderer;
    class Window;
    class ImGuiManager;

    class App
    {
    public:
        std::string m_Title;

        std::unique_ptr<Renderer> m_Renderer;
        std::unique_ptr<ResourceRegistry> m_ResourceRegistry;
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<ImGuiManager> m_ImGuiManager;

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
}
