#include "SceneManager.hpp"
#include "Application.hpp"

using namespace Volt;

SceneManager::SceneManager()
{
    
}

SceneManager::~SceneManager()
{
    for (auto& scene : scenes)
        RemoveScene(scene.get());
}

void SceneManager::Update()
{
    for (auto& scene : scenes) 
        if (!scene->m_Paused)
            scene->Update();
}

void SceneManager::Draw()
{
    for (auto& scene : scenes) 
        scene->Draw();
}

void SceneManager::PauseScene(Scene* scene)
{
    scene->OnPause();
}

void SceneManager::ResumeScene(Scene* scene)
{
    scene->OnResume();
}

void SceneManager::RemoveScene(Scene* sceneToRemove)
{
    scenes.erase(std::remove_if(scenes.begin(), scenes.end(),
    [=](const std::unique_ptr<Scene>& s) {
            return s->m_ID == sceneToRemove->m_ID;
        }),
        scenes.end());
}
