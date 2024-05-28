#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "timer.h"

int main()
{
    Timer t(3);

    auto lines = t.toString();
    for (const auto& line : *lines)
        cout << line << endl;

    t.start();

    lines = t.toString();
    for (const auto& line : *lines)
        cout << line << endl;

    return 0;    
}
