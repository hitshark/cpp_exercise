#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*
    char *st = "test";
    string a(st);
    cout<<a;
    string b(st, st+1);
    cout<<std::endl;
    cout<<b;
    string c(b);
    cout<<std::endl;
    cout<<c;
    cout<<std::endl;
    cout<<"hello world";
    string e(a, 2);
    cout<<std::endl<<e;
    string f(a, 1, 3);
    cout<<std::endl<<f;
    cout<<std::endl;
    b = a + c;
    cout<<std::endl<<b;
    */

    // input method for string object
    string ta;
    //cin>>ta;
    //cout<<ta<<endl;
    //getline(cin, ta);
    //cout<<ta<<endl;
    //getline(cin, ta, ':');
    //cout<<ta<<endl;

    // input method for C-style string
    /*
    char ch[100];
    cin>>ch;
    cout << ch <<endl;
    cin.getline(ch, 20);
    cout << ch <<endl;
    cin.get(ch, 20);
    cout << ch <<endl;
    //cin.getline(ch, 20);
    cin.getline(ch, 30, ':');
    cout<< ch<<endl;
    cout<<string::npos<<endl;
    */

    // string method
    string tb("hello hello");
    cout<<tb.length()<<":"<<tb.size()<<endl;
    cout<<tb.find("hello")<<endl;
    cout<<tb.rfind("hello")<<endl;
    cout<<tb.find_first_of("wo")<<endl;
    cout<<tb.find_first_not_of("wo")<<endl;
    cout<<tb.find_last_of("hel")<<endl;
    cout<<tb.find_last_not_of("hel")<<endl;

    tb[2] = 'c';
    cout<<tb<<endl;
    cout<<tb[2]<<endl;
    cout<<tb.capacity()<<endl;

    string tc;
    cout<<tc.capacity()<<endl;


    return 0;
}
