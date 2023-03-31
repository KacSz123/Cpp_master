#include<iostream>

/**
 * @file file includes example of overload of operator << >>  
 *      
 * 
 * 
 * 
*/
struct LZespolona {double re, im;};
struct Vector3d {double vec[3];};
struct Matrix3x4 {double matrix[3][3];};
std::istream& operator >> (std::istream& istrm, LZespolona& arg)
{
    std::cout<<"Podaj czesc re: ";
    istrm>>arg.re;
    std::cout<<"Podaj czesc im: ";
    istrm>>arg.im;

    return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, LZespolona arg)
{
    if(arg.im>0)
    ostrm<<arg.re<<"+"<<arg.im<<"j"<<std::endl;
    else if(arg.im<0)
    ostrm<<arg.re<<arg.im<<"j"<<std::endl;
    else
    ostrm<<arg.re<<std::endl;
    return ostrm;
}
int main()
{
    LZespolona lz1, lz2, lz3;
    lz1.re =15;
    lz1.im =1.1;
    lz2.re =-5;
    lz2.im =2.1;
    lz3.re =2;
    lz3.im =0;
    std::cout<<lz1;
    std::cout<<lz2;
    std::cout<<lz3;
    std::cin>>lz3;
    std::cout<<lz3;

}