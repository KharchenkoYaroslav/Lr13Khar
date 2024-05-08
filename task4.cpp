#include <iostream>
using namespace std;

void f(const double &i)
{
    double *v;
    v = const_cast<double *>(&i);
    *v = 100;
}

int main()
{
    double x = 98.6;
    cout << x << endl;
    f(x);
    cout << x << endl;

    double A = 5;

    //  Example 1

    const double B = A; 
    const_cast<double &>(B) = A / 2; // work
    cout << B << endl;

    //  Example 2

    const double C = 5; 
    const_cast<double &>(C) = A / 2; // don`t work
    cout << C << endl;

    return 0;
}