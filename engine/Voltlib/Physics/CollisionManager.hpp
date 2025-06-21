#pragma once

#include <chipmunk/chipmunk.h>
#include <vector>
#include <string>

namespace Volt
{
    class Entity;

    enum CollisionEventType
    {
        EVENT_ENTER,
        EVENT_EXIT,
    };

    struct ColliderInfo
    {
        Volt::Entity* owner = nullptr;     // Optional
        std::string tag;                   // Optional
        cpShape* shape = nullptr;
        bool valid = false;
    };

    struct CollisionEvent
    {
        ColliderInfo* a;
        ColliderInfo* b;
        CollisionEventType type;
        bool isValid;
    };

    class CollisionManager
    {
    private:
        std::vector<CollisionEvent> events;
    public:
        void QueueCollision(ColliderInfo* a, ColliderInfo* b, CollisionEventType type);
        void Dispatch();
        CollisionManager(/* args */);
        ~CollisionManager();
    };

    
} // namespace Volt
