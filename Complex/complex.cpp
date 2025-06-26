#include "complex.hpp"
using namespace std;
    
cmplx::cmplx()
{
    real=0;
    img=0;
}

void cmplx::display()    //for print the complex  no.
{
cout << real << "+" << img <<"i"<<endl;
}

cmplx cmplx::add (cmplx y)  
{
    cmplx c;
    c.real = this->real + y.real;  //to get the real part
    c.img = this->img + y.img;  //to get the img part
    return c;
}

cmplx cmplx::sub (cmplx y)  
{
    cmplx c;
    c.real = this->real - y.real;  //to get the real part
    c.img = this->img - y.img;  //to get the img part
    return c;
}
