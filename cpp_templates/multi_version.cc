#include <iostream>

template <int ver>
class Conv {
public:
    void print() const;
    void log() const;
};

template <int ver>
void Conv<ver>::print() const {
    std::cout << "in print, no specialization" << std::endl;
}
template <int ver>
void Conv<ver>::log() const {
    std::cout << "in log, no specialization" << std::endl;
}

template <>
void Conv<1>::print() const {
    std::cout << "in print, instance 1" << std::endl;
    log();
}

template <>
void Conv<2>::log() const {
    std::cout << "in log, instance 2" << std::endl;
}

int main()
{
    Conv<0> inst0;
    inst0.print();
    inst0.log();

    Conv<1> inst1;
    inst1.print();
    inst1.log();

    return 0;
}
