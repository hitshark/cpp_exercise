#include <iostream>

class A
{
    public:
        void display() const {std::cout<<"in A::display()\n";}
        virtual void View() const {std::cout<<"in A\n";}
};

class B : public A
{
    public:
        void display(const char *st) const {std::cout<<st<<std::endl;}
        //void View() const {std::cout<<"in B\n";}
        void View(const char * st) const {std::cout<<st<<std::endl;}
};

/*
int main()
{
    B b;
    B *p = &b;
    b.View();
    p->View();
    //p->View("hehe");
    //p->View("xixi");
    //b.View();

    return 0;
}
*/
