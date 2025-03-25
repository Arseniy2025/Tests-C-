#include <iostream>
#include <string>
using namespace std;

class Encoder {
public:
    virtual string Crypt(const string& message) const = 0;
    virtual void Salt(const string& salt) = 0;

    string ProcessMessage(const string& message) const {
        string processed;
        try {
            for (int i = 0; i < message.length(); ++i) {
                char c = message[i];
                if (c != ' ') {
                    if (c >= 'а' && c <= 'я') {
                        processed += c - 32;
                    }
                    else if (c >= 'А' && c <= 'Я') {
                        processed += c;
                    }
                    else {
                        throw string("Ошибка");
                    }
                }
            }
        }
        catch (const exception& ex) {
            cout << "Ошибка обработки: " << endl;
        }
        return processed;
    }
};

class Caesar : public Encoder {
private:
    int shift;
    string salt;
public:
    Caesar(int shift = 3) {
        if (shift < 1 || shift > 25) {
            throw "Недопустимый сдвиг. Допустимые значения: 1-25";
        }
        this->shift = shift;
    }

    string Crypt(const string& message) const override {
        string processed = ProcessMessage(message);
        string result;

        for (size_t i = 0; i < processed.length(); ++i) {
            char c = processed[i];
            if (c >= 'А' && c <= 'Я') {
                char encrypted = (c - 'А' + shift) % 26 + 'А';
                result += encrypted;
            }
            else {
                throw "Неожиданный символ после обработки: " + string(1, c);
            }
        }

        if (result.empty()) {
            throw "Результат шифрования пуст";
        }

        return result;
    }

    void Salt(const string& salt) override {
        this->salt = salt;
    }

    string GetSalt() const {
        return salt;
    }
};


class Atbash : public Encoder {
private:
    string salt;
public:
    string Crypt(const string& message) const override {
        string processed = ProcessMessage(message);
        string result;

        for (size_t i = 0; i < processed.length(); ++i) {
            char c = processed[i];
            if (c >= 'А' && c <= 'Я') {
                char encrypted = 'Я' - (c - 'А');
                result += encrypted;
            }
            else {
                throw "Неожиданный символ после обработки: " + string(1, c);
            }
        }

        if (result.empty()) {
            throw "Результат шифрования пуст";
        }

        return result;
    }

    void Salt(const string& salt) override {
        this->salt = salt;
    }
};


class DigitCipher : public Encoder {
private:
    string salt;

    string numberToString(int num) const {
        if (num == 0) return "0";
        string result;
        while (num > 0) {
            char digit = '0' + (num % 10);
            result = digit + result;
            num /= 10;
        }
        return result;
    }

public:
    string Crypt(const string& message) const override {
        try {
            string processed = ProcessMessage(message);
            string result;

            for (size_t i = 0; i < processed.length(); ++i) {
                char c = processed[i];
                if (c >= 'А' && c <= 'Я') {
                    int letterNumber = (c - 'А' + 1);
                    result += numberToString(letterNumber) + " ";
                }
                else {
                    throw "Недопустимый символ для DigitCipher: " + string(1, c);
                }
            }

            if (result.empty()) {
                throw "Результат шифрования пуст";
            }
            return result;
        }
        catch (const exception& ex) {
            cout << "Ошибка обработки класса DigitCipher : " << endl;
        }
    }

    void Salt(const string& salt) override {
        this->salt = salt;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    string message = "ПРИВЕТ МИР";
    Atbash atbash;
    Caesar caesar;
    DigitCipher digitCipher;
    string encrypted = caesar.Crypt(message);
    string encrypted1 = atbash.Crypt(message);
    string encrypted2 = digitCipher.Crypt(message);
    cout << "Зашифрованное сообщение: " << encrypted;
    cout << "\nЗашифрованное сообщение: " << encrypted1;
    cout << "\nЗашифрованное сообщение: " << encrypted2;
    return 0;

}







