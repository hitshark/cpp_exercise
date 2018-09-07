#include <iostream>
#include "exp1.hpp"

using VECTOR::Vector;
using VECTOR::operator<<;

int main(int argc, char *argv[])
{
/*
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
*/
    std::cout<<VECTOR::R2D<<std::endl;
    Vector a(20,70);
    Vector b(10,58);
    std::cout<<a;
    Vector c = a + b;
    std::cout<<c;

    return 0;
}
