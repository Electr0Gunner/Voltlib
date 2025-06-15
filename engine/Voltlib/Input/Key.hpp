#pragma once

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_keyboard.h>
#include <vector>

namespace Volt
{

    enum MouseButton
    {
        MouseLeft,
        MouseRight,
        MouseMiddle,
        MouseX1,
        MouseX2,
    };

    enum Key
    {
        UNKNOWN,
        A, B, C, D, E, F, G,
        H, I, J, K, L, M, N,
        O, P, Q, R, S, T, U,
        V, W, X, Y, Z,
        Num0, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,
        F1, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12,
        Keypad0, Keypad1, Keypad2, Keypad3, Keypad4,
        Keypad5, Keypad6, Keypad7, Keypad8, Keypad9,
        KeypadPlus, KeypadMinus, KeypadMultiply, KeypadDivide,
        KeypadPeriod, KeypadEqual,
        Up, Down, Left, Right,
        Plus, // +
        Minus, // -
        Equals, // =
        Asterisk, // *
        Slash, //  /
        Backslash, // "\"
        Colon, // :
        Semicolon, // ;
        Apostrophe, // "
        Comma, // ,
        Period, // .
        Space,
        Escape,
        Tab,
        Shift, //Left or right
        Control, //Left or right
        Alt, //Left and right
        Command, //Windows/Command key (Left and right)
        Enter, //Left and right
        CapsLock,
        Backspace,
        Delete,
        Insert,
        Home,
        End,
        PageUp,
        PageDown,
        PrintScreen,
        ScrollLock,
        Pause,
        NumLock,
        KEY_COUNT,
    };

    // Oh god this is horrible.
    
    static const std::vector<std::pair<SDL_Keycode, Volt::Key>> KeyPairs = {
    { SDLK_A, Volt::Key::A },
    { SDLK_B, Volt::Key::B },
    { SDLK_C, Volt::Key::C },
    { SDLK_D, Volt::Key::D },
    { SDLK_E, Volt::Key::E },
    { SDLK_F, Volt::Key::F },
    { SDLK_G, Volt::Key::G },
    { SDLK_H, Volt::Key::H },
    { SDLK_I, Volt::Key::I },
    { SDLK_J, Volt::Key::J },
    { SDLK_K, Volt::Key::K },
    { SDLK_L, Volt::Key::L },
    { SDLK_M, Volt::Key::M },
    { SDLK_N, Volt::Key::N },
    { SDLK_O, Volt::Key::O },
    { SDLK_P, Volt::Key::P },
    { SDLK_Q, Volt::Key::Q },
    { SDLK_R, Volt::Key::R },
    { SDLK_S, Volt::Key::S },
    { SDLK_T, Volt::Key::T },
    { SDLK_U, Volt::Key::U },
    { SDLK_V, Volt::Key::V },
    { SDLK_W, Volt::Key::W },
    { SDLK_X, Volt::Key::X },
    { SDLK_Y, Volt::Key::Y },
    { SDLK_Z, Volt::Key::Z },
    { SDLK_0, Volt::Key::Num0 },
    { SDLK_1, Volt::Key::Num1 },
    { SDLK_2, Volt::Key::Num2 },
    { SDLK_3, Volt::Key::Num3 },
    { SDLK_4, Volt::Key::Num4 },
    { SDLK_5, Volt::Key::Num5 },
    { SDLK_6, Volt::Key::Num6 },
    { SDLK_7, Volt::Key::Num7 },
    { SDLK_8, Volt::Key::Num8 },
    { SDLK_9, Volt::Key::Num9 },
    { SDLK_F1, Volt::Key::F1 },
    { SDLK_F2, Volt::Key::F2 },
    { SDLK_F3, Volt::Key::F3 },
    { SDLK_F4, Volt::Key::F4 },
    { SDLK_F5, Volt::Key::F5 },
    { SDLK_F6, Volt::Key::F6 },
    { SDLK_F7, Volt::Key::F7 },
    { SDLK_F8, Volt::Key::F8 },
    { SDLK_F9, Volt::Key::F9 },
    { SDLK_F10, Volt::Key::F10 },
    { SDLK_F11, Volt::Key::F11 },
    { SDLK_F12, Volt::Key::F12 },
    { SDLK_KP_0, Volt::Key::Keypad0 },
    { SDLK_KP_1, Volt::Key::Keypad1 },
    { SDLK_KP_2, Volt::Key::Keypad2 },
    { SDLK_KP_3, Volt::Key::Keypad3 },
    { SDLK_KP_4, Volt::Key::Keypad4 },
    { SDLK_KP_5, Volt::Key::Keypad5 },
    { SDLK_KP_6, Volt::Key::Keypad6 },
    { SDLK_KP_7, Volt::Key::Keypad7 },
    { SDLK_KP_8, Volt::Key::Keypad8 },
    { SDLK_KP_9, Volt::Key::Keypad9 },
    { SDLK_KP_PLUS, Volt::Key::KeypadPlus},
    { SDLK_KP_MINUS, Volt::Key::KeypadMinus},
    { SDLK_KP_MULTIPLY, Volt::Key::KeypadMultiply},
    { SDLK_KP_DIVIDE, Volt::Key::KeypadDivide},
    { SDLK_KP_PERIOD, Volt::Key::KeypadPeriod},
    { SDLK_KP_EQUALS, Volt::Key::KeypadEqual},
    { SDLK_UP, Volt::Key::Up},
    { SDLK_DOWN, Volt::Key::Down},
    { SDLK_LEFT, Volt::Key::Left},
    { SDLK_RIGHT, Volt::Key::Right},
    { SDLK_PLUS, Volt::Key::Plus},
    { SDLK_MINUS, Volt::Key::Minus},
    { SDLK_EQUALS, Volt::Key::Equals},
    { SDLK_ASTERISK, Volt::Key::Asterisk},
    { SDLK_SLASH, Volt::Key::Slash},
    { SDLK_BACKSLASH, Volt::Key::Backslash},
    { SDLK_COLON, Volt::Key::Colon},
    { SDLK_SEMICOLON, Volt::Key::Semicolon},
    { SDLK_PERIOD, Volt::Key::Period},
    { SDLK_SPACE, Volt::Key::Space},
    { SDLK_ESCAPE, Volt::Key::Escape},
    { SDLK_TAB, Volt::Key::Tab},
    { SDLK_LSHIFT, Volt::Key::Shift},
    { SDLK_RSHIFT, Volt::Key::Shift},
    { SDLK_LCTRL, Volt::Key::Control},
    { SDLK_RCTRL, Volt::Key::Control},
    { SDLK_LALT, Volt::Key::Alt},
    { SDLK_RALT, Volt::Key::Alt},
    { SDLK_LGUI, Volt::Key::Command},
    { SDLK_RGUI, Volt::Key::Command},
    { SDLK_RETURN, Volt::Key::Enter},
    { SDLK_RETURN2, Volt::Key::Enter},
    { SDLK_CAPSLOCK, Volt::Key::CapsLock},
    { SDLK_BACKSPACE, Volt::Key::Backspace},
    { SDLK_DELETE, Volt::Key::Delete},
    { SDLK_INSERT, Volt::Key::Insert},
    { SDLK_HOME, Volt::Key::Home},
    { SDLK_END, Volt::Key::End},
    { SDLK_PAGEUP, Volt::Key::PageUp},
    { SDLK_PAGEDOWN, Volt::Key::PageDown},
    { SDLK_PRINTSCREEN, Volt::Key::PrintScreen},
    { SDLK_SCROLLLOCK, Volt::Key::ScrollLock},
    { SDLK_PAUSE, Volt::Key::Pause},
    { SDLK_NUMLOCKCLEAR, Volt::Key::NumLock},
    };

    inline Key ToVoltKey(SDL_Keycode key)
    {
        for (const auto& pair : KeyPairs)
        {
            if (pair.first == key)
                return pair.second;
        }
        return Key::UNKNOWN;
    }

    inline SDL_Keycode ToSDLKeyCode(Key key)
    {
        for (const auto& pair : KeyPairs)
        {
            if (pair.second == key)
                return pair.first;
        }
        return SDLK_UNKNOWN;
    }

    inline const char* GetKeyName(Key key)
    {
        SDL_Keycode keycode = ToSDLKeyCode(key);
        return SDL_GetKeyName(keycode);
    }

} // namespace Volt
