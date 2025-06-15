#pragma once

namespace Volt
{
    class Vector2
    {
    public:
        float x, y;
    public:
        Vector2(float x, float y): x(x), y(y) {};
        
        // NON SELF-MODIFYING
        Vector2 operator+(const Vector2& vec) const
        {
            return Vector2(x + vec.x, y + vec.y);
        }

        Vector2 operator-(const Vector2& vec) const
        {
            return Vector2(x - vec.x, y - vec.y);
        }

        Vector2 operator*(float t) const
        {
            return Vector2(x * t, y * t);
        }
        Vector2 operator/(float t) const
        {
            return Vector2(x / t, y / t);
        }

        Vector2 operator-() const
        {
            return Vector2(-x, -y);
        }

        // SELF-MODIFYING
        void operator+=(const Vector2 &vec)
        {
            x += vec.x;
            y += vec.y;
        }
        void operator-=(const Vector2 &vec)
        {
            x -= vec.x;
            y -= vec.y;
        }
        void operator*=(float t)
        {
            x *= t;
            y *= t;
        }
        void operator/=(float t)
        {
            x /= t;
            y /= t;
        }

        bool operator==(const Vector2 &v)
        {
            return x == v.x && y == v.y;
        }
        bool operator!=(const Vector2 &v)
        {
            return x != v.x || y != v.y;
        }

    };
}