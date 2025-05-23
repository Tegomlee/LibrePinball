#ifndef TEGOMLEE_SYSTEMS_TIME_H
#define TEGOMLEE_SYSTEMS_TIME_H

namespace Tegomlee
{
    class Time
    {
        friend class Application;

    public:
        static Time& Get();

        [[nodiscard]] float GetDeltaTime() const;

    private:
        Time();

        void Tick();

        double m_previous_time_;
        float m_delta_time_;
    };
}

#endif //TEGOMLEE_SYSTEMS_TIME_H
