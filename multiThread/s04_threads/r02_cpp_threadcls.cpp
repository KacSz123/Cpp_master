#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include<memory>
#include<thread>
#include<chrono>
#include<functional>
using std::cout;
using std::cin;
#if __linux__
  #define OS "LIN" 
  #include<stdlib.h>
  #include<unistd.h>
#elif (_WIN32 || _WIN64)
  #define OS "WIN"
  #include<windows.h>
  #include <thread>
#else
  #define OS "OTHER"
#endif

void helloThr(int &x)
{
    
    for (int i =0; i<4; ++i){
    ++x;
    cout<<"hello thread clb1! "<<x<<" \n";
    usleep(10000);}
}
void helloThr2(int &x)
{
    
    for (int i =0; i<4; ++i){
    ++x;
    cout<<"hello thread clb2! "<<x<<" \n";
    usleep(10000);}
}

int main(void)
{
    cout<<"THREADS in Cpp!\n\n";
    usleep(2000);

    int x{5};
    cout<<" OS: "<<OS<<std::endl;
    std::thread thr(helloThr,std::ref(x));
    std::thread thr2(helloThr2,std::ref(x));
    thr.join();
    thr2.join();
    return 0;
}