#include "Time.h"

#include "raylib.h"

namespace Tegomlee
{
    Time & Time::Get()
    {
        static Time instance;
        return instance;
    }

    float Time::GetDeltaTime() const
    {
        return m_delta_time_;
    }

    Time::Time()
        : m_previous_time_(GetTime()), m_delta_time_(0.0f) {}

    void Time::Tick()
    {
        const double currentTime = GetTime();
        m_delta_time_ = static_cast<float>(currentTime - m_previous_time_);
        m_previous_time_ = currentTime;
    }
}
