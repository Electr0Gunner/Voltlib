#include "ImGuiManager.hpp"
#include "Rendering/Renderer.hpp"

using namespace Volt;

ImGuiManager* Volt::g_ImGuiManager = nullptr;

bool demoWind = true;

static std::vector<ImGuiWindowEntry> windowList;

void RegisterImGuiWindow(const char *name, bool *enabled, const ImGuiManager::WindowFunction &func)
{
	windowList.push_back({name, enabled, func});
}

void RegisterImGuiWindows()
{
	for (auto &entry : windowList)
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

	ImGui_ImplSDL3_InitForSDLRenderer(Renderer::Instance()->GetWindow(), Renderer::Instance()->GetRenderer());
	ImGui_ImplSDLRenderer3_Init(Renderer::Instance()->GetRenderer());
}

ImGuiManager::~ImGuiManager()
{
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiManager::RenderAll(void)
{
	for (const auto &entry : windowList)
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
