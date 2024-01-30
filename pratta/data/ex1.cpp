#include<iostream>
//#include <cfloat>
const float inch = 2.54;
const float foot  = 30.48;
int main(void)
{
    short height;
    std::cout<<"Enter your height in cm:";
    std::cin>>height;
    std::cout<<"You are "<< height <<"cm tall.\n";
    std::cout<<"Your height is also "<<height/inch<<" inches or "<< height/foot<<" feets.\n";
    return 0;
}