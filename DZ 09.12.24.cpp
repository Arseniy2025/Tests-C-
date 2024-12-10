//Задание 1
#include <iostream>
using namespace std;

int* getEvenNumbers( int* arr, int size) {
    
    int evenCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }

    
    if (evenCount == 0) {
        return nullptr;
    }

   
    int* evenArr = new int[evenCount];

    
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            evenArr[index++] = arr[i];
        }
    }

    return evenArr;
}



int main() { 
    setlocale(LC_ALL, "Russian");
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* evenArr = getEvenNumbers(arr, size);

    if (evenArr != nullptr) {
        std::cout << "Четные числа: ";
        for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])) / 2; i++) { 
            std::cout << evenArr[i] << " ";
        }
        std::cout << std::endl;

        delete[] evenArr; 
    }
    else {
        std::cout << "В массиве нет четных чисел." << std::endl;
    }
    
    return 0;
}
//Задание 3
#include <iostream>
#include <string>

using namespace std;

int countWords(std::string str) {
    if (str.empty()) {
        return 0;
    }

    int wordCount = 0;
    bool inWord = false;
    for (char c : str) {
        if (c != ' ' && !inWord) {
            inWord = true;
            wordCount++;
        }
        else if (c == ' ') {
            inWord = false;
        }
    }
    return wordCount;
}



int main() { 
    setlocale(LC_ALL, "Russian");
    std::string str1 = "Это строка с несколькими словами";
    std::string str2 = "  Одна строка  с пробелами  ";
    std::string str3 = "";
    std::string str4; 

    std::cout << "\"" << str1 << "\" содержит " << countWords(str1) << " слов." << std::endl;
    std::cout << "\"" << str2 << "\" содержит " << countWords(str2) << " слов." << std::endl;
    std::cout << "\"" << str3 << "\" содержит " << countWords(str3) << " слов." << std::endl;
    std::cout << "\"" << str4 << "\" содержит " << countWords(str4) << " слов." << std::endl;
    
    return 0;
}
//Задание 4
#include <iostream>

using namespace std;

void sortArray(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    int size = 10;
    int* arr = new int[size] {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};

    std::cout << "Массив до сортировки: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sortArray(arr, size);

    std::cout << "Массив после сортировки: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
//Задание 5
#include <iostream>

using namespace std;

bool isPalindrome( std::string& str) {
    std::string reversed_str = "";
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed_str += str[i];
    }
    return str == reversed_str;
}



int main() {
    setlocale(LC_ALL, "Russian");
    std::string str1 = "Машина";
    std::string str2 = "Топор";
    std::string str3 = "hello";
    std::string str4 = ""; 

    std::cout << "\"" << str1 << "\" - палиндром: " << (isPalindrome(str1) ? "да" : "нет") << std::endl;
    std::cout << "\"" << str2 << "\" - палиндром: " << (isPalindrome(str2) ? "да" : "нет") << std::endl;
    std::cout << "\"" << str3 << "\" - палиндром: " << (isPalindrome(str3) ? "да" : "нет") << std::endl;
    std::cout << "\"" << str4 << "\" - палиндром: " << (isPalindrome(str4) ? "да" : "нет") << std::endl;


    return 0;
}
//Задание 7
#include <iostream>
#include <string>

int countChar(std::string str, char ch) { 
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string str = "Hello, world!";
    char ch = 'l';
    int occurrences = countChar(str, ch);
    std::cout << "Символ '" << ch << "' встречается " << occurrences << " раз в строке \"" << str << "\"." << std::endl;
    return 0;
}
//Задание 8
#include <iostream>

double calculateAverage(const int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return 0.0; 
    }

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 5;
    int* arr = new int[size] {10, 20, 30, 40, 50};

    double average = calculateAverage(arr, size);
    std::cout << "Среднее арифметическое: " << average << std::endl;

    delete[] arr; 
    return 0;
}
