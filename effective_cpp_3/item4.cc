#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

// non-local static variable handling methods
// method 1
class TestStatic {
    public:
        TestStatic() : name({"tom", "alice"}), phone_num() {}
        void disp() {
            for(auto x : name) std::cout<<x<<std::endl;
        }
    private:
        std::vector<std::string> name;
        std::map<int, int> phone_num;
};

TestStatic & getTestStatic() {
    static TestStatic ts;
    return ts;
}

// method 2, singleton
class TestStatic2 {
    public:
        TestStatic2(std::vector<std::string> nm = {"tom", "erin"}) : name(nm) {}
        void disp() {
            for(auto x : name) std::cout<<x<<std::endl;
        }
        static TestStatic2 & Instance(std::vector<std::string> nm = {"erin", "karen"}) {
            static TestStatic2 ts{nm};
            return ts;
        }

    private:
        std::vector<std::string> name;
        std::map<int, int> phone_num;
};

int main()
{
    TestStatic a = getTestStatic();
    a.disp();
    TestStatic2 b = TestStatic2::Instance();
    b.disp();

    return 0;
}
