#include "timer.h"
#include "clock.h"

#include <chrono>
#include <thread>

Timer::Timer(const int hours, const int minutes, const int seconds) : Timer(hours * 3600 + minutes * 60 + seconds)
{}

Timer::Timer(const int s)
{
    seconds.store(s);
}

Timer::Timer() : Timer(0, 0, 0)
{}

/**
 * This is overkill when we are checking that seconds > 0 before calling, but it demonstrates
 * a good concept which might be useful to know for future reference. 
*/
void Timer::decrament()
{
    int current = seconds.load();
    while (current > 0 && !seconds.compare_exchange_weak(current, current - 1))
    {}
}

void Timer::start()
{
    while (seconds.load() > 0)
    {
        auto next = std::chrono::steady_clock::now() + std::chrono::seconds(1);
        decrament();
        std::this_thread::sleep_until(next);
    }
    
}

std::shared_ptr<std::vector<std::string>> Timer::toString() const
{
    return Clock(seconds.load()).toString();
}
