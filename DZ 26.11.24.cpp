//Арифметика
//3
#include <iostream>
using namespace std;
int main() {
    double Len;
    cout<<"Введите длину ребра куба";
    cin>>Len;
    double value=Len*Len*Len;
    double lateral=4*Len*Len;
    cout<<"\nОбъем куба: "<< value;
    cout<<"\nПлощадь БП: "<< lateral;
    return 0;
}
//14
#include <iostream>
double G=6.674;
using namespace std;
int main() {
    double m1,m2,r;
    cout<<"Введите первую массу: ";
    cin>>m1;
    cout<<"Введите вторую массу: ";
    cin>>m2;
    cout<<"Введите расстояние: ";
    cin>>r;
    double F=G*(m1*m2)/(r*r);
    cout<<"Сила притяжения равна: "<< F <<"H";
    return 0;
}

//17
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double Radius=20.0;
    double ORadius;
    cout<<"\nВнутренний радиус равен 20. Напишите радиус (r>20): ";
    cin>>ORadius;
    double area = M_PI*(ORadius*ORadius - Radius*Radius);
    cout<<"\nПлощадь кольца: "<<area;
    
    return 0;
}
//19
#include <iostream>

int main() {
    double v1, a1, v2, a2, S0;

    std::cout << "Введите начальную скорость первого тела (v1): ";
    std::cin >> v1;
    std::cout << "Введите ускорение первого тела (a1): ";
    std::cin >> a1;
    std::cout << "Введите начальную скорость второго тела (v2): ";
    std::cin >> v2;
    std::cout << "Введите ускорение второго тела (a2): ";
    std::cin >> a2;
    std::cout << "Введите начальное расстояние между телами (S0): ";
    std::cin >> S0;

   
    double t = -2 * (v1 - v2) / (a1 - a2);

    if (t < 0) {
        std::cout << "Тела не встретятся." << std::endl;
    } else {
        std::cout << "Тела встретятся через " << t << " секунд." << std::endl;
    }

    return 0;
}

//Ветвление 
//38 
#include <iostream> 
#include <cmath> 
 
using namespace std; 
 
int main() { 
    int x,y,z; 
    z=0; 
    cout<<"Введите число x: "; 
    cin>>x; 
    cout<<"Введите число y: "; 
    cin>>y; 
    if(x>y){ 
        z=x-y; 
    } 
    else{ 
        z=y-x+1; 
    } 
    cout<<"z="<<z; 
    return 0; 
}

//41
include <iostream>

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

//Целочисленные операции
//76
#include <iostream>
#include <cmath>

bool areSameColor(int k, int l, int m, int n) {
    return (k + l) % 2 == (m + n) % 2;
}

bool isQueenThreatening(int k, int l, int m, int n) {
    return (k == m)  (l == n)  (abs(k - m) == abs(l - n));
}

bool isKnightThreatening(int k, int l, int m, int n) {
    return (abs(k - m) == 2 && abs(l - n) == 1) || (abs(k - m) == 1 && abs(l - n) == 2);
}

bool isRookOneMove(int k, int l, int m, int n) {
    return (k == m) || (l == n);
}

bool isRookTwoMoves(int k, int l, int m, int n, int &intermediateX, int &intermediateY) {
    if (k != m && l != n) {
        intermediateX = m; 
        intermediateY = l; 
        return true;
    } else if (k != m) {
        intermediateX = m; 
        intermediateY = l; 
        return true;
    } else if (l != n) {
        intermediateX = k; 
        intermediateY = n;
        return true;
    }
    return false;
}

bool isQueenOneMove(int k, int l, int m, int n) {
    return (k == m)  (l == n)  (abs(k - m) == abs(l - n));
}

bool isBishopOneMove(int k, int l, int m, int n) {
    return abs(k - m) == abs(l - n);
}

int main() {
  setlocale(LC_ALL, "Russian");
    int k, l, m, n;
    std::cout << "Введите координаты первого поля (k, l): ";
    std::cin >> k >> l;
    std::cout << "Введите координаты второго поля (m, n): ";
    std::cin >> m >> n;

    
    std::cout << "Поля одного цвета: " << (areSameColor(k, l, m, n) ? "Да" : "Нет") << std::endl;

    
    std::cout << "Ферзь угрожает полю (m, n): " << (isQueenThreatening(k, l, m, n) ? "Да" : "Нет") << std::endl;


    std::cout << "Конь угрожает полю (m, n): " << (isKnightThreatening(k, l, m, n) ? "Да" : "Нет") << std::endl;

    
    std::cout << "Ладья может сделать один ход: " << (isRookOneMove(k, l, m, n) ? "Да" : "Нет") << std::endl;
    int intermediateX, intermediateY;
    if (!isRookOneMove(k, l, m, n) && isRookTwoMoves(k, l, m, n, intermediateX, intermediateY)) {
        std::cout << "Ладья может сделать два хода через (" << intermediateX << ", " << intermediateY << ")" << std::endl;
    }

    
    std::cout << "Ферзь может сделать один ход: " << (isQueenOneMove(k, l, m, n) ? "Да" : "Нет") << std::endl;

    
    std::cout << "Слон может сделать один ход: " << (isBishopOneMove(k, l, m, n) ? "Да" : "Нет") << std::endl;

    return 0;
}

//74
#include <iostream>

int main() {
  setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите возраст (в годах): ";
    std::cin >> n;

    
    if (n % 10 == 1 && n % 100 != 11) {
        std::cout << n << " год" << std::endl; 
    } else if (n % 10 >= 2 && n % 10 <= 4 && (n % 100 < 10 || n % 100 >= 20)) {
        std::cout << n << " года" << std::endl; 
    } else {
        std::cout << n << " лет" << std::endl; 
    }

    return 0;
}
//75
#include <iostream>

int main() {
    int n;
    std::cout << "Введите сумму больше 7 рублей: ";
    std::cin >> n;

    if (n <= 7) {
        std::cout << "Сумма должна быть больше 7 рублей." << std::endl;
        return 1;
    }

    bool found = false;

    
    for (int b = 0; b <= n / 5; ++b) {
        
        int remaining = n - 5 * b;

      
        if (remaining % 3 == 0) {
            int a = remaining / 3;
            std::cout << "Найдено решение: a = " << a << ", b = " << b << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Не удалось найти целые неотрицательные a и b." << std::endl;
    }

    return 0;
}




//Массивы
//1
#include <iostream>

int main() {
    
    int array[] = {1, 0, 2, 0, 3, 4, 0, 5};
    int n = sizeof(array) / sizeof(array[0]);


    int zeroCount = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] == 0) {
            zeroCount++;
        }
    }

   
    std::cout << "Количество нулей в массиве: " << zeroCount << std::endl;

    return 0;
}

//2
#include <iostream>

int main() {
    const int SIZE = 10; 
    int numbers[SIZE];   
    int C;              
    int sum = 0;        
    int count = 0;      

    
    std::cout << "Введите 10 чисел:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> numbers[i]; 
    }

   
    std::cout << "Введите число C: ";
    std::cin >> C;

    
    for (int i = 0; i < SIZE; ++i) {
        if (numbers[i] >C{
            sum += numbers[i];
            count++;           
        }
    }

    
    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        std::cout << "Среднее арифметическое элементов, превышающих " << C << ": " << average << std::endl;
    } else {
        std::cout << "Нет элементов, превышающих " << C << "." << std::endl; 
    }

    return 0; 
}
//3
#include <iostream>

int main() {
    int n;

   
    std::cout << "Введите количество элементов массива: ";
    std::cin >> n;

    
    if (n <= 0) {
        std::cout << "Количество элементов должно быть положительным." << std::endl;
        return 1;
    }

    int numbers[n];
    long long product = 1; 

    
    std::cout << "Введите " << n << " целых чисел:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i]; 
    }

    
    for (int i = 0; i < n; i += 2) { 
        product *= numbers[i]; 
    }

    
    std::cout << "Произведение элементов с четными индексами: " << product << std::endl;

    return 0; 
}

//Двумерные массивы
//1
#include <iostream>

int main() {
    int n, m; 


    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;


    if (n <= 0 || m <= 0) {
        std::cout << "Количество строк и столбцов должно быть положительным." << std::endl;
        return 1;
    }

    
    int** array = new int*[n]; 
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m]; 
    }

  
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> array[i][j]; 
        }
    }
    
    std::cout << "Суммы элементов в каждой строке:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += array[i][j]; 
        }
        std::cout << "Сумма строки " << i + 1 << ": " << sum << std::endl; 
    }

    
    for (int i = 0; i < n; ++i) {
        delete[] array[i]; 
    }
    delete[] array; 

    return 0;
}






