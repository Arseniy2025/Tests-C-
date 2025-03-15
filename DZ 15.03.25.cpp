#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UIElement {
public:
    virtual void draw() {};
};

class UIElementButtons : public UIElement {
public:
    bool isFocused;

    void draw() {

    }
};

class UIElementComposable : public UIElement {
public:

    void draw() {

    }
};

class Button : public UIElementButtons {
public:
    int size_x;
    int size_y;
    string text;
    int padding_horizontal;

    Button() {
        size_x = 10;
        size_y = 3;
        text = "Button";
        padding_horizontal = 1;
    }

    Button(string text, int padding_horizontal = 1, int padding_vertical = 1) {
        this->text = text;
        this->padding_horizontal = padding_horizontal;

        this->size_x = text.size() + padding_horizontal * 2 + 2;
        this->size_y = padding_vertical * 2 + 2 + 1;
    }

    void draw() override {
        string textBuffer = this->text;

        //padding > 2 -> Bug
        for (int i = 0; i < size_y; i++) {
            for (int j = 0; j < size_x; j++) {
                if (i == 0 || i == size_y - 1) {
                    cout << '*';
                    continue;
                }

                if (j == 0 || j == size_x - 1) {
                    cout << '*';
                    continue;
                }

                if (i == size_y / 2 && j > padding_horizontal && textBuffer.size() > 0) {
                    cout << textBuffer[0];
                    textBuffer.erase(0, 1);
                    continue;
                }

                cout << " ";
            }
            cout << endl;
        }
    }
};

class CheckBox : public UIElementButtons {
public:
    bool checked;
    int size_x;
    int size_y;
    int padding_horizontal;
    char checked_symbol;
    char unchecked_symbol;

    CheckBox(bool check = false, int size_x = 3, int size_y = 3, int padding_horizontal = 0, char checked_symbol = 'X', char unchecked_symbol = ' ') {
        this->checked = check;
        this->size_x = size_x;
        this->size_y = size_y;
        this->padding_horizontal = padding_horizontal;
        this->checked_symbol = checked_symbol;
        this->unchecked_symbol = unchecked_symbol;
    }

    void draw() override {
        for (int i = 0; i < size_y; ++i) {
            for (int j = 0; j < size_x; ++j) {
                if (i == 0 || i == size_y - 1 || j == 0 || j == size_x - 1) {
                    cout << '*';
                }
                else {
                    if (i == size_y / 2 && j == size_x / 2) {
                        if (checked) {
                            cout << checked_symbol;
                        }
                        else {
                            cout << unchecked_symbol;
                        }
                    }
                    else {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }

    void toggle() {
        checked = !checked;
    }

    void setChecked(bool check) {
        checked = check;
    }

    bool isChecked() {
        return checked;
    }
};

class Text : public UIElement {
public:
    int size_x;
    int size_y;
    string text;
    Text(int size_x, int size_y, string text) {
        this->size_x = size_x;
        this->size_y = size_y;
        this->text = text;
    }
    void draw() override {
        cout << text << endl;
    }
};

class Column : public UIElementComposable {
public:
    vector<UIElement*> components;

    Column(vector<UIElement*> components) {
        for (int i = 0; i < components.size(); i++) {
            this->components.push_back(components[i]);
        }
    }

    void draw() override {
        for (auto& component : components) {
            component->draw();
        }
    }
};

class Row : public UIElementComposable {
public:
    vector<UIElement*> components;

    Row(vector<UIElement*> components) {
        for (int i = 0; i < components.size(); i++) {
            this->components.push_back(components[i]);
        }
    }

    void draw() override {
        for (auto& component : components) {
            component->draw();
            cout << " ";
        }
        cout << endl;
    }
};






class Window {
public:
    int size_x;
    int size_y;
    UIElement* component;

    Window(int size_x, int size_y, UIElement* component) {
        this->size_x = size_x;
        this->size_y = size_y;
        this->component = component;
    }

    void draw() {
        component->draw();
    }
};



int main() {
    setlocale(LC_ALL, "rus");
    Button button1 = Button("First Button", 4);
    Button button2 = Button("Second Button", 5);
    Button button3 = Button("Third Button", 6);
    Text text(10, 4, "Информация");
    CheckBox checkbox1(true, 5, 5, 0, '#', '.');
    CheckBox checkbox2(false, 5, 5, 0, '#', '.');

    Row row({ &button1, &button2, &button3, &text, &checkbox1, &checkbox2 });

    Window screen(100, 100, &row);
    screen.draw();

    checkbox1.toggle();
    cout << "Чекбокс 1 " << (checkbox1.isChecked() ? "проверен" : "непроверенный") << endl;

    checkbox2.setChecked(true);
    cout << "Чекбокс 2 " << (checkbox2.isChecked() ? "проверен" : "непроверенный") << endl;

    return 0;
}


