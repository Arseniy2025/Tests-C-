#include <iostream>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void printTriangle(int n) {
    if (n <= 0) return; 


    std::cout << "1" << std::endl;
    if (n == 1) return;

    int sizeLast = 2;
    int* arrayLast = new int[sizeLast] {1, 1}; 
    printArray(arrayLast, sizeLast); 

    for (int i = 2; i < n; i++) {
        int* newArray = new int[i + 1];
        newArray[0] = 1; 
        newArray[i] = 1; 

        
        for (int j = 1; j < i; j++) {
            newArray[j] = arrayLast[j - 1] + arrayLast[j];
        }

        printArray(newArray, i + 1); 

        delete[] arrayLast; 
        arrayLast = newArray; 
    }

    delete[] arrayLast; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество строк для треугольника Паскаля: ";
    std::cin >> n; 
    printTriangle(n); 

    return 0;
}
