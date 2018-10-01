#include <iostream>
#include <functional>

class Base{
    public:
        explicit Base(int score_) : score(score_) {}
        void print() const {std::cout<<score<<std::endl;}
        virtual ~Base(){}
    private:
        int score;
        Base();
};

class Derived : public Base{
    public:
        void view() const {Base::print();}
};

int main()
{
    Derived a;
    a.view();
    return 0;
}

