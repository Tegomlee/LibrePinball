#include "Application.h"

#include <iostream>

#include "raylib.h"

#include "Systems/Time.h"

namespace Tegomlee
{
    Application::Application(int width, int height, const std::string &title)
        : m_width_(width), m_height_(height), m_title_(title)
    {
        InitWindow(m_width_, m_height_, m_title_.c_str());
        SetTargetFPS(60);
    }

    Application::~Application()
    {
        CloseWindow();
    }

    void Application::Run()
    {
        Initialize();
        std::cout << "Application running" << std::endl;

        while (!WindowShouldClose())
        {
            Time::Get().Tick();

            PerformLogicTick();
            PerformRenderPass();
        }

        Terminate();
        std::cout << "Application terminated" << std::endl;
    }

    void Application::Initialize()
    {
        // TODO: Initialize Systems Here
    }

    void Application::PerformLogicTick()
    {
        // TODO: Update Systems Here
    }

    void Application::PerformRenderPass()
    {
        // TODO: Render Objects Here

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw your scene here (optional test shapes)
        DrawCircle(400, 300, 40, SKYBLUE);

        // Get deltaTime from your system
        float dt = Tegomlee::Time::Get().GetDeltaTime();

        // Calculate FPS manually (optional; raylib has built-in DrawFPS too)
        int fps = (dt > 0.0f) ? static_cast<int>(1.0f / dt) : 0;

        // Draw info using raylib text functions
        DrawText("LibrePinball - Timing Test", 10, 10, 20, DARKGRAY);

        DrawText(TextFormat("deltaTime: %.5f", dt), 10, 40, 20, MAROON);
        DrawText(TextFormat("FPS: %d", fps), 10, 70, 20, BLUE);

        // Optionally compare with raylib's built-in FPS
        DrawFPS(GetScreenWidth() - 100, 10);

        EndDrawing();

    }

    void Application::Terminate()
    {
        // TODO: Terminate Systems Here
    }
}
