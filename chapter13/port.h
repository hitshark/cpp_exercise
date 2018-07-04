#include <iostream>

class Port
{
    public:
        Port(const char *br = "none", const char *st = "none", int b = 0);
        Port(const Port & p);
        virtual ~Port(){delete [] brand_;}
        Port & operator=(const Port & p);
        Port & operator+=(int b);
        Port & operator-=(int b);

        int BottleCount() const {return bottles_;}
        virtual void Show() const;
        friend std::ostream & operator<<(std::ostream & os, const Port & p);

    private:
        enum {STYLE_NUM = 20};
        char *brand_;
        char style_[STYLE_NUM];
        int bottles_;
};

class VintagePort : public Port
{
    public:
        VintagePort();
        VintagePort(const char *br, const char *st, int b, const char *nn, int y);
        VintagePort(const VintagePort & vp);
        ~VintagePort(){delete [] nickname_;}
        VintagePort & operator=(const VintagePort & vp);

        void Show() const;
        friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);

    private:
        char *nickname_;
        int year_;
};
