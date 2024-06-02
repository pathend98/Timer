#pragma once

#include <atomic>
#include <memory>
#include <string>
#include <vector>

class Timer
{
    private:
        std::atomic<int> seconds;
        void decrament();

    public:
        Timer(const int hours, const int minutes, const int seconds);
        Timer(const int seconds);
        Timer();

        void start();
        bool isRunning() const;
        std::shared_ptr<std::vector<std::string>> toString() const;
};
