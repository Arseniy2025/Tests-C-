//Задание 1
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 1, 2, 3, 4, 2, 5, 6, 3, 7, 8, 1, 9, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bool printed[10] = { false }; 

    std::cout << "Повторяющиеся значения: ";

   
    for (int i = 0; i < size; i++) {
        int count = 0;

        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count >= 2 && !printed[arr[i]]) {
            std::cout << arr[i] << " ";
            printed[arr[i]] = true; 
        }
    }

    std::cout << std::endl;
    return 0;
}
//Задание 389
#include <iostream>

int main() {
    int n, m;

    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

   
    double matrix[10][10];

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    double max_of_mins = matrix[0][0];
    int max_row_index = 0;
    int max_col_index = 0;

    for (int i = 0; i < n; i++) {
        double min_in_row = matrix[i][0];
        int min_col_index = 0;


        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < min_in_row) {
                min_in_row = matrix[i][j];
                min_col_index = j;
            }
        }
        if (min_in_row > max_of_mins) {
            max_of_mins = min_in_row;
            max_row_index = i;
            max_col_index = min_col_index;
        }
    }

    
    std::cout << "Максимальное из минимальных элементов: " << max_of_mins << std::endl;
    std::cout << "Индексы: (" << max_row_index << ", " << max_col_index << ")" << std::endl;

    return 0;
}
//Задание 394
#include <iostream>

int main() {
    int n, m;

    setlocale(LC_ALL, "Russian");


    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;


    int matrix[20][20];


    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }


    std::cout << "Строки, удовлетворяющие условиям:" << std::endl;

    // а) 
    std::cout << "Строки с нулями: ";
    for (int i = 0; i < n; i++) {
        bool all_zeros = true;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                all_zeros = false;
                break;
            }
        }
        if (all_zeros) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // б) 
    std::cout << "Строки с одинаковыми элементами: ";
    for (int i = 0; i < n; i++) {
        bool all_same = true;
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != matrix[i][0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // в) 
    std::cout << "Строки с четными элементами: ";
    for (int i = 0; i < n; i++) {
        bool all_even = true;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 != 0) {
                all_even = false;
                break;
            }
        }
        if (all_even) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // г)
    std::cout << "Строки с монотонной последовательностью: ";
    for (int i = 0; i < n; i++) {
        bool increasing = true;
        bool decreasing = true;

        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < matrix[i][j - 1]) {
                increasing = false;
            }
            if (matrix[i][j] > matrix[i][j - 1]) {
                decreasing = false;
            }
        }

        if (increasing || decreasing) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}


