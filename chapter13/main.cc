#include <iostream>
#include "port.h"

int main()
{
    Port *p;
    Port a("white_wine", "sweethahahahahahhhahahhhah", 20);
    VintagePort b("red_wine", "sault", 10, "red", 1573);
    p = &a;
    p->Show();
    p = &b;
    p-> Show();
    Port c = a;
    Port d;
    p = &c;
    p->Show();
    d = b;
    p = &d;
    p->Show();

    return 0;
}
