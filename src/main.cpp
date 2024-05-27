#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "digit.h"
#include "clock.h"

int main()
{
    int num;
    cout << "Please input a digit to display: ";
    cin >> num;

    if (num < 0 || num > 9)
    {
        cout << "Number not between 0 and 9." << endl;
        return 1;
    }

    Digit d(num);

    const auto lines = d.toString();
    for (const auto& line : *lines)
        cout << line << endl;

    Clock c(12, 9);

    const auto clockLines = c.toString();
    for (const auto& line : *clockLines)
        cout << line << endl;

    return 0;    
}
