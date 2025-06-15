#include "ImGuiManager.hpp"
#include "Rendering/Renderer.hpp"

using namespace Volt;

ImGuiManager* Volt::g_ImGuiManager = nullptr;

bool demoWind = true;

static std::vector<ImGuiWindowEntry> g_WindowList;

void RegisterImGuiWindow(const char *name, bool *enabled, const ImGuiManager::WindowFunction &func)
{
	g_WindowList.push_back({name, enabled, func});
}

void RegisterImGuiWindows()
{
	for (auto &entry : g_WindowList)
	{
		if (entry.enabled && *entry.enabled)
		{
			g_ImGuiManager->AddWindow(entry.func);
		}
	}
}

ImGuiManager::ImGuiManager()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplSDL3_InitForSDLRenderer(g_Renderer->GetWindow(), g_Renderer->GetRenderer());
	ImGui_ImplSDLRenderer3_Init(g_Renderer->GetRenderer());
}

ImGuiManager::~ImGuiManager()
{
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiManager::RenderAll(void)
{
	for (const auto &entry : g_WindowList)
	{
		if (entry.enabled && *entry.enabled)
			entry.func();
	}
}

void ImGuiManager::Frame(void)
{
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

	if (demoWind)
		ImGui::ShowDemoWindow();

	RenderAll();

	ImGui::Render();
}
