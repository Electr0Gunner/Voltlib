#pragma once

#include "Math/Rect.hpp"

namespace Volt
{
    class Camera
    {
    private:
        FRect m_ViewPort;
    public:
        Camera(/* args */);
        ~Camera();
    };
    
    Camera::Camera(/* args */)
    {
    }
    
    Camera::~Camera()
    {
    }
    
} // namespace Volt
