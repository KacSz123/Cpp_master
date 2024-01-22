#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include<memory>
#include<thread>
#include<thread>
#include<chrono>
using std::cout;
using std::cin;
#if __linux__
  #define OS "LIN"
  #include<system.h>    
  #include<stdlib.h>
#elif (_WIN32 || _WIN64)
  #define OS "WIN"
  #include<windows.h>
  #include <thread>
#else
  #define OS "OTHER"
#endif

void helloThr(void)
{
    cout<<"hello thread!\n";
}

// std::make_ ad;
// std::_Mutex_base
// 
int main(void)
{
    cout<<"THREADS in Cpp!\n\n";
    Sleep(2000);
    cout<<" OS: "<<OS<<std::endl;
    //  std::thread jt( [] () { std::cout << "test\n"; } );
    std::thread thr(helloThr);
    return 0;
}