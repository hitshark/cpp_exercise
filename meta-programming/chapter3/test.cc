#include <iostream>

class Test {
    private:
        int age_;
    public:
        explicit Test(int age) : age_(age) {}
        void print() const {
            std::cout << "hello" << std::endl;
        }
};

int main()
{
    Test tom(3);
    Test erin = tom;

    return 0;
}
