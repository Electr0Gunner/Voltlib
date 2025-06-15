#pragma once

namespace Volt
{
    template <class _T> class TypePoint
    {
        public:
            _T x;
            _T y;
        public:
            TypePoint(_T x, _T y): x(x), y(y) {}
            TypePoint(const TypePoint<_T>& point): x(point.x), y(point.y) {}
            TypePoint() : x(0), y(0) {}

            // NON SELF-MODIFYING
            TypePoint operator+(const TypePoint& vec) const
            {
                return TypePoint(x + vec.x, y + vec.y);
            }

            TypePoint operator-(const TypePoint& vec) const
            {
                return TypePoint(x - vec.x, y - vec.y);
            }

            TypePoint operator*(float t) const
            {
                return TypePoint(x * t, y * t);
            }
            TypePoint operator/(float t) const
            {
                return TypePoint(x / t, y / t);
            }

            TypePoint operator-() const
            {
                return TypePoint(-x, -y);
            }

            // SELF-MODIFYING
            void operator+=(const TypePoint &vec)
            {
                x += vec.x;
                y += vec.y;
            }
            void operator-=(const TypePoint &vec)
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

            bool operator==(const TypePoint &v)
            {
                return x == v.x && y == v.y;
            }
            bool operator!=(const TypePoint &v)
            {
                return x != v.x || y != v.y;
            }

            void Offset(_T x_offset, _T y_offset)
            {
                x += x_offset;
                y += y_offset;
            }

    };

typedef TypePoint<int> Point;
typedef TypePoint<float> FPoint;

}