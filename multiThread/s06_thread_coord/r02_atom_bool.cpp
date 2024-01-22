#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <memory>
#include <thread>
#include <unistd.h>
#include <mutex>
#include<atomic>

using std::cout;
using std::endl;


std::atomic_flag lock_cout = ATOMIC_FLAG_INIT;
std::atomic<int> x = 3;
std::mutex mt;
void helloThr(std::string str)
{
  using namespace std::literals;
  for (int i = 0; i < 30; ++i)
  {
  while(lock_cout.test_and_set()){};
      std::cout<<str<<"\n";
      lock_cout.clear();
      std::this_thread::sleep_for(50ms);
  }
}

void intThr(int a)
{
  while(lock_cout.test_and_set()){};

  x = a;

  cout<<x<<'\n';
  lock_cout.clear();
}

int main(void)
{
  cout << "THREADS in Cpp!\n\n";
  usleep(2000);
  // std::thread thr(helloThr, std::string("aaa aaa aaa aaa aaa aaa aaa aaa aaa aaa "));
  // std::thread thr2(helloThr,std::string("                                        "));
  

  // thr.join();
  // thr2.join();
 std::vector<std::thread> thr;

 for(int i=0; i<20; i+=2)
 {
  thr.push_back(std::thread(intThr,i));
 }
 

  for(auto& t:thr)
  t.join();
  return 0;
}