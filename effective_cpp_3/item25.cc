#include <iostream>
#include <memory>

namespace Tt{

class Test{
    public:
        explicit Test(const char *nm) {
            if(nm != nullptr) {name = std::make_shared<std::string>(nm);}
            else std::cout<<"nullptr\n";
        }
        void swap(Test & t) {
            using std::swap;
            swap(this->name, t.name);
        }
        void disp() const {std::cout<<*name<<std::endl;}
    private:
        // may be we need a pointer to implementation to clarify this custom swap function
        // char *name;
        std::shared_ptr<std::string> name;
};

void swap(Test & t1, Test &t2) {
    std::cout<<"Tt::swap\n";
    t1.swap(t2);
}
}

using namespace Tt;
namespace std{
template<>
void swap<Test>(Test &t1, Test &t2) noexcept {
    std::cout<<"std::swap<Test>\n";
    t1.swap(t2);
}
}

void swap(Test &t1, Test &t2) {
    std::cout<<"global swap\n";
}

void helper(Test &t1, Test &t2) {
    using std::swap;
    swap(t1, t2);
}

int main()
{
    Test a("tom");
    Test b("erin");
    helper(a,b);
    a.disp();
    b.disp();
    return 0;
}
