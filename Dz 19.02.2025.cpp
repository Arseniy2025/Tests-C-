#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Point;
class Function;

class Point {
    friend class Func;
private:
    int x;
    int y;
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void print() {
        cout << "x: " << x << "y: " << y;
    }
};

class Func {
    friend int averageFunc(Func&, int, int);
private:
    int a;
    int b;
    int c;
public:
    Func(int a, int b,int c)
    {
       this -> a = a;
       this -> b = b;
       this -> c = c;
    }
    bool isContains(Point& point) {
        return (point.y == a * point.x * point.x + b * point.x + c)?true:false;
    }
    void print() {
        cout << a << "x^2+" << b << "x+" << c;
    }
};


int averageFunc(Func& fun,int left, int right) {
    int sum = 0;
    int counter = 0;
    for (int i = left; i <= right; i++) {
        int x = i;
        int y = fun.a * x * x + fun.b * x + fun.c;
        sum += y;
        counter++;
    }
    sum = sum / counter;
    return sum;

}




int main()
{
    Func fun(2, 4, 0);
    Point p(0, 0);
    cout << fun.isContains(p)<<endl;
    cout << averageFunc(fun, 2, 2) << endl;

    fun.print();
}
