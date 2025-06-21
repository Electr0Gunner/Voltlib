#pragma once

namespace Volt
{
    class Entity;

    class Component
    {
    public:
        Entity* owner = nullptr;
        Component() {}
        ~Component() {}

        virtual void Init() {}
        virtual void Start() {}
        virtual void Update() {}
        virtual void Draw() {}
    };
} // namespace Volt
