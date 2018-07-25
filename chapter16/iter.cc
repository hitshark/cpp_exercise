#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

int main()
{
    double a[10];
    for(auto i = 10; i > 0; i--){
        a[10-i] = i*1.25;
    }
    std::sort(a, a+5);
    std::ostream_iterator<double, char> out_iter(cout, " ");
    copy(a, a+8, out_iter);

    using std::istream_iterator;
    using std::ostream_iterator;
    using std::cin;
    //copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(), ostream_iterator<int, char>(cout, " "));
    copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(), a);
    copy(a, a+10, out_iter);

    /*
    for(int i = 0; i < 10; i++){
        cout<<a[i]<<endl;
    }
    */

    return 0;
}

