#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <memory>
#include <thread>
#include <unistd.h>
#include <mutex>
using std::cout;
using std::endl;

std::mutex mt;
void helloThr(std::string str)
{

  for (int i = 0; i < 20; ++i)
  {
    mt.lock();
    cout << str[0] << str[1] << str[2] << endl;
    mt.unlock();
  }
}

int main(void)
{
  cout << "THREADS in Cpp!\n\n";
  usleep(2000);
  std::thread thr(helloThr, std::string("abc"));
  std::thread thr2(helloThr,std::string("xyz"));
  // cout<<"this thr   "<<std::this_thread::get_id()<<'\n';
  thr.join();
  thr2.join();
  return 0;
}