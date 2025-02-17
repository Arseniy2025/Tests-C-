#include <iostream>
using namespace std;

void checkPass() {

    string pass;
    try{
        cout << "Для регистрации введите пароль состоящий минимиум из 8 символов без знаков '.', ',', '/': ";
        cin >> pass ;

        if ( pass.length() < 8) {
            throw "Error: Нужно больше 8 символов";
        }

        int i = 0;
        while (i < pass.length()) {
            char c = pass[i];
            if (c == '.' || c == ',' || c == '/') {
                throw "Error:Не должно быть знаков '.', ',', '/' ";
            }
            i++;
        }

        cout << "Пароль принят";
        cout << "Новый пароль: " << pass;
        
    }
    catch (const char* error_message) {
        cout << error_message;
    }


}

int main()
{
    setlocale(LC_ALL, "rus");
    checkPass();
}

