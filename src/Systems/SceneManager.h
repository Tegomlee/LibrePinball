#ifndef TEGOMLEE_SYSTEMS_SCENEMANAGER_H
#define TEGOMLEE_SYSTEMS_SCENEMANAGER_H

#include <memory>

namespace Tegomlee
{
    class Scene;

    class SceneManager
    {
    public:
        SceneManager() = default;
        ~SceneManager() = default;

        void Process();
        void Render();

        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        SceneManager(SceneManager&&) = delete;
        SceneManager& operator=(SceneManager&&) = delete;

        static SceneManager* Get();

        void ChangeScene(std::unique_ptr<Scene> scene);
        [[nodiscard]] Scene* GetCurrentScene() const;

    private:

        static std::unique_ptr<SceneManager> m_instance_;
        std::unique_ptr<Scene> m_current_scene_;
    };

} // Tegomlee

#endif //TEGOMLEE_SYSTEMS_SCENEMANAGER_H
