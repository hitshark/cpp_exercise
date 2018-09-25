#include <iostream>
#include <memory>

int main()
{
    using dptr = std::auto_ptr<double>;
    //using dptr = std::shared_ptr<double>;
    //using dptr = std::unique_ptr<double>;
    dptr pa;
    dptr pd(new double);
    pa = pd;
    *pa = 10;
    std::cout<<*pa<<std::endl;
    //*pd = 20;
    //std::cout<<*pd<<std::endl;

    using sptr = std::unique_ptr<std::string>;
    sptr ta(new std::string("hello world"));
    sptr tb = sptr(new std::string("hehe"));
    sptr tc = std::move(tb);
    std::cout<<*ta<<std::endl;

    std::unique_ptr<double[]> da;
    const double db[] = {1,2,3};
    da = std::unique_ptr<double[]>(new double[5]);
    da[0] = 100;
    std::cout<<da[0]<<std::endl;

    std::string sa{"hello"};
    std::shared_ptr<std::string> sd = std::make_shared<std::string>();
    *sd = "xixi";
    std::cout<<*sd<<std::endl;
    std::cout<<sa<<std::endl;

    return 0;
}
