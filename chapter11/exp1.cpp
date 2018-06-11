#include <iostream>
#include "exp1.hpp"

Time::Time():hours_m(0),minutes_m(0){}
Time::Time(int h, int m):hours_m(h),minutes_m(m){}
void Time::AddMin(int m){minutes_m += m;}
void Time::AddHr(int h){hours_m += h;}
void Time::Reset(int h, int m){minutes_m = m; hours_m = h;}
Time Time::Sum(const Time &t) const
{
    Time tmp;
    tmp.minutes_m = minutes_m + t.minutes_m;
    tmp.hours_m = hours_m + t.hours_m + tmp.minutes_m/60;
    tmp.minutes_m = tmp.minutes_m % 60;
    return tmp;
}
Time Time::operator+(const Time &t) const
{
    Time tmp;
    tmp.minutes_m = minutes_m + t.minutes_m;
    tmp.hours_m = hours_m + t.hours_m + tmp.minutes_m/60;
    tmp.minutes_m = tmp.minutes_m % 60;
    return tmp;
}
Time Time::operator*(double mult) const
{
    Time tmp;
    tmp.minutes_m = hours_m * 60 * mult + minutes_m * mult;
    tmp.hours_m = tmp.minutes_m / 60;
    tmp.minutes_m = tmp.minutes_m % 60;
    return tmp;
}
void Time::Show() const
{
    std::cout<<hours_m<<":"<<minutes_m<<std::endl;
}

/*
Time operator*(double mult, const Time &t)
{
    Time tmp;
    tmp.minutes_m = t.hours_m * 60 * mult + t.minutes_m * mult;
    tmp.hours_m = tmp.minutes_m / 60;
    tmp.minutes_m = tmp.minutes_m % 60;
    return tmp;

}
*/
Time operator*(double mult, const Time &t)
{
    return (t*mult);
}


// vector
#include <cmath>

namespace VECTOR{

    Vector::Vector(){}
    Vector::Vector(double x, double y, char mode):
        x_(x),
        y_(y),
        mode_(mode)
    {
        std::cout<<"vector constructed!"<<std::endl;
    }

    void Vector::set(double x, double y, char mode)
    {
        x_ = x;
        y_ = y;
        mode_ = mode;
    }

    double Vector::get_mgt() const{ return std::sqrt(x_*x_ + y_*y_); }
    double Vector::get_ang() const
    {
        if(x_ == 0 || y_ == 0) return 0;
        else return std::atan2(y_,x_);
    }

    Vector Vector::operator+(const Vector &t) const{ return Vector(x_+t.x_, y_+t.y_); }
    Vector Vector::operator-(const Vector &t) const{ return Vector(x_-t.x_, y_-t.y_); }
    Vector Vector::operator-() const{ return Vector(-x_,-y_); }
    Vector Vector::operator*(double scale) const{ return Vector(x_*scale, y_*scale); }

    Vector operator*(double scale, const Vector &t)
    {
        return Vector(t.x_*scale, t.y_*scale);
    }

    std::ostream& operator<<(std::ostream &os, const Vector &t)
    {
        //os<<t.x_<<" "<<t.y_<<std::endl;
        os<<t.get_mode()<<" "<<t.get_mgt()<<" "<<t.get_ang()<<std::endl;
        return os;
    }

    /*
    std::ostream& operator<<(std::ostream &os, const Vector &t)
    {
        os<<t.get_mode()<<" "<<t.get_mgt()<<" "<<t.get_ang()<<std::endl;
        return os;
    }
    */
}
