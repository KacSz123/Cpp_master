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

void helloThr(std::string str)
{
    cout<<str<<"\n";
}
void helloThr1(std::string &str)
{
    cout<<str<<"\n";
    str = "123412aosnfoasi";
    cout<<str<<"\n";
}

void helloThr2(std::string &&str)
{
    cout<<str<<"\n";
}

class Hello
{
  public:
  void operator()(){std::cout<<"Hello functor, thread!\n";};
};
std::function<void (void)> helloThr4 = []()->void{
    cout<<"hello lambda thread!\n";};
// std::make_ ad;
// std::_Mutex_base
// 
int main(void)
{
    cout<<"THREADS in Cpp!\n\n";
    usleep(2000);
    cout<<" OS: "<<OS<<std::endl;
    //  std::thread jt( [] () { std::cout << "test\n"; } );
    std::string str = "hello with copy!\n";
    std::thread thr(helloThr,  str);

    std::string str2 = "hello with move!\n";
    str = "hello with ref!\n";

    std::thread thr2(helloThr2, std::move(str2));
    std::thread thr3(helloThr1, std::ref(str));

    cout<<"before joins\n";
    thr.join();
    thr2.join();
    thr3.join();

    if(str2.empty())
    std::cout<<"str2 is not my data!\n";
    else
    std::cout<<"str2 is my data!\n";

    return 0;
}