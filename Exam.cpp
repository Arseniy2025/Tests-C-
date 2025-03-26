#include <iostream>
#include <string>
using namespace std;

class PrintedEdition {
public:
    virtual void printinfo() const = 0;
    virtual string getTitle() const = 0;
    friend ostream& operator<<(ostream& os, const PrintedEdition& printededition) {
        printededition.printinfo();
        return os;
    }
};

class Book : public PrintedEdition {
protected:
    string title;
    string author;
public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }
    string getTitle() const override {
        return title;
    }
    string getAuthor() {
        return author;
    }
    void setTitle(string title) {
        this->title = title;
    }
    void setAuthor(string author) {
        this->author = author;
    }

    void printinfo()const override {
        cout << "Книга: " << title << "Автор: " << author << endl;
    }
};

class Newspaper : public PrintedEdition {
protected:
    string title;
    int number;
public:
    Newspaper(string title, int number) {
        this->title = title;
        this->number = number;
    }
    string getTitle()const override {
        return title;
    }
    int getNumber() {
        return number;
    }

    void setTitle(string title) {
        this->title = title;
    }
    void setNumber(int number) {
        this->number = number;
    }


    void printinfo()const override {
        cout << "Газета: " << title << " ,Номер выпуска " << number << endl;
    }
};

class Periodica : public PrintedEdition {
protected:
    string title;
    string freetime;
public:
    Periodica(string title , string freetime) {
        this->title = title;
        this->freetime = freetime;
    }
    string getTitle() const override {
        return title;
    }
    string getFreeTime() {
        return freetime;
    }

    void setTitle(string title) {
        this->title = title;
    }
    void setFreeTime(string freetime) {
        this->freetime = freetime;
    }

    void printinfo()const override {
        cout << "Периодика " << title << ", Частота выхода " << freetime << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    Book book1("Война и Мир", "Л.Н.Толстой");
    Newspaper newspaper1("Цифровые технологии", 234);
    Periodica periodica1("Наука", "Ежемесячно");
    book1.printinfo();
    newspaper1.printinfo();
    periodica1.printinfo();
    return 0;
}

