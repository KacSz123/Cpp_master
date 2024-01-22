#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
#include<memory>
#include<thread>
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

void helloThr(void)
{
    cout<<"hello thread clb!\n";
}

int main(void)
{
    cout<<"THREADS in Cpp!\n\n";
    usleep(2000);
    cout<<" OS: "<<OS<<std::endl;
    std::thread thr(helloThr);
    // cout<<"this thr   "<<std::this_thread::get_id()<<'\n';
    cout<<"before joins let display native handle:"<<thr.native_handle() <<"\n";
    thr.join();
    cout<<"after joins let display native handle:"<<thr.native_handle() <<"\n";
    return 0;
}