#pragma once

#include "core/imgui.h"
#include "core/imgui_impl_sdl3.h"
#include "core/imgui_impl_sdlrenderer3.h"

#include <vector>
#include <functional>

namespace Volt
{
    class ImGuiManager
    {
    public:
        using WindowFunction = std::function<void()>;
    private:
        std::vector<WindowFunction> windowFuncs;
    public:
        ImGuiManager();

        ~ImGuiManager();

        void RenderAll(void);

        void Frame(void);

        inline void AddWindow(const WindowFunction &func)
        {
            windowFuncs.push_back(func);
        }
    };

    extern ImGuiManager* g_ImGuiManager;
}

struct ImGuiWindowEntry
{
	const char *name;

	bool *enabled;

	Volt::ImGuiManager::WindowFunction func;
};

void RegisterImGuiWindow(const char *name, bool *enabled, const Volt::ImGuiManager::WindowFunction &func);

void RegisterImGuiWindows();
