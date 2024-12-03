//Задание 1
#include <iostream>
#include <string>

std::string atbashCipher(std::string input) {
    std::string output;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) { 
            char offset = (ch >= 'a' && ch <= 'z') ? 'a' : 'A'; 
            output += (char)(offset + ('z' - ch)); 
        } else {
            output += ch; 
        }
    }
    return output;
}

int main() {
    std::string text;
    std::cout << "Введите текст: ";
    std::cin >> text; 
    std::string encrypted = atbashCipher(text);
    std::cout << "Зашифрованный текст: " << encrypted << std::endl;
    return 0;
}
//Задание 2
#include <iostream>
#include <string>

std::string lettersToNumbers(std::string input) {
    std::string output;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        
        if (ch >= 'A' && ch <= 'Z') { 
            output += (ch - 'A' + 1) + '0'; 
            output += " "; 
        } else if (ch >= 'a' && ch <= 'z') {
            output += (ch - 'a' + 1) + '0'; 
            output += " "; 
        }
    }

    return output;
}

int main() {
    std::string text;
    std::cout << "Введите слово: ";
    std::cin >> text; // Считываем одно слово (без пробелов)

    std::string result = lettersToNumbers(text);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
//Задание 3
#include <iostream>
#include <string>

std::string removeDuplicatesIter(std::string str) {
  std::string result = "";
  for (char c : str) {
    size_t found = result.find(c);
    if (found == std::string::npos) {
      result += c;
    }
  }
  return result;
}

int main() {
  std::string str1 = "abracadabra";
  std::string str2 = "Mississippi";
  std::string str3 = "";

  std::cout << "Оригинальная строка: " << str1 << ", Результат: " << removeDuplicatesIter(str1) << std::endl; //abracd
  std::cout << "Оригинальная строка: " << str2 << ", Результат: " << removeDuplicatesIter(str2) << std::endl; //Msip
  std::cout << "Оригинальная строка: " << str3 << ", Результат: " << removeDuplicatesIter(str3) << std::endl; //

  return 0;
}
//Задание 4
#include <iostream>
#include <string>

bool is_alpha_numeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char to_lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }
  return c;
}

bool isPalindrome(const std::string& str) {
  if (str.empty()) return true;

  size_t left = 0;
  size_t right = str.length() - 1;

  while (left < right) {
    while (left < right && !is_alpha_numeric(str[left])) {
      left++;
    }
    while (left < right && !is_alpha_numeric(str[right])) {
      right--;
    }

    if (to_lower(str[left]) != to_lower(str[right])) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  std::string str1 = "A man, a plan, a canal: Panama";
  std::string str2 = "race a car";
  std::string str3 = "hello";
  std::string str4 = "";

  std::cout << "\"" << str1 << "\" полином: " << isPalindrome(str1) << std::endl; 
  std::cout << "\"" << str2 << "\" полином: " << isPalindrome(str2) << std::endl; 
  std::cout << "\"" << str3 << "\" полином: " << isPalindrome(str3) << std::endl; 
  std::cout << "\"" << str4 << "\" полином: " << isPalindrome(str4) << std::endl;

  return 0;
}
