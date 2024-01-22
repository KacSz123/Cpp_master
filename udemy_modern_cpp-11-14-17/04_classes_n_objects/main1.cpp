#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class ComplexNumbers
{

private:
    double re;
    double im;

    static int all, existing;

protected:
public:
    ComplexNumbers() : re{0}, im{0}
    {
        cout << "object created default\n";
        ++all;
        ++existing;
    }
    ComplexNumbers(double r, double i) : re{r}, im{i}
    {
        cout << "object created \\w parameters \n";
        ++all;
        ++existing;
    }
    // copy

    ComplexNumbers(const ComplexNumbers  &c)
    {
        re = c.getRe();
        im = c.getIm();
        cout << "object created by copy const\n";
        ++all;
        ++existing;
    }
    ComplexNumbers( const ComplexNumbers &&c)
    {
        re = c.getRe();
        im = c.getIm();
        cout << "object created by copy const&&\n";
        ++all;
        ++existing;
    }
    ~ComplexNumbers()
    {
        cout << "object destroyed!\n";
        --existing;
    }
    double getRe() const { return re; }
    double getIm() const { return im; }
    static void raport() { cout << "all: " << all << ", existing: " << existing << endl; }
};
int ComplexNumbers::all = 0;
int ComplexNumbers::existing = 0;

int main(int argc, char **argv)
{
    cout << "hello world" << endl
         << endl;

    // ComplexNumbers z1, z2, z3{1, 2}, z4{z3};
    ComplexNumbers *z1 = new ComplexNumbers, *z2 = new ComplexNumbers(), *z3 = new ComplexNumbers(3, 4), *z4 = new ComplexNumbers(*z3), *z5 = new ComplexNumbers(std::move(ComplexNumbers(1, 1)));
    delete z1;
    delete z2;
    delete z3;
    delete z4;
    delete z5;
    cout << endl
         << endl;

    ComplexNumbers::raport();
    return 0;
}
