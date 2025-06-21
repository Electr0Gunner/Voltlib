#include "PhysicsSystem.hpp"
#include "Application.hpp"
#include "Logic/Entity.hpp"
#include "Logic/Components/Transform.hpp"
#include "Logic/Components/Rigidbody.hpp"
#include "CollisionManager.hpp"

using namespace Volt;

PhysicsSystem::PhysicsSystem()
{
    space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(0, 9.8f));

    cpCollisionHandler* handler = cpSpaceAddDefaultCollisionHandler(space);
    handler->userData = this;
    handler->beginFunc = PhysicsSystem::OnBeginCollision;
    handler->separateFunc = PhysicsSystem::OnEndCollision;

    collisionManager = std::make_unique<CollisionManager>();
}

PhysicsSystem::~PhysicsSystem()
{
    cpSpaceFree(space);
}

void PhysicsSystem::Update(const std::vector<std::unique_ptr<Entity>>& entities)
{
    cpSpaceStep(space, Application::Instance()->deltaTime);
    collisionManager->Dispatch();

    for (auto& ptr : entities) {
        Entity* entity = ptr.get();
        auto body = entity->GetComponent<RigidBody>();
        if ( !body || !body->GetCollider()) continue;

        Collider* physicsCollider = body->GetCollider();
        
        if (body->dirtyValues & VALUE_ROTATION)
        {
            cpBodySetAngle(physicsCollider->GetBody(), body->rotation);
            body->dirtyValues &= ~VALUE_ROTATION;
        }

        if (body->dirtyValues & VALUE_POS)
        {
            cpBodySetPosition(physicsCollider->GetBody(), cpv(body->position.x, body->position.y));
            body->dirtyValues &= ~VALUE_POS;
        }

        if (body->dirtyValues & VALUE_BOUNDS)
        {
            for (cpShape* shape : physicsCollider->GetShapes())
            {
                ColliderInfo* info = nullptr;
                info = static_cast<ColliderInfo*>(cpShapeGetUserData(shape));
                if (info) {
                    cpShapeSetUserData(shape, nullptr);
                    info->valid = false;
                    delete info;
                }
                cpSpaceRemoveShape(space, shape);
                cpShapeFree(shape);
            }
            physicsCollider->GetShapes().clear();

            physicsCollider->SetupBoxShape(body->bounds.width, body->bounds.height, entity);

            body->dirtyValues &= ~VALUE_BOUNDS;
        }

        cpVect pos = cpBodyGetPosition(physicsCollider->GetBody());
        body->position = {(float)pos.x, (float)pos.y};
        body->rotation = (float)cpBodyGetAngle(physicsCollider->GetBody());
    }
}

void PhysicsSystem::DebugDraw()
{
    
}

cpBool PhysicsSystem::OnBeginCollision(cpArbiter* arb, cpSpace* space, void* userData)
{
    CP_ARBITER_GET_SHAPES(arb, a, b);
    ColliderInfo* colliderA = (ColliderInfo*)cpShapeGetUserData(a);
    ColliderInfo* colliderB = (ColliderInfo*)cpShapeGetUserData(b);

    if (!colliderA || !colliderB) return cpTrue;

    auto* system = static_cast<PhysicsSystem*>(userData);
    system->collisionManager->QueueCollision(colliderA, colliderB, CollisionEventType::EVENT_ENTER);

    return cpTrue;
}


void PhysicsSystem::OnEndCollision(cpArbiter* arb, cpSpace* space, void* userData)
{
    CP_ARBITER_GET_SHAPES(arb, a, b);
    ColliderInfo* colliderA = (ColliderInfo*)cpShapeGetUserData(a);
    ColliderInfo* colliderB = (ColliderInfo*)cpShapeGetUserData(b);

    if (!colliderA || !colliderB) return;

    auto* system = static_cast<PhysicsSystem*>(userData);
    system->collisionManager->QueueCollision(colliderA, colliderB, CollisionEventType::EVENT_EXIT);

}