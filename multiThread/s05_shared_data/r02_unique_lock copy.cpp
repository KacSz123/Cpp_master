#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <memory>
#include <thread>
#include <unistd.h>
#include <mutex>
// #include<liter
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

void task(std::string str)
{
  using namespace std::literals;
  for(int i=0; i<5;++i)
  {
    std::unique_lock<std::mutex> ulck(mt);
    for(long unsigned int j=0; j<str.size(); ++j)
    cout<<str[j];
    cout<<endl;
    ulck.unlock();
    std::this_thread::sleep_for(75ms);
  }
}

int main(void)
{
  cout << "THREADS in Cpp!\n\n";
  usleep(2000);
  std::thread thr(task, std::string("abcccaaaaa"));
  std::thread thr2(task,std::string("xyzzzyyyyyzz"));
  // cout<<"this thr   "<<std::this_thread::get_id()<<'\n';
  thr.join();
  thr2.join();
  return 0;
}