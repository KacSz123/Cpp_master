#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>


using std::cout;
using std::cin;
void showType(int a)
{
    cout<<"int type\n";
    cout<<typeid(a).name()<<"\n";
}

void showType(int *a)
{
    cout<<"ptr int type\n";
    cout<<typeid(a).name()<<"\n";
}

int main(void)
{
    int x{7};
    double y{7.7};
    std::string str{"Let us begin!"};
    std::vector<int> vec{4,2,3,5,1};
    cout<<"VECTOR<int>: ";
    for (std::vector<int>::iterator i=vec.begin(); i!=vec.end(); i++)
        cout<<*i<<", ";
    cout<<"\ninitiated vals: x="
    <<x<<", y="<<y<<", str=\""<<str<<"\""<<std::endl;
    cout<<"\n----------------------------------\n";
    showType(NULL);
    showType(nullptr);
    cout<<"\n----------------------------------\n";

    return 0;
}