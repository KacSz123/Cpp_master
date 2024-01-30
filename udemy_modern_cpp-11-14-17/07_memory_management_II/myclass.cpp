#include "myclass.hh"


C_ptr operator+(const int a, const C_ptr &c)
{
    cout << "C_ptr& operator+(int, C_ptr)\n";

    C_ptr tmp = (c + a);
    return tmp;
}
void MYPTR_CreateC_ptr()
{
    // std::unique_ptr<C_ptr> c1;
    myPtrC c1 = new C_ptr(1123,11123);
    c1->show();
    c1.show();
    (*c1)(C_ptr::VALUES);
    (*c1)(C_ptr::POINTERS);
}
void CreateC_ptr()
{
    // std::unique_ptr<C_ptr> c1;
    std::unique_ptr<C_ptr> c1(new C_ptr(123,431.1111));
    c1->show();
    // c1.show();
    (*c1)(C_ptr::VALUES);
    // (*c1)(C_ptr::POINTERS);

    int a =   static_cast<int>(*c1);
    // int x =   *c1; // error implicit not allowed
    float b = static_cast<float>(*c1);

    cout<<"cast to int: "<<a<<endl;
    cout<<"cast to float: "<<b<<endl;
}