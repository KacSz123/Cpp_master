#include <iostream>
struct LZespolona {double re, im;};
LZespolona operator + (LZespolona Arg1, LZespolona Arg2)
{
    LZespolona wynik;
    wynik.re = Arg1.re+Arg2.re;
    wynik.im = Arg1.im+Arg2.im;
    return wynik;
}
LZespolona& operator += (LZespolona &Arg1, LZespolona Arg2)
{
    return Arg1=Arg1+Arg2;
}
// LZespolona& operator -= (LZespolona &Arg1, LZespolona Arg2)
// {
//     return Arg1=Arg1-Arg2;
// }

int main()
{
    LZespolona arg1{3,1.4},arg2{1,0.4};
    arg1+=arg2+=arg2;
    
    std::cout<<"arg1: "<<arg1.re<<"  "<<arg1.im<<std::endl;
    std::cout<<"arg2: "<<arg2.re<<"  "<<arg2.im<<std::endl;
}