//Задание 1
#include <iostream>

int fibonacci(int n) {
   
    if (n == 0) return 0;
    if (n == 1) return 1;

   
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите номер числа Фибоначчи: ";
    std::cin >> n;

    int result = fibonacci(n);
    std::cout << "Число Фибоначчи с индексом " << n << " равно " << result << std::endl;

    return 0;
}

//Задание 2
#include <iostream>

double power(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) return 1 / power(base, -exponent);

    
    return base * power(base, exponent - 1); 
}

int main() {
    setlocale(LC_ALL, "Russian");
    double base;
    int exponent;

    std::cout << "Введите основание: ";
    std::cin >> base;
    std::cout << "Введите степень: ";
    std::cin >> exponent;

    double result = power(base, exponent);
    std::cout << base << " в степени " << exponent << " равно " << result << std::endl;

    return 0;
}
