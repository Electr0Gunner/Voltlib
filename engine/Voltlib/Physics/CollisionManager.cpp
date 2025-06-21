#include "CollisionManager.hpp"
#include "Logic/Entity.hpp"

using namespace Volt;

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{
    
}

void CollisionManager::QueueCollision(ColliderInfo* a, ColliderInfo* b, CollisionEventType type)
{
    if (!a || !b || !a->valid || !b->valid)
        return;
    events.push_back({a, b, type});
}

void CollisionManager::Dispatch()
{
    for (const auto& event: events)
    {
        if (!event.a || !event.b || !event.a->valid || !event.b->valid)
            continue;

        if (event.a->owner)
            event.a->owner->OnCollision(event.b);
        if (event.b->owner)
            event.b->owner->OnCollision(event.a);
    }

    events.clear(); //We dispatched all collision events
}
