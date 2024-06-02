#include <thread>
#include <functional>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "timer.h"
#include "display.h"

void countdownTimer(int seconds)
{
    Timer t(seconds);
    Display d(t);

    std::thread timerThread(&Timer::start, std::ref(t));
    std::thread displayThread(&Display::start, std::ref(d));

    timerThread.join();
    displayThread.join();
}

int getDuration()
{
    cout << "How many seconds should the timer count for? " << endl;
    string duration;
    cin >> duration;
    return std::stoi(duration);
}

int main()
{
    try 
    {
        int duration = getDuration();
        countdownTimer(duration);
    }
    catch (std::invalid_argument& e)
    {
        cout << "Unable to acquire a duration from input" << endl;
        return 1;
    }
    catch (std::out_of_range& e)
    {
        cout << "Input is either too small or too large" << endl;
        return 1;
    }
    
    return 0;    
}
