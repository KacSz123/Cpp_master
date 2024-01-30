#include<iostream>

using std::cin;
using std::cout;
using std::endl;


// l-value (ref to var)
int& lval(int &a)
{
    return a +=5;

}


//r-value
int rval()
{
    int b;
    return b+5;
}

//r-val reference (&&5)
int&& rval(int&& a)
{
    return a+5;
}


int main(int argc, char** argv)
{

    int x = 5;
    cout<<"hello world main1.cpp file"<<endl;

    cout<<"\n rval return with 5: "<<lval(x)+5<<endl;


    cout<<"x: "<<x<<endl;

    return 0;
}
