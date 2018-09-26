#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sys/time.h>

class Demo{
    public:
        Demo() {std::cout<<"constructor\n";}
        Demo(const Demo & rv) {
            *this = rv;
            std::cout<<"copy constructor\n";
        }
        ~Demo() {std::cout<<"destructor\n";}
        void print() {
            std::cout<<"hello world"<<std::endl;
        }
};

template<typename T>
void print(T var) {
    var.print();
}
template<>
void print(Demo & var) {
    std::cout<<"specialization\n";
    var.print();
}

void view(Demo && var) {
    std::cout<<"in view\n";
    var.print();
}

std::string get_random_str(int len) {
    static const std::string alphm = "abcdefghijklmnopqrstuvwsyz0123456789";
    static const int size = alphm.size();

    std::string rlt;
    for(int i=0; i<len; i++) {
        int index = rand() % size;
        rlt.push_back(alphm[index]);
    }
    return rlt;
}

#if defined(__i386__)
static __inline__ uint64_t getCycleCount() {
    uint64_t x;
    __asm__ volatile ("rdtsc":"=A"(x));
    return x;
}
#elif defined(__x86_64__)
static __inline__ uint64_t getCycleCount() {
    uint64_t hi, lo;
    __asm__ volatile("rdtsc":"=a"(lo),"=d"(hi));
    return ((hi << 32) + lo);
}
#endif


int main()
{
    /*
    {
        //Demo a;
        //print<Demo>(Demo());
        Demo a(Demo());
        print(Demo());
        view(Demo());
    }

    {
        int x = 10;
        int y = 20;
        int && a = 400;
        int && b = x*2 + y;

        int *ptr = &b;
        *ptr = 64;
        std::cout<<*ptr<<std::endl;
        std::cout<<b<<std::endl;

        x = 40;
        std::cout<<*ptr<<std::endl;
        std::cout<<b<<std::endl;
    }
    */

    {
        using vs = std::vector<std::string>;
        vs orig;
        uint64_t s1, s2;
        s1 = getCycleCount();
        for(int i=0; i<200000; i++) {
            std::string tmp = get_random_str(1000);
            orig.push_back(tmp);
        }
        s2 = getCycleCount() - s1;
        std::cout<<"initial time: "<<s2/(2.3*1000000000)<<std::endl;

        timeval t1, t2;
        s1 = getCycleCount();
        gettimeofday(&t1, nullptr);
        vs new_dat(std::move(orig));
        //vs new_dat(orig);
        gettimeofday(&t2, nullptr);
        s2 = getCycleCount() - s1;
        double time_used = (t2.tv_sec-t1.tv_sec) * 1000000 + (t2.tv_usec-t1.tv_usec);
        std::cout<<"time: "<<time_used/1000000<<std::endl;
        std::cout<<"accurate time: "<<s2/(2.3*1000000000)<<std::endl;

    }

    return 0;
}

