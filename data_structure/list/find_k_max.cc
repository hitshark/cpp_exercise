#include <iostream>
#include<random>
#include <array>
#include <algorithm>
#include <vector>
#include <ctime>
#include <sys/time.h>

using namespace std;

// time related definition
#if defined (__i386__)
static __inline__ unsigned long long GetCycleCount(void)
{
        unsigned long long int x;
        __asm__ volatile("rdtsc":"=A"(x));
        return x;
}
#elif defined (__x86_64__)
static __inline__ unsigned long long GetCycleCount(void)
{
        unsigned hi,lo;
        __asm__ volatile("rdtsc":"=a"(lo),"=d"(hi));
        return ((unsigned long long)lo)|(((unsigned long long)hi)<<32);
}
#endif


int find_kmax_1(const vector<int> &inp, size_t k)
{
    if(inp.size() < k) {
        cout<<"error input size, exit!\n";
        abort();
    }
    else {
        vector<int> tmp(inp.begin(), inp.begin()+k);
        sort(tmp.begin(), tmp.end(), [](int x, int y){return (x > y);});
        for(auto iter=inp.begin()+k; iter != inp.end(); iter++) {
            if(*iter > tmp[k-1]) {
                for(auto it = tmp.begin(); it != tmp.end(); it++) {
                    if(*iter > *it) {
                        tmp.insert(it, *iter);
                        tmp.pop_back();
                        break;
                    }
                }
            }
        }
        return tmp[k-1];
    }
}

int find_kmax_2(vector<int> &inp, size_t k)
{
    if(inp.size() < k) {
        cout<<"error input size, exit!\n";
        abort();
    }
    else {
        sort(inp.begin(), inp.end(), [](int x, int y){return (x > y);});
        return inp[k-1];
    }
}

int main()
{
    const int NUM = 10000;
    const int K = 500;
    vector<int> dat;
    using rdm = std::default_random_engine;
    using distr = std::uniform_int_distribution<int>;
    rdm ele(time(nullptr));
    distr dis(0, 255);
    for(int i=0; i<NUM; i++) {
        dat.push_back(dis(ele));
    }

    int result;

    /*
    time_t start, end;
    start = time(nullptr);
    result = find_kmax_1(dat, K);
    end = time(nullptr);
    cout<<"result: "<<result<<" time: "<<end-start<<endl;

    clock_t cstr, cend;
    cstr = clock();
    find_kmax_1(dat, K);
    cend = clock();
    cout<<"result: "<<result<<" time: "<<double(cend-cstr)/CLOCKS_PER_SEC<<endl;
    */

    timeval t1, t2;
    double time_used;
    gettimeofday(&t1, nullptr);
    result = find_kmax_1(dat, K);
    gettimeofday(&t2, nullptr);
    time_used = (t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec - t1.tv_usec);
    cout<<"result: "<<result<<" time1: "<<time_used/1000000<<endl;

    gettimeofday(&t1, nullptr);
    result = find_kmax_2(dat, K);
    gettimeofday(&t2, nullptr);
    time_used = (t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec - t1.tv_usec);
    cout<<"result: "<<result<<" time2: "<<time_used/1000000<<endl;

    return 0;
}
