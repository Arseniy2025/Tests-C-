// Задание 1
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 20; 
    int range = 10; 
    int frequency[10] = { 0 }; 

    
    std::cout << "Введите 20 целых чисел в диапазоне от 0 до 9:\n";
    for (int i = 0; i < size; ++i) {
        int num;
        std::cin >> num;
        while (num < 0 || num > 9) {
            std::cout << "Введите число в диапазоне от 0 до 9: ";
            std::cin >> num;
        }
        frequency[num]++;
    }
    std::cout << "\nГистограмма частоты:\n";
    for (int i = 0; i < range; ++i) {
        if (frequency[i] > 0) {
            std::cout << i << ": ";
            for (int j = 0; j < frequency[i]; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

// Задание 2
#include <iostream>

void shakerSort(int* arr, int size) {
    int left = 0;
    int right = size - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;

                swapped = true;
            }
        }
        
        right--;

        
        if (!swapped) {
            break;
        }

        swapped = false;

        
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;

                swapped = true;
            }
        }
        
        left++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10;
    int mas[SIZE]{ 2, 1, 4, 5, 6, 4, 8, 4, 7, 9 };

    std::cout << "Массив до сортировки:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    
    shakerSort(mas, SIZE);

    std::cout << "Массив после сортировки:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
