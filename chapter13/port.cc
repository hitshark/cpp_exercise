#include <string>
#include <glog/logging.h>
#include "port.h"

Port::Port(const char *br, const char *st, int b)
{
    int len = strlen(br);
    brand_ = new char[len+1];
    strcpy(brand_, br);
    brand_[len] = '\0';

    len = strlen(st);
    CHECK(len <= STYLE_NUM) <<"style parameter exceed the range\n";
    strcpy(style_, st);

    bottles_ = b;
}

Port::Port(const Port & p)
{
    int len = strlen(p.brand_);
    brand_ = new char[len+1];
    strcpy(brand_, p.brand_);
    brand_[len] = '\0';

    strcpy(style_, p.style_);
    bottles_ = p.bottles_;
}

Port & Port::operator=(const Port & p)
{
    if(this == &p) return *this;

    delete [] brand_;
    int len = strlen(p.brand_);
    brand_ = new char[len+1];
    strcpy(brand_, p.brand_);
    brand_[len] = '\0';

    strcpy(style_, p.style_);
    bottles_ = p.bottles_;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles_ += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    CHECK(bottles_ >= b) << "not enough bottles to provide\n";
    bottles_-= b;
    return *this;
}

void Port::Show() const
{
    LOG(INFO) << brand_ << std::endl;
    LOG(INFO) << style_ << std::endl;
    LOG(INFO) << bottles_ <<std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
    os << p.brand_ << std::endl;
    os << p.style_ << std::endl;
    os << p.bottles_ << std::endl;
    return os;
}

VintagePort::VintagePort()
{
    nickname_ = new char[1];
    nickname_[0] = '\0';
    year_ = 0;
}

VintagePort::VintagePort(const char *br, const char *st, int b, const char *nn, int y)
: Port(br, st, b), year_(y)
{
    int len = strlen(nn);
    nickname_ = new char[len+1];
    strcpy(nickname_, nn);
    nickname_[len] = '\0';
}

VintagePort::VintagePort(const VintagePort & vp)
: Port(vp), year_(vp.year_)
{
    int len = strlen(vp.nickname_);
    nickname_ = new char[len+1];
    strcpy(nickname_, vp.nickname_);
    nickname_[len] = '\0';
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp) return *this;

    Port::operator=(vp);
    delete [] nickname_;
    int len = strlen(vp.nickname_);
    nickname_ = new char[len+1];
    strcpy(nickname_, vp.nickname_);
    nickname_[len] = '\0';

    year_ = vp.year_;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    LOG(INFO) << nickname_ <<std::endl;
    LOG(INFO) << year_ <<std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
    os<<((const Port &)(vp));
    os << vp.nickname_ << std::endl;
    os << vp.year_ << std::endl;
    return os;
}

