#include <iostream>
#include <cstring>
#include "str.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    String a("hello world\n");
    String b("that girl");
    cout<<a<<b<<endl;

    cout<<a[1]<<endl;
    a[1] = 'a';
    cout<<a[1]<<endl;

    String c = a;
    cout<<c;

    c = b;
    cout<<c;

    std::cin >> c;
    cout<<c;

    char *haha = new char[10];
    std::strcpy(haha, "hello worlds test\n");
    //std::strcpy(haha, "hello\n");
    cout<<haha;
    //delete [] haha;

    return 0;
}
