//Задание 9
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double R1, R2, R3, R_total;

    
    cout << "Введите сопротивления R1, R2, R3 (в Омах): ";
    cin >> R1 >> R2 >> R3;

    
    if (R1 <= 0 || R2 <= 0 || R3 <= 0) {
        cout << "Сопротивления должны быть положительными!" << endl;
        return 1;
    }

    
    R_total = 1 / (1 / R1 + 1 / R2 + 1 / R3);

    // Вывод результата с двумя знаками после запятой
    cout << "Общее сопротивление (параллельно): " << R_total << " Ом" << endl;

    return 0;
}

//Задание 24
#include <iostream>
#include <math.h> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x1, y1, x2, y2, d;

    
    cout << "Введите координаты первой точки (x1, y1): ";
    cin >> x1 >> y1;

    
    cout << "Введите координаты второй точки (x2, y2): ";
    cin >> x2 >> y2;

    
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << "Расстояние между точками: " << d << endl;

    return 0;
}

//Задание 36
#include <iostream>

using namespace std;

int main() {
    double a, b, c;

    setlocale(LC_ALL, "Russian");
    cout << "Введите три действительных числа (a, b, c): ";
    cin >> a >> b >> c;

    if (a < b && b < c) {
        cout << "Неравенства a < b < c выполняются." << endl;
    }
    else {
        cout << "Неравенства a < b < c не выполняются." << endl;
    }

    return 0;
}

//Задание 41

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double a,b,c ;

    
    cout << "Введите три действительных числа: ";
    cin >> a >> b >> c ;

    
    cout << "Числа, принадлежащие интервалу (1, 3): ";
    bool found = false;

    if (a > 1 && a < 3) {
        cout << a << " ";
        found = true;
    }
    if (b > 1 && b < 3) {
        cout << b << " ";
        found = true;
    }
    if (c > 1 && c < 3) {
        cout << c << " ";
        found = true;
    }

    if (!found) {
        cout << "Нет чисел, принадлежащих интервалу (1, 3).";
    }

    cout << endl;
    return 0;
}

//Задание 67

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;

    
    cout << "Введите натуральное число n (n <= 100): ";
    cin >> n;

    
    if (n < 1 || n > 100) {
        cout << "Число должно быть натуральным и не превышать 100." << endl;
        return 1;
    }

    // a)
    int count = 0;
    int summa = 0;
    int temp = n; 

    while (temp > 0) {
        summa += temp % 10;
        temp /= 10;               
        count++;             
    }

    // б)
    cout << "Количество цифр в числе n: " << count << endl;
    cout << "Сумма цифр числа n: " << summa << endl;

    // в) 
    int lastD = n % 10;
    cout << "Последняя цифра числа n: " << lastD << endl;

    // г) 
    int firstD = n;
    while (firstD >= 10) {
        firstD /= 10;
    }
    cout << "Первая цифра числа n: " << firstD << endl;

    return 0;
}
