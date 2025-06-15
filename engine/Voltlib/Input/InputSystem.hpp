#pragma once

#include <SDL3/SDL.h>
#include <bitset>
#include "Key.hpp"

namespace Volt
{
    class Input
    {
    private:
        static std::bitset<static_cast<size_t>(Key::KEY_COUNT)> CurrentlyPressedKeys;
        static std::bitset<static_cast<size_t>(Key::KEY_COUNT)> PreviouslyPressedKeys;
    public:
        static void Init();

        static void Update();

        static bool GetKey(Key key);
        static bool GetKeyDown(Key key);
        static bool GetKeyUp(Key key);

        static void OnEvent(const SDL_Event& event);
    };
} // namespace Volt
