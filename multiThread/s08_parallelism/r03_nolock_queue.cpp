
// Simple producer and consumer program using same queue.
// Producer puts data in queue; consumer uses that data.
//
//  producer & consumer never use the same element of q.
//  Only producer can change q.
//
//
//




#include <iostream>
#include <string>
#include <vector>
#include <list>
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
template<typename T>
class LockFreeQ
{
  std::list<T> list;
  typename std::list<T>::iterator iHead, iTail;

  public:
  LockFreeQ()
  {
    list.push_back(T());
    iHead = list.begin();
    iTail = list.end();

    // cout<<"beg: "<<iHead<<", end: "<<iTail;
  }

  bool consume(T& t)
  {
    auto iF = iHead; //zm poom
    ++iF; // przejscie po iteratorze
    if(iF!=iTail) //jesli to nie koniec
    {
      iHead = iF;
      t = *iHead; // przesuniecie glowy
      return true;
    }
    return false;
  }

  void produce(const T& t)
  {
    list.push_back(t); //dodanie do listy
    iTail = list.end(); // ogon na koniec
    list.erase(list.begin(), iHead); //usuniecie przed glowa
  }

  void Print()
  {
    auto head = iHead;
    // ++head;
    for(auto el = (++head); el!=iTail; ++el)
    cout<<*el<<", ";
    cout<<endl;    
  }
};



int main(void)
{
  cout << "THREADS in Cpp!\n\n";
  usleep(2000);

  LockFreeQ<int> l;
  std::vector<std::thread> thr;

  int j{1};
  
  for(int i{0}; i<10; ++i)
  {
    /*
     * non thr program 
     * 
     * l.produce(i);
     * l.consume(j);
     */
    std::thread produce(&LockFreeQ<int>::produce, &l, std::ref(i));
    thr.push_back(std::move(produce));
    std::thread consume(&LockFreeQ<int>::consume, &l, std::ref(j));
    thr.push_back(std::move(consume));


  }

  for(auto& t:thr)
    t.join();


  l.Print();
  return 0;
} 