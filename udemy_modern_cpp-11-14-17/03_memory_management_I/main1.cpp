#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<memory>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

void allocateC()
{

    int *p  =  (int*)calloc(1, sizeof(int));
    *p = 5;
    cout<<"C allocate: "<<*p<<endl;
    // cout<<"hello world "<<*p<<endl;
    free(p);
    p=NULL; //without this error
    free(p);
}
void allocateCPP()
{
    int *p  =  new int(5);
    // cout<<"hello world "<<*p<<endl;
    cout<<"CPP allocate: "<<*p<<endl;

    delete p;
    p=nullptr; //without this error

}

void allocateArray()
{
    int *t = new int[5]{1,2,3,4,5};

    delete[] t;

}
void allocateString()
{
    char *s = new char[21];
    
    strcpy(s, "hello world allocate");

    cout<<s<<endl;

    delete[] s;
    s=nullptr;
    delete[] s;

}

void allocate2DArray()
{
    cout<<"2D array allocate: "<<endl;
    // tab[2][3]

    int *p1 = new int[3]{1,2,3};
    int *p2 = new int[3]{4,5,6};

    int **pData = new int*[2];

    pData[0]=p1;
    pData[1]=p2;


    cout<<"acces to dynamic 2d array[0][1]: "<<pData[0][1]<<endl;

    delete[] p1;
    delete[] p2;
    delete[] pData;
    // int *p = new int[2][3]{0,0,0},{0,0,0}};
}
int main(int argc, char** argv)
{

    allocateC();
    allocateCPP();
    allocateString();
    allocate2DArray();


    return 0;
}