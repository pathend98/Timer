#include "display.h"

#include <iostream>
#include <chrono>
#include <thread>
using std::cout;
using std::endl;

Display::Display(Timer& timer) : timer(timer)
{}

void Display::print() const
{
    const auto lines = timer.toString();

    for (const auto& line : *lines)
        cout << line << endl;
}

void Display::clear() const
{
    const auto lines = timer.toString();

    cout << "\033[" << lines->size() << "A";
    for (auto i = 0; i < lines->size(); ++i)
        cout << "\033[K";

}

void Display::start() const
{
    bool isRunning = true;

    while (isRunning)
    {
        isRunning = timer.isRunning();
        auto next = std::chrono::steady_clock::now() + std::chrono::seconds(1);
        print();
        std::this_thread::sleep_until(next);

        if (isRunning)
            clear();
    }
}

