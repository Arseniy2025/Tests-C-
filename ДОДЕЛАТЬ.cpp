#include <iostream>
#include <string>
using namespace std;


class Animal {
public:
    virtual string getPol() = 0;
    virtual string getName() = 0;
    virtual int getCount() = 0;
    virtual int getHp() = 0;
    virtual int getSpeed() = 0;
    virtual int getDamage() = 0;
    virtual string getDiet() = 0;
    virtual int getGrowth() = 0;
    
};

class Trav : Animal {
    string pol;
    string name;
    int count;
    int Hp;
    int speed;
    int damage;
    string diet;
    int growth;
    int hunger;
public:
    string getPol() { return pol; }
    string getName() { return name; }
    int getCount() { return count; }
    int getHp() { return Hp; }
    int getSpeed() { return speed; }
    int getDamage() { return damage; }
    string getDiet() { return diet; }
    int getGrowth() { return growth; }
    
    void eat(){
        if (hunger > 0) {
            hunger--;
        }
    }

    void reproduction() {
        if (hunger == 0 && pol == "Female") {
            count += growth;
        }
    }


    void decreaseCount() {
        if (count > 0) {
            count--;
        }
    }
    void increaseCount(int amount) {
        count += amount;
    }

    void decreaseHp(int amount) {
        Hp -= amount;
        if (Hp < 0) {
            Hp = 0;
        }
    }

    bool isHungry(){
        return hunger > 0;
    }
};



class Predator : Animal {
    string pol;
    string name;
    int count;
    int Hp;
    int speed;
    int damage;
    string diet;
    int growth;
    int hunger;
public:
    string getPol() { return pol; }
    string getName() { return name; }
    int getCount() { return count; }
    int getHp() { return Hp; }
    int getSpeed() { return speed; }
    int getDamage() { return damage; }
    string getDiet() { return diet; }
    int getGrowth() { return growth; }

    void eat() {
        if (hunger > 0) {
            hunger--;
        }
    }

    void reproduction() {
        if (hunger == 0 && pol == "Female") {
            count += growth;
        }
    }

    void decreaseCount() {
        if (count > 0) {
            count--;
        }
    }
    void increaseCount(int amount) {
        count += amount;
    }

    void decreaseHp(int amount) {
        Hp -= amount;
        if (Hp < 0) {
            Hp = 0;
        }
    }

    bool isHungry() {
        return hunger > 0;
    }
};

class Plant {
private:
    string name;
    string type;
    bool edibility;
    int col;
    bool eatsAnimal;
public:
    string getName() { return name; }
    string getType() { return type; }
    bool getEdibility() { return edibility; }
    int getCol() { return col; }
    bool geteatsAnimal() { return eatsAnimal; }

    void decreaseCount() {
        if (col > 0) {
            col--;
        }
    }
    void increaseCount(int amount) {
        col += amount;
    }

    void eatAnimal() {
        if (eatsAnimal) {
            cout << name << " " << endl;
        }
    }
};




class Ecosystem {
private:
    Trav* herbivores [10];
    Predator* predators [10];
    Plant* plants[10];
    int herbovoreCount;
    int predatorCount;
    int plantCount;
public:
    Ecosystem() : herbovoreCount(0), predatorCount(0),plantCount(0){}
    void addherbovore(Trav* herbivore) {
        if (herbovoreCount < 10) {
            herbivore = herbivores[herbovoreCount++];
        }
    }

    void addpredator(Predator* predator) {
        if (predatorCount < 10) {
            predator = predators[predatorCount++];
        }
    }

    void addplant(Plant* plant) {
        if (plantCount < 10) {
            plant = plants[plantCount++];
        }
    }

    void simulate() {
        while (true) {
            for (int i = 0; i < herbovoreCount; i++) {
                if (herbivores[i]->isHungry()) {
                    for (int j = 0; j < plantCount;j++) {
                        if (plants[j]->getEdibility() && plants[j]->getCol() > 0) {
                            herbivores[i]->eat();
                            plants[j]->decreaseCount();
                            break;
                        }
                    }
                }
            }

            for (int i = 0; i < predatorCount; i++) {
                if (predators[i]->isHungry()) {
                    int preyindex = rand() % herbovoreCount;
                    Trav* prey = herbivores[preyindex];
                    predators[i]->eat();
                    prey->decreaseCount();
                }
            }



        }
    }









};





int main() {
    setlocale(LC_ALL, "rus");



}
