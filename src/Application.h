#ifndef TEGOMLEE_APPLICATION_H
#define TEGOMLEE_APPLICATION_H

#include <string>

namespace Tegomlee
{
    class Application
    {
    public:
        Application(int width, int height, const std::string& title);
        ~Application();

        void Run();

    private:
        void Initialize();
        void PerformLogicTick();
        void PerformRenderPass();
        void Terminate();

        // Application Variables
        int m_width_;
        int m_height_;
        std::string m_title_;
    };
}

#endif //TEGOMLEE_APPLICATION_H
