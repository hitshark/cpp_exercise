#include <memory>
#include <iostream>
#include <array>
#include <sys/time.h>

struct Data{
    //Data(){
    //    for(auto &x : dat) {x = std::rand() % 256;}
    //}
    enum {MAX = 1024*1024};
    std::array<int,MAX> dat;
};

int main()
{
    timeval t1, t2;
    gettimeofday(&t1, nullptr);
    for(int i = 0; i < 10000; i++) {
        std::shared_ptr<Data> a(new Data);
    }
    gettimeofday(&t2, nullptr);
    double rlt = ((t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec))/1000000.0;
    std::cout<<rlt<<std::endl;

    gettimeofday(&t1, nullptr);
    for(int i = 0; i < 10000; i++) {
        std::shared_ptr<Data> a = std::make_shared<Data>();
    }
    gettimeofday(&t2, nullptr);
    rlt = ((t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec))/1000000.0;
    std::cout<<rlt<<std::endl;

    return 0;
}
