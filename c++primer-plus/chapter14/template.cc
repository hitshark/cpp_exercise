#include <iostream>
#include <string>

template <typename T>
class A
{
    public:
        A():val_(0x100){}
        void disp(){std::cout<<"in A: "<<val_<<std::endl;}
    private:
        T val_;
};

template <typename T>
class B : public A<int>
{
    public:
        explicit B(const T &t):val_(t){}
        void view(){std::cout<<val_<<std::endl;}
    private:
        T val_;
};

int main()
{
    B<std::string> a("hello world");
    a.disp();
    a.view();

    return 0;
}
