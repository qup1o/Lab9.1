//////////////////////////////////////////////////////////////////////////
// sum.cpp
// файл реалізації функції
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"                  // підключили зовнішні оголошення змінних

using namespace nsDod;
using namespace nsVar;

void nsSum::sum()
{
    const double halfPi = 1.57079632679489661923;     // pi / 2

    n = 0;
    a = -1 / x;                   // перший доданок (n = 0)
    s = a;
    do
    {
        n++;
        dod();                    // виклик процедури обчислення доданку
        s += a;
    } while (fabs(a) > e);

    s += halfPi;                  // arctg x = pi/2 + сума ряду
}
