#include <vector>
#include <deque>
#include <iostream>

int main()
{
    //std::vector<int> data{1,2,3,4};
    std::deque<int> data{1,2,3,4};
    auto it = data.begin();
    int &tmp = data[1];
    int *tmp1 = &(data[2]);
    std::cout << *it << std::endl;
    std::cout << tmp << std::endl;
    std::cout << *tmp1 << std::endl;

    //data.erase(it);
    for(int i = 5; i < 100; i++) data.push_back(i);
    std::cout << *it << std::endl;
    std::cout << tmp << std::endl;
    std::cout << *tmp1 << std::endl;

    return 0;
}
