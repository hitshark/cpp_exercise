#include <iostream>

class A
{
    public:
        virtual void disp() const {std::cout<<"in A\n";}
};

class B : private A
{
    public:
        void view() const {disp();}
    public:
        void disp() const {
            A::disp();
            std::cout<<"in B private\n";
        }
};

int main()
{
    B b;
    b.view();
    b.disp();

    return 0;
}
