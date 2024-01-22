#include<iostream>
#include<chrono>



using std::cout;
using std::cin;
using namespace std::literals;
namespace sc = std::chrono;

int main(void)
{

    cout<<"\nChrono review!\n\n";
    cout<<"c++11 syntax\n";
    cout<<"seconds! \n";
    sc::seconds(2);
    cout<<"miliseconds! \n";
    sc::milliseconds(20);
    cout<<"microseconds! \n";
    sc::microseconds(50);
    cout<<"c++14 syntax\n";
    cout<<"seconds! \n";
    2s;
    cout<<"miliseconds! \n";
    20ms;
    cout<<"microseconds! \n";
    50us;


    cout<<"end!\n\n";
    
    // cout<<"s: "<<sc::seconds(2)<<", ms: "<<sc::milliseconds(23)<<", \nmu: "<<
    // sc::microseconds(30)<<"\n";


    return 0;
}