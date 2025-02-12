#include <iostream>
#include <string>
using namespace std;

class Whels {
private:
    string nameWhels;
    int diametr;
    int size;
public:
    string getNameWhels() {
        return nameWhels;
    }

    int getDiametr() {
        return diametr;
    }

    int getSize() {
        return size;
    }

    void setNameWhels(string Whelses) {
        this->nameWhels = Whelses;
    }
    void setDiametr(int dia) {
        this->diametr = dia;
    }
    void setSize(int size) {
        this->size = size;
    }

    void printw() {
        cout << "Название шины: " << nameWhels << "\nДиаметр: " << diametr << "\nШирина: " << size << endl;
    }
};

class Engine {
private:
    string nameEngine;
    double power;
public:
    string getNameEngine() {
        return nameEngine;
    }

    double getPower() {
        return power;
    }

    void setNameEngine(string Engines) {
        this->nameEngine = Engines;
    }
    void setPower(double po) {
        this->power = po;
    }

    void printe() {
        cout << "Название мотора: " << nameEngine << "\nМощность: " << power << endl;
    }
};

class Body {
private:
    string namebody;
    int wheight;
    int hight;
public:
    string getNameBody() {
        return namebody;
    }

    int getWheight() {
        return wheight;
    }

    int getHight() {
        return hight;
    }

    void setNameBody(string bodys) {
        this->namebody = bodys;
    }
    void setWheight(int whe) {
        this->wheight = whe;
    }
    void setHight(int hig) {
        this->hight = hig;
    }

    void printb() {
        cout << "Название кузова: " << namebody << "\nДлина: " << wheight << "\nШирина: " << hight << endl;
    }
};

class Save {
private:
    string nameSave;
    string reliable;
public:
    string getNameSave() {
        return nameSave;
    }

    string getreliable() {
        return reliable;
    }

    void setNameSave(string saves) {
        this->nameSave = saves;
    }
    void setreliable(string re) {
        this->reliable = re;
    }

    void prints() {
        cout << "Название безопасности: " << nameSave << "\nНадёжность: " << reliable << endl;
    }
};

class Car : public Whels, public Engine, public Body, public Save {
public:
    void print() {
        printw();
        printe();
        printb();
        prints();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Car car;
    car.setNameWhels("Мишлен");
    car.setDiametr(18);
    car.setSize(225);

    car.setNameEngine("V8");
    car.setPower(350.0);

    car.setNameBody("Седан");
    car.setWheight(4500);
    car.setHight(1800);

    car.setNameSave("Airbags");
    car.setreliable("Высокий");
    car.print();

    return 0;
}
