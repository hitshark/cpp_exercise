#include <iostream>
#include <string>

template<typename T>
class NoCopy {
    public:
        NoCopy(std::string & nm, const T val) : name_value(nm), object_value(val) {}
        void disp() {
            std::cout<<name_value<<std::endl;
            std::cout<<object_value<<std::endl;
        }
    private:
        std::string & name_value;
        const T object_value;
        static void view() {std::cout<<"hello\n";}

        NoCopy(const NoCopy &);
        //NoCopy & operator=(const NoCopy &);
};

class B : public NoCopy<int> {
    public:
        //void view() {NoCopy::view();}
};

class C {
    public:
        C(){}
        void print() {std::cout<<"hey girl!"<<std::endl;}
    private:
        C(const C &);
        C & operator=(const C &);
};

void global_view();

int main()
{
    std::string name("tom");
    std::string nm("erin");
    NoCopy<int> a(name, 2);
    NoCopy<int> b(nm, 3);
    //b = a;
    //b.disp();
    //NoCopy<int>::view();
    C c1;
    c1.print();
    C c2 = c1;
    c2.print();
}
