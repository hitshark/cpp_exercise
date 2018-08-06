#include <vector>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <array>
#include <valarray>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;

// members common to all or most containers
void basic_member()
{
    vector<int> a = {1,2,3,4};
    vector<int>::value_type b = 10;
    vector<int>::reference c = b;
    vector<int>::const_reference d = b;
    vector<int>::iterator iter = a.begin();                     // iterator type pointing to T, behaves like type T*
    vector<int>::size_type num = a.size();                      // unsigned integer type
    vector<int>::difference_type diff = a.end() - a.begin();    // signed integer type

    cout<<"size_type: num = "<<num<<endl;
    cout<<"difference_type: diff = " <<diff<<endl;
}

// operations defined for all containers
void basic_op()
{
    using std::list;
    using std::string;

    list<int> a = {1, 2, 3};
    list<int> b(a);
    list<int> c = a;
    (&b)->~list<int>();

    auto iter1 = a.begin();
    *iter1 = 10;
    for(auto x : a) cout<<x<<endl;

    auto iter2 = a.cbegin();
    //*iter2 = 5;
    auto num = a.size();
    auto maxsize = a.max_size();
    auto isempty = a.empty();
    swap(a, c);
    if(a == c) cout<<"equal\n";
}

void replace_ele(std::string str)
{
    using std::string;
    vector<string> input;
    string temp;
    while(std::cin >> temp && temp != "quit"){
        input.push_back(temp);
    }
    vector<string>::iterator iter = find(input.begin(), input.end(), str);
    if(iter != input.end()){
        vector<string>::reference r = *iter;
        r = "bogus";
    }
    copy(input.begin(), input.end(), std::ostream_iterator<std::string, char>(cout, " "));
    //for(auto x : input) cout<<x<<endl;
}

template<typename Bag>
typename Bag::value_type min(const Bag & b)
{
    typename Bag::const_iterator it;
    typename Bag::value_type m = *b.begin();
    //auto m = *b.begin();
    //for(auto it = b.begin(); it != b.end(); it++){    // auto is also right, so when and where to use auto?
    for(it = b.begin(); it != b.end(); it++){
        if(*it < m) m = *it;
    }
    return m;
}

void add_sequence_op()
{
    std::deque<int> dat;
    dat = {1, 2, 3, 4};
    cout<<dat.front()<<endl;
    dat.push_front(2);
    cout<<dat.front()<<endl;
    cout<<dat.back()<<endl;
    dat.clear();
    if(dat.empty()) cout<<"empty\n";

    std::vector<int> a = {1, 2, 3, 4, 5};
    a.assign(11, 0xff);
    a.resize(5);
    a.assign({1,2,3,4});
    a.erase(a.begin());
    a.insert(a.end(), {4,3,2});
    for(auto x : a) cout<<x<<endl;
    cout<<a.capacity()<<endl;
}

int main()
{
    add_sequence_op();
    //basic_op();
    //cout<<min<vector<int>>(vector<int>{1,2,3,4})<<endl;
    return 0;
}
