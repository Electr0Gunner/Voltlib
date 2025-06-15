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

void Renderer::Draw(RenderCommand command)
{
	SDL_SetRenderTarget(m_RenderBackend, m_RenderBuffer);

   // SDL_SetTextureColorMod( command.texture, command.color.r, command.color.g, command.color.b);
	//SDL_SetTextureAlphaMod( command.texture, command.color.a);
	//SDL_SetTextureBlendMode( command.texture, GetBlendMode(command.drawMode));

    //This is stupid. But since SDL doesnt have a entry for flipping both axes, we have to use this.
    double additionalRotation = 0.0;
    SDL_FRect srcRect = {command.src.x, command.src.y, command.src.width, command.src.height};
	SDL_FRect dstRect = {command.dst.x, command.dst.y, command.dst.width, command.dst.height};
    SDL_Rect clipRect = {command.clip.x, command.clip.y, command.clip.width, command.clip.height};
    SDL_FPoint centerPoint = {command.center.x, command.center.y};
    SDL_FlipMode flipMode = SDL_FLIP_NONE;
    if (command.flipMode == FLIP_VERTICAL)
        flipMode = SDL_FLIP_VERTICAL;
    else if (command.flipMode == FLIP_HORIZONTAL)
        flipMode = SDL_FLIP_HORIZONTAL;
    else if (command.flipMode == FLIP_BOTH)
    {
        flipMode = SDL_FLIP_NONE;
        additionalRotation = 180.0;
    }

    SDL_SetRenderClipRect(m_RenderBackend, &clipRect);
    SDL_RenderTextureRotated(m_RenderBackend, command.texture, &srcRect, &dstRect, command.rotation + additionalRotation, &centerPoint, flipMode);
    SDL_SetRenderClipRect(m_RenderBackend, nullptr);
	SDL_SetRenderTarget(m_RenderBackend, nullptr);
}

void Renderer::DrawLine(LineCommand command)
{
	SDL_SetRenderTarget(m_RenderBackend, m_RenderBuffer);

    SDL_BlendMode oldBlendMode;
    SDL_GetRenderDrawBlendMode(m_RenderBackend, &oldBlendMode);
	SDL_SetRenderDrawBlendMode(m_RenderBackend, GetBlendMode(command.drawMode));
    SDL_SetRenderDrawColor(m_RenderBackend, command.color.r, command.color.g, command.color.b, command.color.a);
    SDL_RenderLine(m_RenderBackend, command.startPos.x, command.startPos.y, command.endPos.x, command.endPos.y);
	SDL_SetRenderDrawBlendMode(m_RenderBackend, oldBlendMode);
	SDL_SetRenderTarget(m_RenderBackend, nullptr);
}

void Renderer::DrawRect(RectCommand command)
{
	SDL_SetRenderTarget(m_RenderBackend, m_RenderBuffer);

    SDL_FRect rect = {command.rect.x, command.rect.y, command.rect.width, command.rect.height};

    SDL_BlendMode oldBlendMode;
    SDL_GetRenderDrawBlendMode(m_RenderBackend, &oldBlendMode);
	SDL_SetRenderDrawBlendMode(m_RenderBackend, GetBlendMode(command.drawMode));
    SDL_SetRenderDrawColor(m_RenderBackend, command.color.r, command.color.g, command.color.b, command.color.a);
    if (command.fillIn)
        SDL_RenderFillRect(m_RenderBackend, &rect);
    else
        SDL_RenderRect(m_RenderBackend, &rect);
	SDL_SetRenderDrawBlendMode(m_RenderBackend, oldBlendMode);
	SDL_SetRenderTarget(m_RenderBackend, nullptr);
}