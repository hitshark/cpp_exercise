#include <iostream>

class Base {
    public:
        explicit Base(int32_t age, std::string nm = "charly") : age_(age), name_(nm) {}
        int32_t getAge() const { return age_; }
        std::string getName() const { return name_; }

    public:
        int32_t age_;
    private:
        std::string name_;
};

class Derived : private Base {
    public:
        Derived(int32_t age) : Base(age) {}
        void logAge() const {
            int32_t age = Base::getAge();
            std::cout << age << std::endl;
            int32_t age_tmp = ((Base *)this) -> age_;
            std::cout << age_tmp << std::endl;
            int32_t age_3 = Base::age_;
            std::cout << age_3 << std::endl;
        }
};

int main()
{
    Derived obj(27);
    obj.logAge();

    return 0;
}
