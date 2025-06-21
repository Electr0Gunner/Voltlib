#include "Collider.hpp"
#include "Logic/Entity.hpp"
#include "CollisionManager.hpp"

using namespace Volt;

    
Collider::Collider(PhysicsSystem* physicsSystem)
{
    system = physicsSystem;

    shapeType = SHAPE_INVALID;

    isStatic = false;
    friction = 0.0f;
    elasticity = 0.0f;

    physicsBody = nullptr;

    moment = 0.0f;
}
    
Collider::~Collider()
{
    for (cpShape* shape : shapes)
    {
        ColliderInfo* info = nullptr;
        info = static_cast<ColliderInfo*>(cpShapeGetUserData(shape));
        if (info && info->valid) {
            cpShapeSetUserData(shape, nullptr);
            info->valid = false;
            delete info;
        }
        cpShapeFree(shape);
    }
    shapes.clear();
    if (physicsBody)
    {
        if (cpBodyGetSpace(physicsBody))
            cpSpaceRemoveBody(system->space, physicsBody);

        cpBodyFree(physicsBody);
    }
}


void Collider::SetupBoxShape(float width, float height, Entity* owner)
{
    shapeType = SHAPE_BOX;
    shape = std::make_unique<BoxData>(width, height);

    BoxData* box = (BoxData*)shape.get();

    moment = cpMomentForBox(1.0f, box->width, box->height);

    physicsBody = isStatic ? cpBodyNewStatic() : cpBodyNew(1.0f, moment);

    cpBodySetPosition(physicsBody, cpv(position.x, position.y));
    cpSpaceAddBody(system->space, physicsBody);

    cpShape* rawShape = nullptr;
    rawShape = cpBoxShapeNew(physicsBody, box->width, box->height, 0.0f);

    if (shape) {
        cpShapeSetFriction(rawShape, friction);
        cpShapeSetElasticity(rawShape, elasticity);
        cpShapeSetSensor(rawShape, isSensor);
        ColliderInfo* info = new ColliderInfo();
        info->owner = owner;
        info->tag = "";
        info->shape = rawShape;
        info->valid = true;
        cpShapeSetUserData(rawShape, info);
        cpSpaceAddShape(system->space, rawShape);
        shapes.push_back(rawShape);
    }

}

void Collider::SetupCircleShape(float radius, Entity* owner)
{

}

void Collider::SetupPolygonShape(const std::vector<Vec2>& points, Entity* owner)
{
    
}