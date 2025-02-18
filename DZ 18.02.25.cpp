#include <iostream>
#include <cmath>
using namespace std;

class Func {
    friend bool PointOnFunction(Func& f, double x, double y);
    friend double ValueOnInterval(Func& f, double x1, double x2);
private:
    double a;
    double b;
    double c;

public:
    Func(double func_a, double func_b, double func_c = 0) {
        a = func_a;
        b = func_b;
        c = func_c;
    }

    double evaluate(double x) {
        if (c != 0) {
            return a * x * x + b * x + c;
        }
        else {
            return a * x + b;
        }
    }
};


bool PointOnFunction(Func& f, double x, double y) {
    return y == f.evaluate(x);
}


double ValueOnInterval(Func& f, double x1, double x2) {
    int n = 1000;
    double sum = 0;
    double dx = (x2 - x1) / n;
    for (int i = 0; i < n; ++i) {
        double x = x1 + i * dx;
        sum += f.evaluate(x);
    }
    return sum / n;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Func linearFunc(2, 3);
    Func quadraticFunc(1, -2, 1);

    cout << "Точка (2, 7) принадлежит линейной функции: "
        << (PointOnFunction(linearFunc, 2, 7) ? "Да" : "Нет") << endl;

    cout << "Точка (1, 0) принадлежит квадратичной функции: "
        << (PointOnFunction(quadraticFunc, 1, 0) ? "Да" : "Нет") << endl;

    cout << "Среднее значение линейной функции на интервале [0, 2]: "
        << ValueOnInterval(linearFunc, 0, 2) << endl;

    cout << "Среднее значение квадратичной функции на интервале [0, 2]: "
        << ValueOnInterval(quadraticFunc, 0, 2) << endl;

    return 0;
}
