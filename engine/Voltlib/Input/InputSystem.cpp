#include "InputSystem.hpp"
#include "Debug/Debug.hpp"

using namespace Volt;

std::bitset<static_cast<size_t>(Volt::Key::KEY_COUNT)> Volt::Input::CurrentlyPressedKeys;
std::bitset<static_cast<size_t>(Volt::Key::KEY_COUNT)> Volt::Input::PreviouslyPressedKeys;


void Input::Init()
{
    CurrentlyPressedKeys.reset();
    PreviouslyPressedKeys.reset();
}

void Input::Update()
{
    PreviouslyPressedKeys = CurrentlyPressedKeys;
}

bool Input::GetKey(Key key)
{
    return CurrentlyPressedKeys[static_cast<size_t>(key)];
}

bool Input::GetKeyDown(Key key)
{
    size_t i = static_cast<size_t>(key);
    return CurrentlyPressedKeys[i] && !PreviouslyPressedKeys[i];
}

bool Input::GetKeyUp(Key key)
{
    size_t i = static_cast<size_t>(key);
    return !CurrentlyPressedKeys[i] && PreviouslyPressedKeys[i];
}

void Input::OnEvent(const SDL_Event& event)
{
    if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP) {
        bool isDown = (event.type == SDL_EVENT_KEY_DOWN);
        
        Volt::Key key = ToVoltKey(event.key.key);
        CurrentlyPressedKeys[static_cast<size_t>(key)] = isDown;
    }
}
    