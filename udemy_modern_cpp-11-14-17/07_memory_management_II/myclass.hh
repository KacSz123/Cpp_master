/////// smart pointers!!
#pragma once
#include<iostream>
#include<memory>
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
        cout << " constr C_ptr(int, float)\n";

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

    void show() { cout << "C_ptr:::--- iptr: " << *iptr << ", fptr: " << *fptr << "------\n"; }

    friend C_ptr operator+(int a, const C_ptr &c);

    explicit operator int(){return *iptr;}
    explicit operator float(){return *fptr;}
};

C_ptr operator+(const int a, const C_ptr &c);
////////////////////////////////////////////////////////////////////////////////
                                                        ////////////////////////////////////////////////////////////////////////////////
                                                        ////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class myPtrC
{
    C_ptr *ptr=nullptr;
    public: 
    myPtrC(){}
    myPtrC(C_ptr *c):ptr{c}{cout<<"pointer to C_ptr\n";};

    ~myPtrC(){cout<<" dest pointer to C_ptr\n";delete ptr;}

    C_ptr* operator->(){return ptr;}
    C_ptr& operator*(){return *ptr;};
    void show(){cout<<"co to za czary:::"; ptr->show();}
};
void CreateC_ptr();



void MYPTR_CreateC_ptr();