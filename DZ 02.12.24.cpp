//Задание 1
#include <iostream>
#include <string>

std::string replace(std::string input) {
    std::string result = "";

    for (char c : input) {
        
        if (c == 'a' ||  c == 'e' ||  c == 'i' ||  c == 'o'||  c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') { 
            result += '_';
        }
        else {
            result += c;
        }
    }

    return result;
}

int main() { 
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::cout << "Введите строку: ";
    std::cin >> input;
    std::string output = replace(input);
    std::cout << "Результат: " << output << std::endl;
    return 0;
}

//задание 2
#include <iostream>
#include <string>

std::string toLowerCase(const std::string& input) {
    std::string result = "";

    for (char c : input) { 
        result += std::tolower(c);
    }

    return result; 
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input); 

    std::string output = toLowerCase(input); 
    std::cout << "Результат: " << output << std::endl; 

    return 0;
}
