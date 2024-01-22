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
int x{0};
void helloThr()
{
    
    for (int i=0; i<100000; ++i)
    x++;
}

int main(void)
{

    cout<<" OS: "<<OS<<std::endl;
    std::vector<std::thread> tasks;
    tasks.push_back(std::thread{helloThr});
    tasks.push_back(std::thread{helloThr});
    sleep(2);
    for(auto&t : tasks) t.join();


    cout<<"result!: "<<x <<" \n";
    return 0;
}