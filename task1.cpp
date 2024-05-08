#include <iostream>
using namespace std;
template <class T>  class coord
{
    T x, y; 
public:
    coord()
    {
        x = 0;
        y = 0;
        cout << "Constructing A." << endl;
    };
    coord(T i, T j)
    {
        x = i;
        y = j;
        cout << "Constructing B." << endl;
    }
    void get_xy(T &i, T &j)
    {
        i = x;
        j = y;
    }
    ~coord() { cout << "Destructing." << endl; };
    coord operator+(const coord obj);
};
template <class T>
coord<T> coord<T>::operator+(const coord<T> obj)
{
    coord<T> temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}
int main()
{
    coord <int> obj1(10.2, 10), obj2(5, 3.5), obj3;
    int x1, y1;
    obj3 = obj1 + obj2; 
    obj3.get_xy(x1, y1);
    cout << "(obj1+obj2) X: " << x1 << ", Y: " << y1 << endl;

    coord <double> obj4(10.2, 10), obj5(5, 3.5), obj6;
    double x2, y2;
    obj6 = obj4 + obj5; 
    obj6.get_xy(x2, y2);
    cout << "(obj4+obj5) X: " << x2 << ", Y: " << y2 << endl;
    return 0;
}