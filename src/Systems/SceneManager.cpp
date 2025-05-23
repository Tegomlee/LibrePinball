#include "SceneManager.h"

#include <iostream>

#include "Scenes/Scene.h"

namespace Tegomlee
{
    std::unique_ptr<SceneManager> SceneManager::m_instance_ = nullptr;

    void SceneManager::Process()
    {
        // TODO: Updates the scenes here
        std::cout << "I am running" << std::endl;
    }

    void SceneManager::Render()
    {
        // TODO: Draw scene objects here
    }

    SceneManager* SceneManager::Get()
    {
        if (!m_instance_)
        {
            m_instance_ = std::make_unique<SceneManager>();
        }
        return m_instance_.get();
    }

    void SceneManager::ChangeScene(std::unique_ptr<Scene> scene)
    {
        if (!scene) return;

        if (m_current_scene_)
        {
            m_current_scene_->OnExit();
        }

        m_current_scene_ = std::move(scene);
        m_current_scene_->OnEnter();
    }

    Scene* SceneManager::GetCurrentScene() const
    {
        return m_current_scene_.get();
    }
} // Tegomlee