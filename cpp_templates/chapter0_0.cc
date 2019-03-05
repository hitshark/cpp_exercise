#include <iostream>
#include <string>
#include <memory>

class Base {
    public:
        Base(const std::string nm) : name_(nm) {}
        virtual void logOut() const {
            std::cout << "in Base class: " << name_ << std::endl;
        }
    private:
        std::string name_;
};

class Derived : public Base {
    public:
        Derived(const std::string nm) : Base("base"), name_(nm) {}
        virtual void logOut() const {
            std::cout << "in Derived class: " << name_ << std::endl;
        }
        void testPrint() const {
            Base::logOut();
            std::cout << "test for derived class" << std::endl;
        }
    private:
        std::string name_;
};

int main()
{
    /*
    char a = 'a';
    char* const b = &a;
    *b = 'c';
    std::cout << *b << std::endl;
    */

    /*
    Base* pa = new Derived("derived");
    pa->logOut();
    //pa->testPrint();

    std::shared_ptr<Base> pb = static_cast<std::shared_ptr<Base> >(
            std::make_shared<Derived>("haha"));
    pb->logOut();
    */

    int a = 12;
    int& b = a;
    auto c = b;
    auto d = a;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &c << std::endl;
    std::cout << &d << std::endl;

    return 0;
}
