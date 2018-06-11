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
