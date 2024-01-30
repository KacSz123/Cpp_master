#include<iostream>
/*!
 * @brief MOvE semantics
 * 
 */
using std::cin;
using std::cout;
using std::endl;

int Add(int x, int y)
{
    return x+y;
}

int& Transform(int &x)
{
    x*=x;
    return x;

}

void Print(int &x) //lvalue ref
{
    cout<<"Print(int&): "<<x<<endl;
}
void Print(const int &x) //const lval
{
    cout<<"Print(const int&): "<<x<<endl;
}
void Print(int &&x)
{
    cout<<"Print(int&&): "<<x<<endl;
}
int main(int argc, char** argv)
{

    cout<<"hello world main2!!"<<endl<<endl;
    const auto y{12};
    auto x{10};

    Print(x);
    Print(y);
    Print(5);

    return 0;
}
