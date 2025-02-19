#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(const string& name, double salary) {
        this->name = name;
        this->salary = salary;
    }


    virtual double Bonus() {
        return 0.0;
    }


    friend void printEmployeeInfo(Employee& employee);

   

    string getName() { return name; }
    double getSalary() { return salary; }
};

class Manager : public Employee {
private:
    int Subordinates;

public:
    Manager(const string& name, double salary, int Subordinates)
        : Employee(name, salary), Subordinates(Subordinates) {}

    double Bonus() {
        return getSalary() * 0.1 * Subordinates;
    }
};

class Developer : public Employee {
private:
    int Projects;

public:
    Developer(const string& name, double salary, int Projects)
        : Employee(name, salary), Projects(Projects) {}

    double Bonus() {
        return getSalary() * 0.05 * Projects;
    }
};

class Intern : public Employee {
private:
    int Duration;

public:
    Intern(const string& name, double salary, int Duration)
        : Employee(name, salary), Duration(Duration) {}

    double Bonus() {
        if (Duration > 3) {
            return 1000.0;
        }
        else {
            return 0.0;
        }
    }
};

void print(Employee& employee) {
    cout << "Имя: " << employee.getName() << ",Зарплата : " << employee.getSalary()
        << ", Бонус: " << employee.Bonus() << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Manager manager("Алан Вэйк", 5000, 5);
    Developer developer("Райн Купер", 4000, 3);
    Intern intern("Гордон Фримен", 1000, 4);

    print(manager);
    print(developer);
    print(intern);

    return 0;
}
