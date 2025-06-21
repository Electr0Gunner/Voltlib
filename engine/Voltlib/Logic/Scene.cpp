#include "Scene.hpp"
#include "Physics/PhysicsSystem.hpp"

using namespace Volt;

Scene::Scene() : m_ID(nextSceneId++)
{
    physicsSystem = std::make_unique<PhysicsSystem>();
}

Scene::~Scene()
{

}


void Scene::SetGravity(const Vec2& gravity)
{
   
}

void Scene::Update()
{
    physicsSystem->Update(entities);
}

void Scene::Init()
{

}

void Scene::Start()
{

}

void Scene::Draw()
{

}

void Scene::Exit()
{

}