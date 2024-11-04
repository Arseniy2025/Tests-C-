//Задание 1
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите число: ";
	int a;
	std::cin >> a;
	int sum = 0;
	while (a != 0) {
		sum += a % 10;
		a /= 10;
	}
	std::cout << "Сумма: " << sum;
	return 0;
}

//Задание 2
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int day;
	std::cout << "Введите количество дней: ";
	std::cin >> day;
	int t = 0;
	for (int day = 1; day <= day; day--) {
		int dist = 15 + (day - 1) * 2;
		t += dist;
	}
	std::cout << "Улитка проползла за " << day << "дней " << t << "см."<<std::endl;
	return 0;
}

//Задание 3
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
    int count = 0;

    std::cout << "Все возможные трехзначные комбинации:\n";


    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == i) continue;
            for (int k = 0; k <= 9; ++k) {
                if (k == i || k == j) continue;
                std::cout << i << j << k << std::endl;
                count++;
            }
        }
    }


    int timer = 3;
    int total = count * timer;

    std::cout << "\nКоличество комбинаций: " << count << std::endl;
    std::cout << "Время на открытие чемодана составляет: " << total << " секунд.";
	return 0;
}

//Задание 4
#include <iostream>
bool Prosto(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
	setlocale(LC_ALL, "Russian");
    std::cout << "Простые числа от 2 до 1000:\n";

    for (int i = 2; i <= 1000; ++i) { 
        if (Prosto(i)) { 
            std::cout << i << " "; 
        }
    }

    std::cout << std::endl;
    return 0;
}
//Задание 5
#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
    int l;
    char s;
    char d;


    std::cout << "Введите количество символов: ";
    std::cin >> l;

    std::cout << "Введите символ: ";
    std::cin >> s;

    std::cout << "Введите направление (h - горизонтально, v - вертикально): ";
    std::cin >> d;


    if (d == 'h' || d == 'H') {
        for (int i = 0; i < l; ++i) {
            std::cout << s;
        }
        std::cout << std::endl;
    }
    else if (d == 'v' || d == 'V') {
        for (int i = 0; i < l; ++i) {
            std::cout << s << std::endl;
        }
    }
    else {
        std::cout << "Неверное направление! Пожалуйста, введите 'h' или 'v'." << std::endl;
    }

    return 0;
}#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
    int l;
    char s;
    char d;


    std::cout << "Введите количество символов: ";
    std::cin >> l;

    std::cout << "Введите символ: ";
    std::cin >> s;

    std::cout << "Введите направление (h - горизонтально, v - вертикально): ";
    std::cin >> d;


    if (d == 'h' || d == 'H') {
        for (int i = 0; i < l; ++i) {
            std::cout << s;
        }
        std::cout << std::endl;
    }
    else if (d == 'v' || d == 'V') {
        for (int i = 0; i < l; ++i) {
            std::cout << s << std::endl;
        }
    }
    else {
        std::cout << "Неверное направление! Пожалуйста, введите 'h' или 'v'." << std::endl;
    }

    return 0;
}
