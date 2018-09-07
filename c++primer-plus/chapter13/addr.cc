#include <iostream>
using namespace std;

class Base
{
    public:
        Base(){cout<<"base construct"<<endl;}
        virtual void f(){cout<<"base::f()"<<endl;}
        virtual void g(){cout<<"base::g()"<<endl;}
        virtual void h(){cout<<"base::h()"<<endl;}
        virtual ~Base(){}
};

int main()
{
    typedef void (*Fun)();
    Base *b = new Base();

    cout<<"start address: "<<*(long long *)(b)<<endl;

    Fun funf = (Fun)(*(long long *)*(long long *)(b));
    Fun fung = (Fun)(*((long long *)*(long long *)(b)+1));
    Fun funh = (Fun)(*((long long *)*(long long *)(b)+2));

    funf();
    fung();
    funh();

    cout << (long long)funh << endl;
    cout <<(*((long long *)*(long long *)b+0))<<endl;
    cout <<(*((long long *)*(long long *)b+1))<<endl;
    cout <<(*((long long *)*(long long *)b+2))<<endl;
    cout <<(*((long long *)*(long long *)b+3))<<endl;
    cout <<(*((long long *)*(long long *)b+4))<<endl;

    delete b;
    return 0;
}
