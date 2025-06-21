#pragma once

#include <vector>
#include <memory>
#include <chipmunk/chipmunk.h>

namespace Volt
{
    class Entity;
    class CollisionManager;

    class PhysicsSystem
    {
    private:
        static cpBool BeginCallback(cpArbiter* arb, cpSpace* space, void* userData);
    public:
        cpSpace* space = nullptr;
        std::unique_ptr<CollisionManager> collisionManager = nullptr;

        PhysicsSystem();
        ~PhysicsSystem();

        virtual void Update(const std::vector<std::unique_ptr<Entity>>& entities);
        virtual void DebugDraw();

        static cpBool OnBeginCollision(cpArbiter* arb, cpSpace* space, void* userData);
        static void OnEndCollision(cpArbiter* arb, cpSpace* space, void* userData);

    };
} // namespace Volt
