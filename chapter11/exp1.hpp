#ifndef _EXP1_H_
#define _EXP1_H_

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

#endif

