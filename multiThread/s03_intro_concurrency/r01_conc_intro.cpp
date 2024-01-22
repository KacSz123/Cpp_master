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
    cout<<"hello thread!\n";
    sleep(3);
    cout<<"hello thread!\n";
}

void helloThr2(void)
{
      for(int i=0; i<5; ++i)
    {
      std::cout<<i<<std::endl;
      sleep(2);
    }
}

const std::vector<std::string> names = {"Tommy", "Anie", "Casper", "Mark"};
void fizzbuzz(const std::vector<std::string> names, const int &counter)
{

  for(int i=1; i<=counter; ++i)
  {
    if(i%3==0 && i%5==0)
    std::cout<<names[i%names.size()]<<" says fizzbuzz\n";
    else if(i%3==0 && i%5!=0)
    std::cout<<names[i%names.size()]<<" says fizz\n";
    else if(i%3!=0 && i%5==0)
    std::cout<<names[i%names.size()]<<" says buzz\n";
    else
    std::cout<<names[i%names.size()]<<" says "<<i<<std::endl;
  }

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
    std::thread thr(helloThr);
    std::thread thr2(helloThr4);
    std::thread thr3([](){
                            for(int i=0; i<10; ++i)
                          {
                            std::cout<<7-i<<std::endl;
                            sleep(1);
                          }
                        });
    Hello h1;
    std::thread thr4(h1);

    cout<<"before joins\n";
    thr.join();
    thr2.join();
    thr3.join();
    thr4.join();
    return 0;
}