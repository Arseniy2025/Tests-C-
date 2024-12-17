#include <iostream> 
#include <cmath> 
using namespace std;

struct complex {
    int weight;
    int hight;

    complex(int w, int h) {
        this->weight = w;
        this->hight = h;
    }

    void print() {
        cout << "Высота: " << hight << " Ширина: " << weight << endl;
    }

    complex operator+( complex& add)  {
        return complex(this->weight + add.weight, this->hight + add.hight);
    }

    complex operator-( complex& add)  {
        return complex(this->weight - add.weight, this->hight - add.hight);
    }

    
    complex operator/( complex& add)  {
        int area1 = this->weight * this->hight;
        int area2 = add.weight * add.hight;
        if (area2 == 0) {
           
            return complex(0, 0);
        }

        return complex(area1 / area2, 0); 
    }

    complex operator*( complex& add)  {
        return complex(this->weight * add.weight, this->hight * add.hight);
    }
};



int main() {
    setlocale(LC_ALL, "Russian");
    complex a = complex(5, 10); 
    complex b = complex(3, 9);  


    complex sum = a + b;
    cout << "Сумма: ";
    sum.print();

    complex sub = a - b;
    cout << "Вычитание: ";
    sub.print();

    complex mul = a * b;
    cout << "Умножение: ";
    mul.print();

    complex del = a / b;
    cout << "Деление: ";
    del.print();
    return 0;
}
