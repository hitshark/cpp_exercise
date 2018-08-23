#include <iostream>
#include <iterator>
#include <vector>

class A {
    private:
        enum { SIZE = 10 };
        char name[SIZE];
        static const int Size = 10;
        int score[Size];
        mutable int length;
    public:
        A(){strcpy(name, "hello");}
        void set(int index){ score[index] = 1; }
        int get(int index){ return score[index]; }

        const char & operator[](int index) const {
            return name[index];
        }
        char & operator[](int index) {
            return (const_cast<char &> (static_cast<const A &>(*this)[index]));
        }

        int getLength() const {
            length = strlen(name);
            return length;
        }
};

int main()
{
    const A a;
    //a.set(0);
    //std::cout<<a.get(0)<<std::endl;
    std::cout<<a[0]<<std::endl;
    std::cout<<a.getLength()<<std::endl;

    std::vector<int> vec{1,2,3};
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 10;
    iter++;
    std::vector<int>::const_iterator cIter = vec.begin();
    *cIter = 11;
    ++cIter;

    return 0;
}
