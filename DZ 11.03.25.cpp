#include <iostream>
#include <string>
using namespace std;

class BaseClass {
protected:
    int power;
    string name;

public:
    
    BaseClass() {
        power = 0;
        name = "Неизвестно";
    }
    BaseClass(int p, const string& n) {
        this->power = p;
        this->name = n;
    }

    void setPower(int p) {
        if (p >= 0) {
            power = p;
        }
        else {
            cout << "Ошибка: мощность не может быть отрицательной." << endl;
        }
    }

   
    bool operator==(const BaseClass& other) const {
        return power == other.power && name == other.name;
    }

    
    BaseClass operator+(const BaseClass& other) const {
        return BaseClass(power + other.power, name + " & " + other.name);
    }

    
    BaseClass& operator++() {
        ++power;
        return *this;
    }

    virtual void print() const {
        cout << "Вычислительная машина: " << name << ", мощность: " << power << endl;
    }
};


class DerivedClass1 : public BaseClass {
private:
    int ram; 

public:
    DerivedClass1() {
        ram=0;
    }
    DerivedClass1(int p, const string& n, int r) {
        this->power = p; 
        this->name = n;  
        this->ram = r;
    }

    void setRAM(int r) {
        if (r >= 0) {
            ram = r;
        }
        else {
            cout << "Ошибка: оперативная память не может быть отрицательной." << endl;
        }
    }

    void print() const override {
        cout << "Персональный компьютер: " << name << ", мощность: " << power << ", ОЗУ: " << ram << "GB" << endl;
    }
};

class DerivedClass2 : public BaseClass {
private:
    double screenSize; 

public:
    DerivedClass2() {
        screenSize = 0.0;
    }
    DerivedClass2(int p, const string& n, double s) {
        this->power = p;
        this->name = n;
        this->screenSize = s;
    }

    void setScreenSize(double s) {
        if (s >= 0) {
            screenSize = s;
        }
        else {
            cout << "Ошибка: размер экрана не может быть отрицательным." << endl;
        }
    }

    void print() const override {
        cout << "Ноутбук: " << name << ", мощность: " << power << ", размер экрана: " << screenSize << " дюймов" << endl;
    }
};


class DerivedClass3 : public BaseClass {
private:
    int batteryLife; 

public:
    DerivedClass3() {
        batteryLife = 0;
    }
    DerivedClass3(int p, const string& n, int b) {
        this->power = p;
        this->name = n;
        this->batteryLife = b;
    }

    void setBatteryLife(int b) {
        if (b >= 0) {
            batteryLife = b;
        }
        else {
            cout << "Ошибка: время работы от батареи не может быть отрицательным." << endl;
        }
    }

    void print() const override {
        cout << "Планшет: " << name << ", мощность: " << power << ", время работы от батареи: " << batteryLife << " часов" << endl;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100; 
    BaseClass* collection[MAX_SIZE] = { nullptr }; 
    int count = 0; 

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить новый элемент\n";
        cout << "2. Удалить элемент по индексу\n";
        cout << "3. Вывод всех элементов\n";
        cout << "4. Сравнение двух элементов на равенство\n";
        cout << "5. Завершение работы\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (count >= MAX_SIZE) {
                cout << "Достигнуто максимальное количество элементов." << endl;
                break;
            }

            int type;
            cout << "Выберите тип элемента (1 - Персональный компьютер, 2 - Ноутбук, 3 - Планшет): ";
            cin >> type;

            int power;
            string name;
            cout << "Введите мощность: ";
            cin >> power;
            cout << "Введите название: ";
            cin >> name;

            if (type == 1) {
                int ram;
                cout << "Введите объем ОЗУ: ";
                cin >> ram;
                collection[count] = new DerivedClass1(power, name, ram);
            }
            else if (type == 2) {
                double screenSize;
                cout << "Введите размер экрана: ";
                cin >> screenSize;
                collection[count] = new DerivedClass2(power, name, screenSize);
            }
            else if (type == 3) {
                int batteryLife;
                cout << "Введите время работы от батареи: ";
                cin >> batteryLife;
                collection[count] = new DerivedClass3(power, name, batteryLife);
            }
            else {
                cout << "Неверный тип элемента." << endl;
                continue;
            }
            count++;
            break;
        }
        case 2: {
            int index;
            cout << "Введите индекс элемента для удаления: ";
            cin >> index;
            if (index >= 0 && index < count && collection[index] != nullptr) {
                delete collection[index];
                for (int i = index; i < count - 1; i++) {
                    collection[i] = collection[i + 1];
                }
                collection[count - 1] = nullptr;
                count--;
            }
            else {
                cout << "Неверный индекс." << endl;
            }
            break;
        }
        case 3: {
            for (int i = 0; i < count; i++) {
                cout << "Элемент " << i << ": ";
                collection[i]->print();
            }
            break;
        }
        case 4: {
            int index1, index2;
            cout << "Введите индексы двух элементов для сравнения: ";
            cin >> index1 >> index2;
            if (index1 >= 0 && index1 < count && index2 >= 0 && index2 < count) {
                if (*collection[index1] == *collection[index2]) {
                    cout << "Элементы равны." << endl;
                }
                else {
                    cout << "Элементы не равны." << endl;
                }
            }
            else {
                cout << "Неверные индексы." << endl;
            }
            break;
        }
        case 5: {
            cout << "Завершение работы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 5);

    for (int i = 0; i < count; i++) {
        delete collection[i];
    }

    return 0;
}
