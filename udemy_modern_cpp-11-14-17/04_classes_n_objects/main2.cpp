/*!
 * @file main2.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief  DELEGATING CONTRUCTORS!
 * @version 0.1
 * @date 2024-01-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>

using std::cin;
using std::cout;
using std::endl;


class cl{

    int a;
    int b;
    char c;
    public:
    cl():a{0},b{0}, c{'A'}{}
    cl(int aa)
    {
        a = aa;
        b = 0;
        c  = 'P';
    }
    cl(int aa, int bb):cl(aa)
    {
        // cl()
        b = bb;
    }
    ~cl(){}

    void show(){
        cout<<"a "<<a<<", b: "<<b<<", c: "<<c<<endl;
    }
};

int main(int argc, char** argv)
{

    cout<<"hello world"<<endl;

    cl a1, a2(1), a3(2,2);

    a1.show();
    a2.show();
    a3.show();
    return 0;
}
