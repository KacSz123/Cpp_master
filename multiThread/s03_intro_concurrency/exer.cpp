// #include
#include<iostream>
#include<vector>
#include<thread>
#include<string>
// #include<>





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

int main()
{
    const std::vector<std::string> names = {"Tommy", "Anie", "Casper", "Mark"};

    std::thread ex1(fizzbuzz,names,15);

    ex1.join();
    return 0;
}