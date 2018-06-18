#ifndef _STR_H_
#define _STR_H_

#include <iostream>

class String
{
    public:
        String(const char *s);
        String(const String &);
        String();
        ~String();

        int GetLen() const {return len_;}
        char GetChar(int i) const;

        //overloading operator
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i){return str_[i];};
        const char & operator[](int i) const {return str_[i];};

        // friend function
        friend bool operator<(const String &st1, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st1, const String &st2);
        friend std::ostream & operator<<(std::ostream & os, const String &st);
        friend std::istream & operator>>(std::istream & is, String &st);

        // static function
        static int HowMany();

    private:
        char *str_;
        int len_;
        static int num_strings_;
        static const int CINLIM = 80;
};


#endif
