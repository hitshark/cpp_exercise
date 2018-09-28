#include <iostream>
#include <string>
#include <vector>

class Transaction {
    public:
        explicit Transaction(const std::string & log) {
            logTransaction(log);
        }
        void logTransaction(const std::string & log) {
            std::cout<<log<<std::endl;
        }
};

class BuyTransaction : public Transaction{
    public:
        BuyTransaction():Transaction(getLogString()){}
        void setPrice(const std::vector<int> & pri) {count = pri;}
    private:
        std::vector<int> price;
        static std::vector<int> count;
        static std::string getLogString() {
            std::string temp;
            for(auto x : count) temp.push_back(static_cast<char>(x));
            return temp;
        }
};

std::vector<int> BuyTransaction::count = {0x41,0x42,0x43,0x44};

int main()
{
    BuyTransaction tr;
    return 0;
}
