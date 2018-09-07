#include <cstring>
#include "str.hpp"

int String::num_strings_ = 0;
int String::HowMany(){return num_strings_;}

String::String(const char *s)
{
    if(s != nullptr){
        len_ = std::strlen(s);
        str_ = new char[len_+1];
        std::strcpy(str_, s);
        num_strings_++;
        std::cout<<"construction: num_strings = "<<num_strings_<<std::endl;
    }
    else{
        std::cout<<"fatal initialization\n";
        exit(-1);
    }
}

String::String(const String & st)
{
    len_ = st.len_;
    str_ = new char[len_+1];
    std::strcpy(str_, st.str_);
    num_strings_++;
    std::cout<<"construction: num_strings = "<<num_strings_<<std::endl;
}

String::~String()
{
    delete [] str_;
    num_strings_--;
    std::cout<<"de-construction: num_strings = "<<num_strings_<<std::endl;
}

String::String()
{
    len_ = 0;
    str_ = new char[len_+1];
    str_[len_] = '\0';
    num_strings_++;
    std::cout<<"construction: num_strings = "<<num_strings_<<std::endl;
}

char String::GetChar(int i) const
{
    if(i>len_){
        std::cout<<"index range error\n";
        exit(-1);
    }
    else return str_[i];
}

String & String::operator=(const String & st)
{
    if(*this == st){
        return (*this);
    }
    delete [] str_;
    len_ = st.len_;
    str_ = new char[len_+1];
    std::strcpy(str_, st.str_);

    return (*this);
}

String & String::operator=(const char *s)
{
    delete [] str_;
    len_ = std::strlen(s);
    str_ = new char[len_+1];
    std::strcpy(str_, s);

    return(*this);
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str_, st2.str_) < 0);
}
bool operator>(const String &st1, const String &st2)
{
    return (st2<st1);
}
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str_, st2.str_) == 0);
}

std::ostream & operator<<(std::ostream & os, const String &st)
{
    os<<st.len_<<std::endl;
    os<<st.str_<<std::endl;
    return os;
}
std::istream & operator>>(std::istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is) st = temp;
    while(is && is.get() != '\n') continue;
    return is;
}
