#include <memory>
#include <vector>
#include <iostream>

class Item{
    private:
        struct Point{
            Point(){}
            Point(int x_, int y_) : x(x_), y(y_){}
            int x;
            int y;
        };
    public:
        Item(){}
        Item(int sx, int sy, int ex, int ey) : start(Point(sx,sy)), end(Point(ex,ey)){}
        void setStart(int x, int y) {start = Point(x,y);}
        void setEnd(int x, int y) {end = Point(x,y);}
        void disp() const {
            std::cout<<"start: ("<<start.x<<","<<start.y<<")"<<std::endl;
            std::cout<<"end: ("<<end.x<<","<<end.y<<")"<<std::endl;
        }
    private:
        Point start, end;
};

struct Elem{
    std::shared_ptr<Item> pitem;
    std::string tag;
};

class ElemHandle{
    public:
        ElemHandle(const std::string &tag, const Item &t) {
            pelem = std::make_shared<Elem>();
            pelem->pitem = std::make_shared<Item>(t);
            pelem->tag = tag;
        }
        //copy and swap, exception-safety
        void updateItem(const std::string &tag, const Item &item) {
            using std::swap;
            if(tag == pelem->tag){
                std::shared_ptr<Elem> tmp(pelem);
                tmp->pitem.reset(new Item(item));
                swap(pelem, tmp);
            }
        }
        void disp(){pelem->pitem->disp();}
    private:
        std::shared_ptr<Elem> pelem;
};

int main()
{
    std::shared_ptr<Item> pi = std::make_shared<Item>();
    pi->setStart(1,2);
    pi->setEnd(3,4);
    pi->disp();

    ElemHandle a("tom", *pi);
    a.disp();
    a.updateItem("tom", Item(22,41,42,53));
    a.disp();

    return 0;
}
