#include <iostream>
#include "exp1.hpp"

int main(int argc, char *argv[])
{
    Time a;
    Time b(2, 34);
    Time c;

    a.AddMin(40);
    a.Show();
    c = a.Sum(b);
    c.Show();
    c =c.operator+(b);
    c.Show();
    c = c + b;
    c.Show();

    c = c * 3.0;
    c.Show();
    c = 2.7 * c;
    c.Show();

    return 0;
}
