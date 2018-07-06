#include <iostream>

class A
{
    public:
        void Show(){std::cout<<"in A\n";}
};

class B : public A
{
    public:
        void disp(){
            A::Show();
            std::cout<<"hello world\n";
        }
    public:
        void Show(){}
};

int main()
{
    using ta = int;
    ta temp = 10;
    std::cout << temp << std::endl;
    B b;
    b.disp();
    b.Show();

    return 0;
}
