#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "digit.h"

int main()
{
    int num;
    cout << "Please input a digit to display: ";
    cin >> num;

    if (num < 0 || num > 9)
        return 1;

    Digit d(num);
    cout << d.toString() << endl;
    return 0;    
}
