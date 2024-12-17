#include <iostream> 
#include <cmath> 
using namespace std;
//Объявление структуры
struct complex {
    int weight;
    int hight;
    //Конструктор класса
    complex(int w, int h) {
        this->weight = w;
        this->hight = h;
    }
    //Вывод значений ширины и высоты
    void print() {
        cout << "Высота: " << hight << " Ширина: " << weight << endl;
    }
    // Перегрузка оператора + (сложение)
    complex operator+( complex& add)  {
        return complex(this->weight + add.weight, this->hight + add.hight);
    }
    // Перегрузка оператора - (вычитание)
    complex operator-( complex& add)  {
        return complex(this->weight - add.weight, this->hight - add.hight);
    }

    // Перегрузка оператора / (деление)
    complex operator/( complex& add)  {
        int area1 = this->weight * this->hight; //Площадь объекта 1
        int area2 = add.weight * add.hight; //Площадь объекта 2
        if (area2 == 0) {
           
            return complex(0, 0);
        }

        return complex(area1 / area2, 0); 
    }
    // Перегрузка оператора * (умножение)
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
