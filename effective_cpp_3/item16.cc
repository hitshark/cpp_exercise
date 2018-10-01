#include <iostream>
#include <memory>
#include <vector>
#include <string>

using std::cout;
using std::endl;

class Investment{
    public:
        explicit Investment(const std::string &name_, const std::vector<double> &unit_):name(name_),unit(unit_){}
        virtual void print() const {
            cout<<"name: "<<name<<endl;
            cout<<"unit: ";
            for(auto x : unit) cout<<x<<" ";
            cout<<endl;
        }
    private:
        std::string name;
        std::vector<double> unit;
};

class StackInvst : public Investment{
    public:
        explicit StackInvst(const std::string &name_, const std::vector<double> &unit_, int interest_)
            : Investment(name_, unit_),
              interest(interest_){}
        void print() const override final {
            Investment::print();
            cout<<"interest: "<<interest<<endl;
        }
    private:
        int interest;
};

struct InvestmentFactory{
    static std::shared_ptr<Investment> getInvestment(Investment *ptr) {
        return std::make_shared<Investment>(*ptr);
    }
};

// rvalue test
void test(const std::vector<int> &pr) {
    cout<<"rvalue test: ";
    for(auto x : pr) cout<<x<<" ";
    cout<<endl;
}

int main()
{
    /*
    int *pa = new int[16];
    int *pb = new int[32];
    int *pc = new int[64];

    cout<<std::hex<<reinterpret_cast<uint64_t>(pa)<<endl;
    cout<<std::hex<<reinterpret_cast<uint64_t>(pb)<<endl;
    cout<<std::hex<<reinterpret_cast<uint64_t>(pc)<<endl;
    */

    using pv = std::shared_ptr<Investment>;
    using ps = std::shared_ptr<StackInvst>;

    std::vector<double> ua{1.2, 1.7};
    std::vector<double> ub{2.4, 4.5};
    pv a(new Investment("tom", {1,2}));
    a->print();
    pv b(new StackInvst("erin", {3,4}, 10));
    b->print();

    ps c(new StackInvst("ethan", ub, 3));
    c->print();
    ps d(new Investment("berg", ua));
    d->print();

    //test({1,2,3});

    return 0;
}
