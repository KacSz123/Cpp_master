#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class C
{

    private:
        int a;
        int b;
        // char name[20];

    protected:
    public:

    C():a{0},b{0}{};
    C(int aa, int bb):a{aa},b{bb}{}
    C(const C &tmp):C(tmp.getA(), tmp.getB()){};

    ~C()=default;
    // getter

    int getA()const{return a;}
    int getB()const{return b;}
    // const char* getName()const{return this->name;}
    // setter
    void setA(int a){this->a=a;}    
    void setB(int a){b=a;}

    void show(){cout<<"a: "<<a<<", b: "<<b<<endl;};
    // OPERATORS HHAHAHAHAHA
    C& operator =(const C& aa){this->a = aa.getA(); this->b = aa.getB(); return *this;}
    C& operator =(const C&& aa){this->a = aa.getA(); this->b = aa.getB(); return *this;}
    C& operator+=(const C& aa)
    {
        this->a +=aa.getA(); 
        this->b +=aa.getB(); 


        return *this;
    }
    C& operator+(const C&bb )
    {
        this->a+=bb.getA();
        this->b+=bb.getB();

        return *this;
    }
    C& operator+(const int &a )
    {
        this->a+=a;
        this->b+=a;

        return *this;
    }
    C& operator++()
    {
        ++a;
        ++b;
        return *this;
    }
    C operator++(int)
    {
        C temp(*this);
        ++a;
        ++b;
        return temp;
    }

};

int main(int argc, char **argv)
{

    cout << "hello world" << endl;
    C a{1,2}, b{3,3};
    a.show();b.show();

    a = b;

    b = b+b;
    cout<<"\n---------------\n\n";
    cout<<"Obj-a ";
    a.show();

    cout<<"Obj-b ";
    b.show();
    b=b+23;
    cout<<"Obj-b ";
    b.show();
    ++b;
    cout<<"Obj-b ";
    b.show();

    b++;
    cout<<"Obj-b ";
    b.show();

    return 0;
}
