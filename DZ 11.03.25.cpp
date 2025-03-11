#include <iostream>
#include <string>
using namespace std;
class ComputingMachine {
protected:
    string model;
    int power;

public:
    ComputingMachine() : model(""), power(0) {}

    ComputingMachine(const string& model, int power) : model(model) {
        SetPower(power);
    }

    
    string GetModel() const { return model; }
    void SetModel(const string& model) { this->model = model; }

    int GetPower() const { return power; }
    void SetPower(int power) {
        if (power >= 0) {
            this->power = power;
        }
        else {
            cout << "Ошибка: Мощность должна быть неотрицательной. Установите значение мощности равным 0." << endl;
            this->power = 0;
        }
    }

    virtual void DisplayInfo() const {
        cout << "Вычислительная машина: Модель = " << model << ", Мощность = " << power << "В";
    }

    bool operator==(const ComputingMachine& other) const {
        return (model == other.model && power == other.power);
    }

    
    ComputingMachine operator+(const ComputingMachine& other) const {
        return ComputingMachine(model + "+" + other.model, power + other.power);
    }

   
    ComputingMachine& operator++() {
        power++;
        return *this;
    }

    
    ComputingMachine operator++(int) {
        ComputingMachine temp = *this;
        ++(*this);
        return temp;
    }
};


class PersonalComputer : public ComputingMachine {
protected:
    string operatingSystem;
    int ram; 

public:
    PersonalComputer() : ComputingMachine(), operatingSystem(""), ram(0) {}

    PersonalComputer(const string& model, int power, const string& operatingSystem, int ram)
        : ComputingMachine(model, power), operatingSystem(operatingSystem) {
        SetRam(ram);
    }

    
    string GetOperatingSystem() const { return operatingSystem; }
    void SetOperatingSystem(const string& operatingSystem) { this->operatingSystem = operatingSystem; }

    int GetRam() const { return ram; }
    void SetRam(int ram) {
        if (ram >= 0) {
            this->ram = ram;
        }
        else {
            cout << "Ошибка: значение RAM должно быть неотрицательным. Значение RAM равно 0." << endl;
            this->ram = 0;
        }
    }

    void DisplayInfo() const override {
        ComputingMachine::DisplayInfo();
        cout << ", Операционная система = " << operatingSystem << ", RAM = " << ram << "Гб";
    }

    bool operator==(const PersonalComputer& other) const {
        return (ComputingMachine::operator==(other) && operatingSystem == other.operatingSystem && ram == other.ram);
    }

    PersonalComputer operator+(const PersonalComputer& other) const {
        return PersonalComputer(GetModel() + "+" + other.GetModel(), GetPower() + other.GetPower(), operatingSystem + "+" + other.operatingSystem, ram + other.ram);
    }
    PersonalComputer& operator++() {
        ram++;
        return *this;
    }

    PersonalComputer operator++(int) {
        PersonalComputer temp = *this;
        ++(*this);
        return temp;
    }
};


class Laptop : public PersonalComputer {
protected:
    double screenSize;
    bool hasWebcam;

public:
    Laptop() : PersonalComputer(), screenSize(0.0), hasWebcam(false) {}

    Laptop(const std::string& model, int power, const std::string& operatingSystem, int ram, double screenSize, bool hasWebcam)
        : PersonalComputer(model, power, operatingSystem, ram), screenSize(screenSize), hasWebcam(hasWebcam) {
        SetScreenSize(screenSize);
    }

    double GetScreenSize() const { return screenSize; }
    void SetScreenSize(double screenSize) {
        if (screenSize >= 0) {
            this->screenSize = screenSize;
        }
        else {
            cout << "Ошибка: Размер экрана должен быть неотрицательным. Значение равно 0." << endl;
            this->screenSize = 0;
        }
    }


    bool HasWebcam() const { return hasWebcam; }
    void SetHasWebcam(bool hasWebcam) { this->hasWebcam = hasWebcam; }

    
    void DisplayInfo() const override {
        PersonalComputer::DisplayInfo();
        cout << ",Размер экрана = " << screenSize << " дюймов, Веб-камера = " << (hasWebcam ? "Yes" : "No");
    }

    bool operator==(const Laptop& other) const {
        return (PersonalComputer::operator==(other) && screenSize == other.screenSize && hasWebcam == other.hasWebcam);
    }

    Laptop operator+(const Laptop& other) const {
        return Laptop(GetModel() + "+" + other.GetModel(), GetPower() + other.GetPower(), GetOperatingSystem() + "+" + other.GetOperatingSystem(), GetRam() + other.GetRam(), screenSize + other.screenSize, hasWebcam || other.hasWebcam);
    }

    Laptop& operator++() {
        screenSize++;
        return *this;
    }

    Laptop operator++(int) {
        Laptop temp = *this;
        ++(*this);
        return temp;
    }
};

class Tablet : public ComputingMachine {
protected:
    string operatingSystem;
    double screenSize;

public:
    Tablet() : ComputingMachine(), operatingSystem(" "), screenSize(0.0) {}

    Tablet(const string& model, int power, const std::string& operatingSystem, double screenSize)
        : ComputingMachine(model, power), operatingSystem(operatingSystem) {
        SetScreenSize(screenSize);
    }

    string GetOperatingSystem() const { return operatingSystem; }
    void SetOperatingSystem(const string& operatingSystem) { this->operatingSystem = operatingSystem; }

    double GetScreenSize() const { return screenSize; }
    void SetScreenSize(double screenSize) {
        if (screenSize >= 0) {
            this->screenSize = screenSize;
        }
        else {
            cout << "Ошибка: Размер экрана должен быть неотрицательным. Значение равно 0." << endl;
            this->screenSize = 0;
        }
    }


    void DisplayInfo() const override {
        ComputingMachine::DisplayInfo();
        cout << ", Операционная система = " << operatingSystem << ", Размер экрана = " << screenSize << " дюймы";
    }

    bool operator==(const Tablet& other) const {
        return (ComputingMachine::operator==(other) && operatingSystem == other.operatingSystem && screenSize == other.screenSize);
    }

    Tablet operator+(const Tablet& other) const {
        return Tablet(GetModel() + "+" + other.GetModel(), GetPower() + other.GetPower(), operatingSystem + "+" + other.operatingSystem, screenSize + other.screenSize);
    }

   
    Tablet& operator++() {
        screenSize++;
        return *this;
    }

    
    Tablet operator++(int) {
        Tablet temp = *this;
        ++(*this);
        return temp;
    }
};


int GetIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Неверный ввод. Пожалуйста, введите целое число." << endl;
        }
        else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

double GetDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Неверный ввод. Пожалуйста, введите номер." << endl;
        }
        else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

struct MachineNode {
    ComputingMachine* data;
    MachineNode* next;
};

void addMachine(MachineNode** head, ComputingMachine* machine) {
    MachineNode* newNode = new MachineNode;
    newNode->data = machine;
    newNode->next = *head;
    *head = newNode;
}

bool deleteMachine(MachineNode** head, int index) {
    if (*head == nullptr) return false;

    if (index == 0) {
        MachineNode* temp = *head;
        *head = (*head)->next;
        delete temp->data;
        delete temp;
        return true;
    }

    MachineNode* current = *head;
    MachineNode* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex != index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) return false;

    previous->next = current->next;
    delete current->data;
    delete current;
    return true;
}

void displayMachines(MachineNode* head) {
    MachineNode* current = head;
    int index = 0;
    while (current != nullptr) {
        std::cout << index++ << ": ";
        current->data->DisplayInfo();
        std::cout << std::endl;
        current = current->next;
    }
}

ComputingMachine* getMachine(MachineNode* head, int index) {
    MachineNode* current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex != index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) return nullptr;

    return current->data;
}

void freeMachines(MachineNode** head) {
    MachineNode* current = *head;
    while (current != nullptr) {
        MachineNode* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    *head = nullptr;
}

int main() {
    MachineNode* machines = nullptr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Добавить новый элемент\n";
        cout << "2. Удалить элемент по индексу\n";
        cout << "3. Вывести все элементы\n";
        cout << "4. Сравнить два элемента на предмет равенства\n";
        cout << "5. Выход\n";

        int choice = GetIntInput("Введите свой выбор: ");

        switch (choice) {
        case 1: {
            cout << "Выберите тип:\n";
            cout << "1. Вычислительная машина\n";
            cout << "2. Персональный компьютер\n";
            cout << "3. Ноутбук\n";
            cout << "4. Планшет\n";
            int typeChoice = GetIntInput("Выберите тип ввода: ");

            string model;
            int power;

            cout << "Введите модель: ";
            cin >> ws; 
            cin >> model;

            power = GetIntInput("Входная мощность (Вт): ");

            switch (typeChoice) {
            case 1: {
                addMachine(&machines, new ComputingMachine(model, power));
                break;
            }
            case 2: {
                string os;
                int ram;
                cout << "Введите операционную систему: ";
                cin >> ws;
                cin >> os;

                ram = GetIntInput("Введите объем оперативной памяти (ГБ): ");

                addMachine(&machines, new PersonalComputer(model, power, os, ram));
                break;
            }
            case 3: {
                string os;
                int ram;
                double screenSize;
                bool hasWebcam;

                cout << "Введите операционную систему: ";
                cin >> ws;
                cin >> os;

                ram = GetIntInput("Введите объем оперативной памяти (ГБ): ");

                screenSize = GetDoubleInput("Введите размер экрана (дюймы): ");

                int webcamChoice = GetIntInput("Есть веб-камера? (1 - Да, 0 - Нет): ");
                hasWebcam = (webcamChoice == 1);

                addMachine(&machines, new Laptop(model, power, os, ram, screenSize, hasWebcam));
                break;
            }
            case 4: {
                string os;
                double screenSize;

                cout << "Введите операционную систему: ";
                cin >> ws;
                cin >> os;

                screenSize = GetDoubleInput("Введите размер экрана (дюймы): ");

                addMachine(&machines, new Tablet(model, power, os, screenSize));
                break;
            }
            default:
                cout << "Неверный выбор типа.\n";
                break;
            }
            break;
        }
        case 2: {
            if (machines == nullptr) {
                cout << "Нет элементов для удаления.\n";
                break;
            }
            int index = GetIntInput("Введите индекс для удаления: ");
            if (deleteMachine(&machines, index)) {
                cout << "Элемент удален.\n";
            }
            else {
                cout << "Неверный индекс.\n";
            }
            break;
        }
        case 3: {
            if (machines == nullptr) {
                cout << "Нет элементов для отображения.\n";
                break;
            }
            cout << "Элементы:\n";
            displayMachines(machines);
            break;
        }
        case 4: {
            MachineNode* current = machines;
            int count = 0;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            if (count < 2) {
                cout << "Необходимо как минимум два элемента для сравнения.\n";
                break;
            }
            int index1 = GetIntInput("Введите индекс первого элемента: ");
            int index2 = GetIntInput("Введите индекс второго элемента: ");

            ComputingMachine* machine1 = getMachine(machines, index1);
            ComputingMachine* machine2 = getMachine(machines, index2);

            if (machine1 != nullptr && machine2 != nullptr) {
                if (*machine1 == *machine2) {
                    cout << "Элементы равны.\n";
                }
                else {
                    cout << "Элементы не равны.\n";
                }
            }
            else {
                cout << "Неверный индекс.\n";
            }
            break;
        }
        case 5: {
            freeMachines(&machines);
            cout << "Выход...\n";
            return 0;
        }
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
