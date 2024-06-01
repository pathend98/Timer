#include <thread>
#include <functional>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "timer.h"
#include "display.h"

int main()
{
    Timer t(120);
    Display d(t);

    std::thread timerThread(&Timer::start, std::ref(t));
    std::thread displayThread(&Display::start, std::ref(d));

    timerThread.join();
    displayThread.join();

    return 0;    
}
