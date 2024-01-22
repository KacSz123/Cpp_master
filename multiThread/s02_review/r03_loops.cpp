#include<iostream>
#include<vector>
using std::cout;
using std::cin;

void printIntVector(std::vector<int> vec)
{
        cout<<"VECTOR<int>: ";
        for (std::vector<int>::iterator i=vec.begin(); i!=vec.end(); i++)
        cout<<*i<<", ";
        cout<<std::endl;
}
void printIntVectorAuto(std::vector<int> vec)
{
        cout<<"VECTOR<int> auto: ";
        for (auto i=vec.begin(); i!=vec.end(); i++)
        cout<<*i<<", ";
        cout<<std::endl;
}
void printIntVectorRange(std::vector<int> vec)
{
        cout<<"VECTOR<int> range: ";
        for (auto i:vec)
        cout<<i<<", ";
        cout<<std::endl;
}
int main(void)
{

    cout<<"\n Loops!!\n";


    std::vector<int> vec{4,2,3,5,1};
    
    printIntVector(vec);
    for (std::vector<int>::iterator i=vec.begin(); i!=vec.end(); i++)
        (*i)+=2;    
    printIntVector(vec);
    
    for (auto i=vec.begin(); i!=vec.end(); i++)
        (*i)*=2;    
    printIntVectorAuto(vec);
    
    cout<<"\nrange for loops\n";
    for (auto &i:vec)
        (i)-=60;
    printIntVectorRange(vec);    

    return 0;
}