#include <iostream>

class VirtualDestructor {
    public:
        VirtualDestructor(uint32_t age_ = 10, uint32_t score_ = 0) : age(age_), score(score_) {}
        virtual ~VirtualDestructor(){}
        //~VirtualDestructor(){}
    private:
        uint32_t age;
        uint32_t score;
};

void disp(uint64_t dat) {std::cout<<dat<<std::endl;}

int main()
{
    VirtualDestructor a;
    std::cout<<sizeof(a)<<std::endl;
    disp(*reinterpret_cast<uint64_t *>(&a));

    return 0;
}
