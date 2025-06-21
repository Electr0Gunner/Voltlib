#include "Renderer.hpp"
#include "Window.hpp"
#include "imgui/ImGuiManager.hpp"

using namespace Volt;

Renderer* Renderer::s_Instance = nullptr;

Renderer::Renderer(Window* window)
{
    s_Instance = this;

    rendererBackend = window->renderer;
    windowBackend = window->window;

    int w,h;
    SDL_GetWindowSize(windowBackend, &w, &h);
    renderBuffer = SDL_CreateTexture(rendererBackend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
	SDL_SetTextureBlendMode(renderBuffer, SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
    SDL_DestroyTexture(renderBuffer);
}


void Renderer::Render()
{
	g_ImGuiManager->Frame();

	SDL_SetRenderTarget(rendererBackend, nullptr);

	SDL_SetRenderDrawColor(rendererBackend, 0, 0, 0, 255);
	SDL_RenderClear(rendererBackend);
    SDL_RenderTexture(rendererBackend, renderBuffer, nullptr, nullptr);

    if (ImGui::GetDrawData() != nullptr)
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), rendererBackend);

    SDL_RenderPresent(rendererBackend);
}

SDL_Renderer* Renderer::GetRenderer()
{
    return rendererBackend;
}

SDL_Window* Renderer::GetWindow()
{
    return windowBackend;
}

void Renderer::Draw(RenderCommand command)
{
	SDL_SetRenderTarget(rendererBackend, renderBuffer);

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

    SDL_SetRenderClipRect(rendererBackend, &clipRect);
    SDL_RenderTextureRotated(rendererBackend, command.texture, &srcRect, &dstRect, command.rotation + additionalRotation, &centerPoint, flipMode);
    SDL_SetRenderClipRect(rendererBackend, nullptr);
	SDL_SetRenderTarget(rendererBackend, nullptr);
}

void Renderer::DrawLine(LineCommand command)
{
	SDL_SetRenderTarget(rendererBackend, renderBuffer);

    SDL_BlendMode oldBlendMode;
    SDL_GetRenderDrawBlendMode(rendererBackend, &oldBlendMode);
	SDL_SetRenderDrawBlendMode(rendererBackend, GetBlendMode(command.drawMode));
    SDL_SetRenderDrawColor(rendererBackend, command.color.r, command.color.g, command.color.b, command.color.a);
    SDL_RenderLine(rendererBackend, command.startPos.x, command.startPos.y, command.endPos.x, command.endPos.y);
	SDL_SetRenderDrawBlendMode(rendererBackend, oldBlendMode);
	SDL_SetRenderTarget(rendererBackend, nullptr);
}

void Renderer::DrawRect(RectCommand command)
{
	SDL_SetRenderTarget(rendererBackend, renderBuffer);

    SDL_FRect rect = {command.rect.x, command.rect.y, command.rect.width, command.rect.height};

    SDL_BlendMode oldBlendMode;
    SDL_GetRenderDrawBlendMode(rendererBackend, &oldBlendMode);
	SDL_SetRenderDrawBlendMode(rendererBackend, GetBlendMode(command.drawMode));
    SDL_SetRenderDrawColor(rendererBackend, command.color.r, command.color.g, command.color.b, command.color.a);
    if (command.fillIn)
        SDL_RenderFillRect(rendererBackend, &rect);
    else
        SDL_RenderRect(rendererBackend, &rect);
	SDL_SetRenderDrawBlendMode(rendererBackend, oldBlendMode);
	SDL_SetRenderTarget(rendererBackend, nullptr);
}