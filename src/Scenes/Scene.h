#ifndef TEGOMLEE_SCENES_SCENE_H
#define TEGOMLEE_SCENES_SCENE_H

#include <vector>

namespace Tegomlee
{
    class Scene
    {
    public:
        virtual ~Scene() = default;

        virtual void OnEnter() {}
        virtual void OnExit() {}

        virtual void Process() = 0;
        virtual void Render() = 0;

    protected:
        // std::vector<Object> scenes;
    };
}

#endif //TEGOMLEE_SCENES_SCENE_H
