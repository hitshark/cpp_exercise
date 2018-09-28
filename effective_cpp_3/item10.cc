#include <iostream>

class Widget{
    public:
        explicit Widget(int flag_) : flag(flag_){}
        void test(const Widget & wd) {std::cout<<wd.getFlag()<<std::endl;}
        //Widget & operator=(const Widget & wd) {
        Widget operator=(const Widget & wd) {
            this->flag = wd.flag;
            return *this;
        }
        int getFlag() const {return flag;}
    private:
        //Widget(const Widget &);
        int flag;
};

int main()
{
    Widget a(1), b(2), c(3);
    a = b = c;
    std::cout<<a.getFlag()<<std::endl;
    return 0;
}
