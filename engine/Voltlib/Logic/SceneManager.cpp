#include "SceneManager.hpp"
#include "App.hpp"

using namespace Volt;

SceneManager::SceneManager()
{
    
}

SceneManager::~SceneManager()
{
    for (auto& scene : m_Scenes)
        RemoveScene(scene.get());
}

void SceneManager::Update()
{
    for (auto& scene : m_Scenes) 
        if (!scene->m_Paused)
            scene->Update();
}

void SceneManager::Draw()
{
    for (auto& scene : m_Scenes) 
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
    m_Scenes.erase(std::remove_if(m_Scenes.begin(), m_Scenes.end(),
    [=](const std::unique_ptr<Scene>& s) {
            return s->m_ID == sceneToRemove->m_ID;
        }),
        m_Scenes.end());
}
