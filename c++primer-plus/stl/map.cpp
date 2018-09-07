#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>
#include <iostream>

int main()
{
    using std::map;
    using std::set;
    using std::string;
    using std::vector;

    map<string, vector<int>> scores;
    using value_t = map<string, vector<int>>::value_type;
    using key_t = map<string, vector<int>>::key_type;
    using key_cpr = map<string, vector<int>>::key_compare;
    using value_cpr = map<string, vector<int>>::value_compare;

    scores.insert(value_t("tom", vector<int>{1,2,3}));
    scores.insert(std::make_pair("harry", vector<int>{4,5,6}));

    for(auto iter = scores.begin(); iter != scores.end(); iter++){
        std::cout<<iter->first<<std::endl;
    }

    key_cpr fp;
    std::cout<<key_cpr()(string("alice"),string("bob"))<<std::endl;
    std::cout<<scores.key_comp()(string("alice"),string("bob"))<<std::endl;
    std::cout<<scores.value_comp()(std::make_pair("tom", vector<int>{1,2}), std::make_pair("erin", vector<int>{3,4}))<<std::endl;
    //std::cout<<value_cpr(std::less<string>())(std::make_pair("tom",vector<int>{1,2}), std::make_pair("erin", vector<int>{3,4}))<<std::endl;

    for(auto x : scores["tom"]) std::cout<<x<<" ";
    std::cout<<std::endl;

    return 0;
}

