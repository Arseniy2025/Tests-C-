#include <iostream>
#include <string>
using namespace std;

class Footwear {
private:
    string brand;
    string model;
    double price;
    int size;

public:
    Footwear() {
        brand = "";
        model = "";
        price = 0.0;
        size = 0;
    }

    Footwear(string brand, string model, double price, int size) {
        this->brand = brand;
        this->model = model;
        this->price = price;
        this->size = size;
    }

    void displayInfo() {
        cout << "Бренд: " << brand;
        cout << ", Модель: " << model;
        cout << ", Цена: $" << price;
        cout << ", Размер: " << size << endl;
    }
};

class Accessory {
private:
    string type;
    double price;

public:
    Accessory() {
        type = "";
        price = 0.0;
    }

    Accessory(string type, double price) {
        this->type = type;
        this->price = price;
    }

    void displayInfo() {
        cout << "Тип Носка: " << type;
        cout << ", Цена: $" << price << endl;
    }
};

class Shop {
private:
    string name;
    string location;
    Footwear footwearList[10];
    Accessory accessoryList[10];
    int footwearCount;
    int accessoryCount;

public:
    Shop(string name, string location) {
        this->name = name;
        this->location = location;
        this->footwearCount = 0;
        this->accessoryCount = 0;
    }


    bool addFootwear(Footwear footwear) {
        if (footwearCount < 10) {
            footwearList[footwearCount] = footwear;
            footwearCount++;
            return true;
        }
        return false;
    }

    bool addAccessory(Accessory accessory) {
        if (accessoryCount < 10) {
            accessoryList[accessoryCount] = accessory;
            accessoryCount++;
            return true;
        }
        return false;
    }

    void displayInventory() {
        cout << "Магазин: " << name << " | Местоположение: " << location << endl;
        cout << "Инвентарь для обуви:" << endl;
        for (int i = 0; i < footwearCount; ++i) {
            footwearList[i].displayInfo();
        }
        cout << "Инвентарь для Носков:" << endl;
        for (int i = 0; i < accessoryCount; ++i) {
            accessoryList[i].displayInfo();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Shop shop("Магазин", "Москва");


    Footwear nike("Nike", "Air Max", 100.0, 38);
    Footwear adidas("Adidas", "Gazelle", 85.0, 39);

    shop.addFootwear(nike);
    shop.addFootwear(adidas);

    Accessory bag("Носок 1", 50.0);
    Accessory scarf("Носок 2", 20.0);

    shop.addAccessory(bag);
    shop.addAccessory(scarf);

    shop.displayInventory();

    return 0;
}
