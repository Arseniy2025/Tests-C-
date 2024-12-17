//6
#include <iostream> 
#include <random> 
 
 
void RandomMatrix(int* arr, int size) { 
    if (arr == nullptr || size <= 0) { 
        return;  
    } 
 
    
    bool seeded = false; 
    if (!seeded) { 
        seeded = true; 
    } 
 
    for (int i = 0; i < size; ++i) { 
        arr[i] = std::rand() % 10;  
    } 
} 
 
int main() { 
    int size; 
 
    std::cout << "Введите размер массива: "; 
    std::cin >> size; 
 
    if (size <= 0) { 
        std::cout << "Некорректный размер массива." << std::endl; 
        return 1;  
    } 
 
    int* myArray = new int[size]; 
 
    RandomMatrix(myArray, size); 
 
    std::cout << "Массив, заполненный случайными числами: "; 
    for (int i = 0; i < size; ++i) { 
        std::cout << myArray[i] << " "; 
    } 
    std::cout << std::endl; 
 
    delete[] myArray;  
    myArray = nullptr;  
 
    return 0; 
}

//9
#include <iostream>
#include <string>
char* reverseString( char* str) {
  if (str == nullptr) {
    return nullptr; 
  }

  
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }

    char* reversedStr = new char[length + 1];
    
    for (int i = 0; i < length; ++i) {
    reversedStr[i] = str[length - 1 - i];
  }


  reversedStr[length] = '\0'; 
  return reversedStr;
}

int main() {
    char* Strorig = "Hello, World!";
    char* reversedStr = reverseString(Strorig);
      if (reversedStr != nullptr) {
        std::cout << "Оригинальная строка: " << Strorig << std::endl;
        std::cout << "Реверсивная строка: " << reversedStr << std::endl;
         delete[] reversedStr;
    } else {
        std::cout << "Ошибка" << std::endl;
    }
    
    char* empStr = "";
    char* reversedEmptyStr = reverseString(empStr);

    if (reversedEmptyStr != nullptr) {
      std::cout << "Оригинальная строка: " << empStr << std::endl;
        std::cout << "Реверсивная строка: " << reversedEmptyStr << std::endl;
         delete[] reversedEmptyStr;
    } else {
         std::cout << "Ошибка" << std::endl;
    }
    char* nullStr = nullptr;
    char* reversedNullStr = reverseString(nullStr);

    if (reversedNullStr != nullptr) {
        std::cout << "Оригинальная строка: " << nullStr << std::endl;
        std::cout << "Реверсивная строка: " << reversedNullStr << std::endl;
        delete[] reversedNullStr;
    } else {
         std::cout << "Ошибка" << std::endl;
    }

    return 0;
}
