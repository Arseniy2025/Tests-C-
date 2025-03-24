#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    virtual void printInfo() = 0;
    virtual string getName() = 0;
    friend ostream& operator<<(ostream& os, Person& person) {
        person.printInfo();
        return os;
    }
};

class Student : public Person {
protected:
    string name;
    int year;
    string group;
public:
    Student(string name, int year, string group) {
        this->name = name;
        this->year = year;
        this->group = group;
    }

    string getName() override {
        return name;
    }

    int getYear() {
        return year;
    }

    string getGroup() {
        return group;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setGroup(string group) {
        this->group = group;
    }

    void printInfo() override {
        cout << "Студент: " << name << ", Год обучения: " << year << ", Группа: " << group << endl;
    }
};

class ExpelledStudent : public Student {
private:
    string reason;
public:
    ExpelledStudent(string name, int year, string group, string reason) : Student(name, year, group) {
        this->reason = reason;
    }

    string getReason() {
        return this->reason;
    }

    void setReason(string reason) {
        this->reason = reason;
    }

    void printInfo() override {
        cout << "Отчисленный студент: " << this->name << ", Бывшая группа: " << this->group<<", Год обучения " <<this->year <<", Причина отчисления: " << this->reason << endl;
    }
};

class Classroom {
public:
    string number;
    int capacity;
    Student* students[50];
    int studentCount;
public:
    Classroom(){
        this->number = "";
        this->capacity = 0;
        this->studentCount = 0;
        for (int i = 0; i < 50; i++) {
            students[i] = nullptr;
        }
    }

    Classroom(string number, int capacity) {
        this->number = number;
        this->capacity = capacity;
        this->studentCount = 0;
        for (int i = 0; i < 50; i++) {
            students[i] = nullptr;
        }
    }

    string getNumber() {
        return number;
    }

    int getCapacity() {
        return capacity;
    }

    void addStudent(Student* student) {
        if (student == nullptr) {
            cout << "Ошибка: попытка добавить nullptr студента" << endl;
            return;
        }

        if (studentCount < capacity && studentCount < 50) {
            students[studentCount++] = student;
        }
        else {
            cout << "Аудитория " << number << " заполнена!" << endl;
        }
    }

    void printInfo() {
        cout << "Аудитория № " << number << ", Вместимость: " << capacity << ", Студентов: " << studentCount << endl;
        cout << "Список студентов:" << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i]->printInfo();
        }
    }
};

class AlexeySotnikov : public Student {
private:
    string nickname;
public:
    AlexeySotnikov(int year, string group) : Student("Алексей Сотников", year, group) {
        this->nickname = "Кощей";
    }

    string getNickname() {
        return nickname;
    }

    void printInfo() override {
        cout << "Студент: " << name << " (известный как " << nickname << "), Год обучения: " << year << ", Группа: " << group << endl;
    }
};

class College {
public:
    string name;
    Classroom classrooms[10];
    int classroomCount;
    Student* students[100];
    int studentCount;
public:
    College(string name){
        this->name = name;
        this->classroomCount = 0;
        this->studentCount = 0;
        for (int i = 0; i < 100; i++) {
            students[i] = nullptr;
        }
    }

    void addClassroom(Classroom classroom) {
        if (classroomCount < 10) {
            classrooms[classroomCount++] = classroom;
        }
        else {
            cout << "Достигнуто максимальное количество аудиторий!" << endl;
        }
    }

    void addStudent(Student* student) {
        if (student == nullptr) {
            cout << "Ошибка: попытка добавить nullptr студента" << endl;
            return;
        }

        if (studentCount < 100) {
            students[studentCount++] = student;
        }
        else {
            cout << "Достигнуто максимальное количество студентов!" << endl;
        }
    }

    void printInfo() {
        cout << "Колледж: " << this->name << endl;
        cout << "Количество аудиторий: " << this->classroomCount << endl;
        cout << "Количество студентов: " << this->studentCount << endl;

        cout << "\nАудитории:" << endl;
        for (int i = 0; i < this->classroomCount; i++) {
            this->classrooms[i].printInfo();
        }

        cout << "\nВсе студенты:" << endl;
        for (int i = 0; i < this->studentCount; i++) {
            this->students[i]->printInfo();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Student student1("Иван Петров", 2, "П-21");
    Student student2("Мария Сидорова", 1, "П-22");
    AlexeySotnikov alexey(3, "П-20");
    ExpelledStudent expelled("Василий Кузнецов", 2, "П-21", "академическая неуспеваемость");

    Classroom classroom1("101", 30);
    Classroom classroom2("205", 25);

    classroom1.addStudent(&student1);
    classroom1.addStudent(&alexey);
    classroom2.addStudent(&student2);

    College college("Политехнический колледж");

    college.addClassroom(classroom1);
    college.addClassroom(classroom2);
    college.addStudent(&student1);
    college.addStudent(&student2);
    college.addStudent(&alexey);
    college.addStudent(&expelled);

    cout << "=== Информация о студентах ===" << endl;
    student1.printInfo();
    student2.printInfo();
    alexey.printInfo();
    expelled.printInfo();

    cout << "\n=== Информация о колледже ===" << endl;
    college.printInfo();

    return 0;
}
