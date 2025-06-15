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
        FPoint m_Position;
        float m_Rotation;
        Vector2 m_Scale;

        Transform(float x = 0.0f, float y = 0.0f): m_Position(x, y), m_Rotation(0.0f), m_Scale(1.0f, 1.0f) {};
    };

} // namespace Volt
