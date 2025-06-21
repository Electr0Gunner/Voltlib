#pragma once

#include "Component.hpp"
#include "Math/Point.hpp"
#include "Math/Vector.hpp"
#include "Math/Rect.hpp"

namespace Volt
{
    class Transform : public Component
    {
    public:
        FPoint position;
        float rotation;
        Vec2 scale;
        FRect bounds;
        FRect rawBounds;

        Transform(float x = 0.0f, float y = 0.0f): position(x, y), rotation(0.0f), scale(1.0f, 1.0f), bounds(0,0,0,0) {};

        virtual void SetPosition(float x = 0.0f, float y = 0.0f)
        {
            position.x = x;
            position.y = y;
        }

        virtual void SetPosition(const FPoint& pos)
        {
            position = pos;
        }

        virtual void Offset(const FPoint& pos)
        {
            SetPosition(position + pos);
        }

        virtual void Offset(float x = 0.0f, float y = 0.0f)
        {
            SetPosition(position.x + x, position.y + y);
        }

        virtual void Rotate(float degrees)
        {
            rotation += degrees;
            rotation = rotation > 0.0f ? rotation <= 360.0f ? rotation : 360.0f : 0.0f;
        }

        virtual void SetBounds(const FRect& newBounds)
        {
            bounds = rawBounds = newBounds;
            bounds.width *= scale.x;
            bounds.height *= scale.y;
        }

        virtual void Scale(float factorX, float factorY)
        {
            scale += Vec2(factorX, factorY);

            SetBounds(rawBounds);
        }

        virtual void Scale(const Vec2& scaleFactor)
        {
            scale += scaleFactor;

            SetBounds(rawBounds);
        }
    };

} // namespace Volt
