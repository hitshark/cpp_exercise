#include <iostream>
#include <string>

/*
 * @breif binary method problem
 * @details the subtype polymorphism, a serious problem,
 * take care about the difference between binary method problem and covariance of return type
 */

class Point {
    public:
        virtual bool equal(const Point* p) const = 0;
        virtual Point* print() = 0;
};

class ColorPoint : public Point {
    public:
        ColorPoint(float x, float y, std::string c) : x(x), y(y), color(c) {}
        //virtual bool equal(const ColorPoint* p) const {
        virtual bool equal(const Point* p) const {
            std::cout << "in ColorPoint equal" << std::endl;
            const ColorPoint* cp = dynamic_cast<const ColorPoint*>(p);
            std::cout << cp->color << std::endl;
            return (color == cp->color && x == cp->x && y == cp->y);
        }
        virtual ColorPoint* print() {
            return this;
        }
    public:
        float x, y;
        std::string color;
};

class NamePoint : public Point {
    public:
        NamePoint(float x, float y) : x(x), y(y) {}
        //virtual bool equal(const NamePoint* p) const {
        virtual bool equal(const Point* p) const {
            const NamePoint* cp = dynamic_cast<const NamePoint*>(p);
            if(cp == nullptr) std::cout << "nullptr" << std::endl;
            return (x == cp->x && y == cp->y);
        }
        virtual NamePoint* print() {
            return this;
        }
    public:
        float x, y;
};

void print_equal(const Point* a, const Point* b) {
    std::cout << std::boolalpha << (a->equal(b)) << std::endl;
}

template <typename T>
void print_equal2(const T* a, const T* b) {
    std::cout << std::boolalpha << (a->equal(b)) << std::endl;
}

int main(int argc, char** argv)
{
    ColorPoint* a = new ColorPoint(1.0, 2.0, "blue");
    ColorPoint* b = new ColorPoint(1.0, 2.0, "red");
    print_equal(a, b);

    NamePoint* c = new NamePoint(1.0, 2.0);
    //print_equal(a, c);
    //print_equal(c, a);

    //print_equal2(a, c);

    Point* pa = static_cast<Point*>(a);
    Point* pc = static_cast<Point*>(c);
    //print_equal2(pa, pc);

    ColorPoint* ppc = static_cast<ColorPoint*>(pc);
    std::cout << ppc->color << std::endl;

    return 0;
}
