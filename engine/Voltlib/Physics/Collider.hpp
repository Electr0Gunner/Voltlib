#pragma once

#include <vector>
#include <memory>
#include "Math/Vector.hpp"
#include "Logic/Components/Component.hpp"
#include "PhysicsSystem.hpp"

namespace Volt
{
    class Entity;

    class ShapeData
    {
    public:
        ShapeData() {}
        ~ShapeData() {}
    };

    class BoxData : public ShapeData
    {
    public:
        float width;
        float height;

        BoxData(float width, float height): width(width), height(height) {}
        ~BoxData() {}
    }; 

    class CircleData : public ShapeData
    {
    public:
        float radius;

        CircleData(float radius): radius(radius) {}
        ~CircleData() {}
    }; 

    class PolygonData : public ShapeData
    {
    public:
        std::vector<Vec2> points;

        PolygonData(const std::vector<Vec2>& points): points(points) {}
        ~PolygonData() {}
    }; 

    enum ColliderShape
    {
        SHAPE_INVALID = 0,
        SHAPE_BOX,
        SHAPE_CIRCLE,
        SHAPE_POLYGON,
        NUM_SHAPES,
    };

    class Collider : public Component
    {
    private:
        PhysicsSystem* system;
        cpBody* physicsBody;
        std::vector<cpShape*> shapes;

        ColliderShape shapeType;
        Vec2 position;
        std::unique_ptr<ShapeData> shape;
        bool isStatic = false;
        bool isSensor = false;
        float friction = 0.0f;
        float elasticity = 0.0f;

        float moment;

    public:
        Collider(PhysicsSystem* physicsSystem);
        ~Collider();

        void SetupBoxShape(float width, float height, Entity* owner);
        void SetupCircleShape(float radius, Entity* owner);
        void SetupPolygonShape(const std::vector<Vec2>& points, Entity* owner);

        cpBody* GetBody() {return physicsBody;}
        std::vector<cpShape*> GetShapes() {return shapes;}
    };

} // namespace Volt
