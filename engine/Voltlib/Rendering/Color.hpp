#pragma once

#include <cstdint>

namespace Volt
{
    struct Color {
        int r, g, b, a;

        Color() : r(0), g(0), b(0), a(1) {}
        Color(int red, int green, int blue, int alpha = 255) : r(red), g(green), b(blue), a(alpha) {}

        Color(int color) : a((color >> 24) & 0xFF), r((color >> 16) & 0xFF), g((color >> 8) & 0xFF), b(color & 0xFF) {}
    
        int operator[](int theIdx) const
        {

            switch (theIdx)
            {
            case 0:
                return r;
            case 1:
                return g;
            case 2:
                return b;
            case 3:
                return a;
            default:
                return -1;
            }
        }

        uint64_t ToInt() const
        {
            return (a << 24) | (r << 16) | (g << 8) | (b);
        }

        bool operator==(const Color& color)
        {
            return (r == color.r) && (g == color.g) && (b == color.b)  && (a == color.a);
        }

        bool operator!=(const Color& color)
        {
            return (r != r) || (g != color.g) || (b != color.b)  || (a != color.a);
        }

    };
} // namespace Volt
