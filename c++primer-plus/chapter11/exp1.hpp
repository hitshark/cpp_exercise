#ifndef _EXP1_H_
#define _EXP1_H_

#include <iostream>

class Time
{
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0, int m=0);
    Time Sum(const Time &t) const;
    Time operator+(const Time &t) const;
    Time operator*(double mult) const;
    void Show() const;
//public:
private:
    friend Time operator*(double mult, const Time &t);

private:
    int hours_m;
    int minutes_m;
};

namespace VECTOR{

    const double R2D = 57.29577;

    class Vector{
    public:
        Vector();
        Vector(double x, double y, char mode='r');
        void set(double x, double y, char mode);
        char get_mode() const { return mode_; }
        double get_mgt() const;
        double get_ang() const;

        // operator overloading
        Vector operator+(const Vector &t) const;
        Vector operator-(const Vector &t) const;
        Vector operator-() const;
        Vector operator*(double scale) const;

        // friend functions
        friend Vector operator*(double scale, const Vector &t);
        //friend std::ostream& operator<<(std::ostream &os, const Vector &t);

    private:
        double x_;
        double y_;
        char mode_;
    };

    std::ostream& operator<<(std::ostream &os, const Vector &t);

} // end namespace VECTOR

#endif

