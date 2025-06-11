#include "Renderer.hpp"
#include "Window.hpp"
#include "imgui/ImGuiManager.hpp"

using namespace Volt;

Renderer* Volt::g_Renderer = nullptr;

Renderer::Renderer(Window* window)
{
    g_Renderer = this;

    m_RenderBackend = window->m_Renderer;
    m_WindowBackend = window->m_Window;

    int w,h;
    SDL_GetWindowSize(m_WindowBackend, &w, &h);
    m_RenderBuffer = SDL_CreateTexture(m_RenderBackend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
	SDL_SetTextureBlendMode(m_RenderBuffer, SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
    SDL_DestroyTexture(m_RenderBuffer);
}

void Renderer::Draw(RenderBatch batch)
{
	SDL_SetRenderTarget(m_RenderBackend, m_RenderBuffer);

    SDL_FRect srcF = {batch.src.x, batch.src.y, batch.src.width, batch.src.height};
	SDL_FRect dstF = {batch.pos.x, batch.pos.y, batch.src.width, batch.src.height};

    SDL_RenderTexture(m_RenderBackend, batch.texture, &srcF, &dstF);
	SDL_SetRenderTarget(m_RenderBackend, nullptr);
}

void Renderer::Render()
{
	g_ImGuiManager->Frame();

	SDL_SetRenderTarget(m_RenderBackend, nullptr);

	SDL_SetRenderDrawColor(m_RenderBackend, 0, 0, 0, 255);
	SDL_RenderClear(m_RenderBackend);
    SDL_RenderTexture(m_RenderBackend, m_RenderBuffer, nullptr, nullptr);

    if (ImGui::GetDrawData() != nullptr)
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_RenderBackend);

    SDL_RenderPresent(m_RenderBackend);
}

SDL_Renderer* Renderer::GetRenderer()
{
    return m_RenderBackend;
}

SDL_Window* Renderer::GetWindow()
{
    return m_WindowBackend;
}
