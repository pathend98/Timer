#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "digit.h"
#include "clock.h"

int main()
{
    Clock c(1, 2, 3);

    const auto clockLines = c.toString();
    for (const auto& line : *clockLines)
        cout << line << endl;

    return 0;    
}
