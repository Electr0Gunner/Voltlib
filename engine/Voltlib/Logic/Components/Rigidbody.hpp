#pragma once

#include "Transform.hpp"
#include "Logic/Scene.hpp"
#include "Logic/Entity.hpp"
#include "Physics/Collider.hpp"
#include "Physics/PhysicsSystem.hpp"
#include <vector>
#include "Math/Vector.hpp"
#include <chipmunk/chipmunk.h>

namespace Volt
{
    enum DirtyValues
    {
        VALUE_POS = 1,
        VALUE_ROTATION = 2,
        VALUE_BOUNDS = 4,
    };

    class RigidBody : public Transform
    {
    public:
        virtual void Init()
        {
            if (!collider)
                collider = owner->AddComponent<Collider>(owner->parentScene->physicsSystem.get());
            collider->Init();
            collider->SetupBoxShape(bounds.width, bounds.height, owner);
            collider->Start();
        }

        virtual void ApplyForce(const Vec2& force)
        {
            Collider* collider = GetCollider();
            if (!collider)
                return;
            cpBodyApplyForceAtWorldPoint(collider->GetBody(), cpv(force.x, force.y), cpBodyGetPosition(collider->GetBody()));
        }

        virtual void ApplyImpulse(const Vec2& impulse)
        {
            Collider* collider = GetCollider();
            if (!collider)
                return;
            cpBodyApplyImpulseAtWorldPoint(collider->GetBody(), cpv(impulse.x, impulse.y), cpBodyGetPosition(collider->GetBody()));
        }

        virtual void SetVelocity(const Vec2& velocity)
        {
            Collider* collider = GetCollider();
            if (!collider)
                return;
            cpBodySetVelocity(collider->GetBody(), cpv(velocity.x, velocity.y));
        }

        virtual Vec2 GetVelocity()
        {
            Collider* collider = GetCollider();
            if (!collider)
                return Vec2(0, 0);
            cpVect cpVelocity = cpBodyGetVelocity(collider->GetBody());
            return Vec2((float)cpVelocity.x, (float)cpVelocity.y);
        }

        virtual void SetPosition(float x = 0.0f, float y = 0.0f)
        {
            Transform::SetPosition(x, y);
            dirtyValues |= VALUE_POS;
        }

        virtual void SetPosition(const FPoint& pos)
        {
            Transform::SetPosition(pos);
            dirtyValues |= VALUE_POS;
        }

        virtual void Rotate(float degrees)
        {
            Transform::Rotate(degrees);
            dirtyValues |= VALUE_ROTATION;
        }


        virtual void SetBounds(const FRect& newBounds)
        {
            Transform::SetBounds(newBounds);
            dirtyValues |= VALUE_BOUNDS;
        }

        virtual void Scale(float factorX, float factorY)
        {
            Transform::Scale(factorX, factorY);
            dirtyValues |= VALUE_BOUNDS;
        }

        virtual void Scale(const Vec2& scaleFactor)
        {
            Transform::Scale(scaleFactor);
            dirtyValues |= VALUE_BOUNDS;
        }

        Collider* GetCollider() const { return owner->GetComponent<Collider>(); }

        Collider* collider;
        int dirtyValues;
    };

} // namespace Volt
