#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <memory>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <shared_mutex>
// #include<liter
using std::cout;
using std::endl;

std::shared_mutex mt;

int x = 0;
void writer()
{
  using namespace std::literals;
  for(int i=0; i<5;++i)
  {
    std::lock_guard lck_g(mt);
    cout<<"1\n";
    ++x; 
    std::this_thread::sleep_for(100ms);

  }
}

void reader()
{
    std::shared_lock lck_g(mt);
    using namespace std::literals;
    cout<<x<<"\n";
    std::this_thread::sleep_for(100ms);
}
int main(void)
{
  cout << "multi readers in Cpp!\n\n";
  usleep(2000);

  std::vector<std::thread> thrs;
  for(int i=0; i<20; ++i)
  thrs.push_back(std::thread(reader));
  // cout<<"this thr   "<<std::this_thread::get_id()<<'\n';



  usleep(300);
  thrs.push_back(std::thread(writer));
  thrs.push_back(std::thread(writer));
  usleep(300);



  for(int i=0; i<20; ++i)
  thrs.push_back(std::thread(reader));

  for(auto& i:thrs)
    i.join();
  return 0;
}