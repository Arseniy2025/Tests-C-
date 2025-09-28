#include <iostream>
#include <unordered_map>
using namespace std;

class PhoneBook {
private:
    unordered_map<string, string> contacts;

public:
    void addContact(const string& name, const string& phone) {
        contacts[name] = phone;
        cout << "Контакт '" << name << "' добавлен." << endl;
    }

    void DeleteContact(const string& name) {
        if (contacts.count(name) > 0) {
            contacts[name] = ""; 
            unordered_map<string, string> newContacts;
            for (auto& contact : contacts) {
                if (contact.first != name && contact.second != "") {
                    newContacts[contact.first] = contact.second;
                }
            }
            contacts = newContacts;
            cout << "Контакт '" << name << "' удален." << endl;
        }
        else {
            cout << "Контакт '" << name << "' не найден." << endl;
        }
    }

    void findContact(const string& name) {
        string phone = contacts[name];
        if (phone != "") {
            cout << "Контакт найден: " << name << " - " << phone << endl;
        }
        else 
            cout << "Контакт '" << name << "' не найден." << endl;
            
        
    }

    void AllContacts() {
        int count = 0;
        for (const auto& contact : contacts) {
            if (contact.second != "") {
                count++;
            }
        }

        if (count == 0) {
            cout << "Телефонная книга пуста." << endl;
            return;
        }

        cout << "Все контакты:" << endl;
        for (const auto& contact : contacts) {
            if (contact.second != "") {
                cout << contact.first << " - " << contact.second << endl;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    PhoneBook phoneBook;

    phoneBook.addContact("Никита", "+7-423-456-7658");
    phoneBook.addContact("Иван", "+7-987-654-3466");
    phoneBook.addContact("Илья", "+7-545-345-4564");

    cout << "\n";

    phoneBook.findContact("Иван");
    phoneBook.findContact("Петр");

    cout << "\n";

    phoneBook.AllContacts();

    cout << "\n";

    phoneBook.DeleteContact("Иван");
    phoneBook.DeleteContact("Петр");

    cout << "\n";
    phoneBook.AllContacts();

    return 0;
}
