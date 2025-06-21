#pragma once

namespace Volt
{
    class Vec2
    {
    public:
        float x, y;
    public:
        Vec2(): x(0.0f), y(0.0f) {};
        Vec2(float x, float y): x(x), y(y) {};
        
        // NON SELF-MODIFYING
        Vec2 operator+(const Vec2& vec) const
        {
            return Vec2(x + vec.x, y + vec.y);
        }

        Vec2 operator-(const Vec2& vec) const
        {
            return Vec2(x - vec.x, y - vec.y);
        }

        Vec2 operator*(float t) const
        {
            return Vec2(x * t, y * t);
        }
        Vec2 operator/(float t) const
        {
            return Vec2(x / t, y / t);
        }

        Vec2 operator-() const
        {
            return Vec2(-x, -y);
        }

        // SELF-MODIFYING
        void operator+=(const Vec2 &vec)
        {
            x += vec.x;
            y += vec.y;
        }
        void operator-=(const Vec2 &vec)
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

        bool operator==(const Vec2 &v)
        {
            return x == v.x && y == v.y;
        }
        bool operator!=(const Vec2 &v)
        {
            return x != v.x || y != v.y;
        }

    };

    inline float Distance(const Vec2& a, const Vec2& b)
    {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        return sqrt((dx*dx) + (dy*dy));
    }

    //Returns non sqrt distance
    inline float DistanceCheap(const Vec2& a, const Vec2& b)
    {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        return (dx*dx) + (dy*dy);
    }
}