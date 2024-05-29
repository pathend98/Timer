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

    cout << "\033[" << lines->size() << "A";
    for (auto i = 0; i < lines->size(); ++i)
        cout << "\033[K";

    lines = t.toString();
    for (const auto& line : *lines)
        cout << line << endl;

    return 0;    
}
