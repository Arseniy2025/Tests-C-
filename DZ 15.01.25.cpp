//Задание 1
#include <iostream>
using namespace std;

double* Copy(double* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        return nullptr;
    }
    double* d = new double[size];

    for (int i = 0; i < size; ++i) {
        d[i] = arr[i];
    }
    return d;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double origArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    int size = sizeof(origArray) / sizeof(origArray[0]);


    double* copied = Copy(origArray, size);


    if (copied != nullptr) {
        std::cout << "Оригинальный массив: ";
        for (int i = 0; i < size; ++i) {
            std::cout << origArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Скопированный масив:   ";
        for (int i = 0; i < size; ++i) {
            std::cout << copied[i] << " ";
        }
        delete[] copied;
    }
        return 0;
}


//Задание 2
#include <iostream>
using namespace std;


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


int* removeDuplicates(int* arr, int size, int& newSize) {
    if (arr == nullptr || size <= 0) {
        newSize = 0;
        return nullptr;
    }

    
    bubbleSort(arr, size);

    
    int uniqueCount = 0;
    if (size > 0) {
        uniqueCount = 1;
        for (int i = 1; i < size; ++i) {
            if (arr[i] != arr[i - 1]) {
                uniqueCount++;
            }
        }
    }

    newSize = uniqueCount;

    
    int* newArray = new int[newSize];
    if (newSize > 0) {
        newArray[0] = arr[0];
        int newArrayIndex = 1;
        for (int i = 1; i < size; ++i) {
            if (arr[i] != arr[i - 1]) {
                newArray[newArrayIndex] = arr[i];
                newArrayIndex++;
            }
        }
    }


    return newArray;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 1, 2, 2, 3, 4, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* dynamicArray = new int[size];
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = arr[i];
    }

    int newSize;
    int* uniqueArray = removeDuplicates(dynamicArray, size, newSize);
    delete[] dynamicArray; 

    if (uniqueArray != nullptr) {
        cout << "Массив без дубликатов: ";
        for (int i = 0; i < newSize; ++i) {
            cout << uniqueArray[i] << " ";
        }
        cout << endl;
        cout << "Размер массива без дубликатов: " << newSize << endl;

        delete[] uniqueArray;
    }
    else {
        cout << "Не удалось создать массив без дубликатов." << endl;
    }

    return 0;
}
