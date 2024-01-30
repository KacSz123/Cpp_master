#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class C_ptr
{

    int *iptr;
    float *fptr;

    void freeSpace()
    {
        delete iptr;
        delete fptr;
    }

public:
    typedef enum
    {
        VALUES,
        POINTERS
    } COUT_DATA_TYPE;
    int getIntVal() const { return *iptr; };
    float getFloatVal() const { return *fptr; };
    void setInt(int a) { *iptr = a; }
    void setFloat(float a) { *fptr = a; }
    C_ptr()
    {
        cout << " C_ptr()\n";

        iptr = new int(0);
        fptr = new float(0.0);
    }
    C_ptr(int a, float b)
    {
        cout << " C_ptr(int, float)\n";

        iptr = new int(a);
        fptr = new float(b);
    }
    // rule of 5
    C_ptr(const C_ptr &c)
    {
        cout << " C_ptr(C_ptr &)\n";
        // if(iptr!=nullptr)
        iptr = new int(c.getIntVal());
        fptr = new float(c.getFloatVal());
    }

    C_ptr(const C_ptr &&c)
    {
        cout << " C_ptr(C_ptr &&)\n";

        iptr = new int(c.getIntVal());
        fptr = new float(c.getFloatVal());
        // c.freeSpace();
    }
    C_ptr &operator=(const C_ptr &c)
    {
        cout << "operator =&\n";
        if (iptr != nullptr)
            delete iptr;
        if (fptr != nullptr)
            delete fptr;

        iptr = new int(c.getIntVal());
        fptr = new float(c.getFloatVal());
        return *this;
    }
    C_ptr &operator=(const C_ptr &&c)
    {
        cout << "operator =&&\n";
        if (iptr != nullptr)
            delete iptr;
        if (fptr != nullptr)
            delete fptr;

        iptr = new int(c.getIntVal());
        fptr = new float(c.getFloatVal());

        // c.freeSpace();
        return *this;
    }

    ~C_ptr()
    {
        cout << "~C_ptr()\n";
        if (iptr != nullptr)
            delete iptr;
        if (fptr != nullptr)
            delete fptr;
    }

    ///////////////
    C_ptr operator+(int a) const
    {
        cout << "C_ptr& operator+(int)\n";
        C_ptr tmp(*this);

        tmp.setInt((*iptr) + a);
        tmp.setFloat((*fptr) + (float)a);

        // (*iptr)+=(int)a;
        // tmp.(*fptr)+=a;

        return tmp;
    }

    C_ptr operator+(float a) const
    {

        C_ptr tmp(*this);
        cout << "C_ptr& operator+(float)\n";

        tmp.setInt((*iptr) + (int)a);
        tmp.setFloat((*fptr) + a);

        // (*iptr)+=(int)a;
        // tmp.(*fptr)+=a;

        return tmp;
    }

    void operator()(COUT_DATA_TYPE ok)
    {
        if (ok == VALUES)
            cout << "int: " << *iptr << ",  float: " << *fptr << endl;
        else if (ok == POINTERS)
            cout << "int ptr: " << iptr << ",  float ptr: " << fptr << endl;
        else
            throw("exception ! error");
    }

    void show() { cout << "--- iptr: " << *iptr << ", fptr: " << *fptr << "------\n"; }

    friend C_ptr operator+(int a, const C_ptr &c);
};

C_ptr operator+(const int a, const C_ptr &c)
{
    cout << "C_ptr& operator+(int, C_ptr)\n";

    C_ptr tmp = (c + a);
    return tmp;
}

int main(int argc, char **argv)
{

    cout << "hello world main2\n"
         << endl;
    C_ptr c1, c2{1, 4.5}, c3{1, 1};
    cout << endl;
    C_ptr c4(c2), c5(std::move(C_ptr(1, 15.69))), c6, c7;
    cout << endl;

    c6 = c1;
    c7 = C_ptr(13, 13.11);

    c1.show();
    c2.show();
    c3.show();
    c4.show();
    c5.show();
    c6.show();
    c7.show();

    cout << "\n\n + oper ------------------------\n";

    c1.show();
    c2.show();
    c1 = (c1 + 3);
    c2 = 4 + c1;

    cout << "------------------------\n";

    c1.show();
    c2.show();
    cout << "------------------------\n";
    cout << "------------------------\n";
    c1(C_ptr::VALUES);
    c1(C_ptr::POINTERS);
    // c1(15);
    return 0;
}
