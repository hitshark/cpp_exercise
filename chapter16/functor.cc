#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<double> arr1 = {1, 2, 3, 4, 5, 6};
    vector<double> arr2 = {11, 12, 13, 14, 15, 16};

    cout.setf(ios_base::fixed);
    cout.precision(1);
    for_each(arr1.begin(), arr1.end(),
            [](double x){
                cout.width(6);
                cout<<x<<" ";
            });
    cout<<endl;

    vector<double> sum;
    transform(arr1.begin(), arr1.end(), arr2.begin(), insert_iterator<vector<double>>(sum, sum.begin()), plus<double>());
    for_each(sum.begin(), sum.end(),
            [](double x){
                cout.width(6);
                cout<<x<<" ";
            });
    cout<<endl;

    vector<double> pro;
    transform(arr1.begin(), arr1.end(), insert_iterator<vector<double>>(pro,pro.begin()), bind1st(multiplies<double>(), 2.5));
    for_each(pro.begin(), pro.end(),
            [](const double x){
                cout.width(6);
                cout<<x<<" ";
            });
    cout<<endl;

    vector<double> mul;
    //binder2nd<multiplies<double>(), 3.1> f1;
    binder2nd<multiplies<double>> f1(multiplies<double>(), 3.1);
    transform(arr2.begin(), arr2.end(), insert_iterator<vector<double>>(mul, mul.begin()), f1);
    for_each(mul.begin(), mul.end(),
            [](const double x){
                cout.width(6);
                cout<<x<<" ";
            });
    cout<<endl;

    return 0;
}
