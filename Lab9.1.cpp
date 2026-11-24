//////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
// головний файл проекту – функція main
// Варіант 28: arctg x = pi/2 + сума (-1)^(n+1) / ((2n+1) x^(2n+1)),  x > 1

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    // ряд збігається лише при x > 1
    if (x_p <= 1 || dx <= 0)
    {
        cout << "Error: x_p must be > 1 and dx must be > 0" << endl;
        return 1;
    }

    // горизонтальна лінія таблиці
    const string line = "+----------+--------------+--------------+--------+";

    cout << "Table of the function arctg(x), x > 1" << endl;
    cout << line << endl;
    cout << "|    x     |   arctg(x)   |     sum      |   n    |" << endl;
    cout << line << endl;
    cout << fixed << setprecision(6);

    x = x_p;
    while (x <= x_k + dx / 1000)      // допуск на похибку накопичення x += dx
    {
        sum();                        // виклик процедури обчислення суми

        cout << "| " << setw(8) << x
            << " | " << setw(12) << atan(x)
            << " | " << setw(12) << s
            << " | " << setw(6) << n << " |" << endl;

        x += dx;
    }
    cout << line << endl;

    cin.get();
    cin.get();
    return 0;
}

// 1.5 3 0.5 0.000001