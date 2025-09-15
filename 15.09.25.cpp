#include <iostream> 
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
};

Node* InitializeList(int size) {
   
    Node* head = new Node(); 
    head->value = 0;
    Node* current = head; 

    for (int i = 1; i < size; i++) {
        current->next = new Node(); 
        current = current->next; 
        current->value = 0;
    }
    return head;  
}

Node* InitializeList(int size, int defaultValue) {

    Node* head = new Node();  
    head->value = defaultValue;
    Node* current = head;  

    for (int i = 1; i < size; i++) {
        current->next = new Node(); 
        current = current->next; 
        current->value = defaultValue;
    }
    return head; 
}

void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int MaxOfList(Node* head) {
    if (head == nullptr) {
        return -1;
    }
    int maxValue = head->value;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->value > maxValue) {
            maxValue = current->value;
        }
        current = current->next;
    }
    return maxValue;
}

int MinOfList(Node* head) {
    if (head == nullptr) {
        return -1;
    }
    int minValue = head->value;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->value < minValue) {
            minValue = current->value;
        }
        current = current->next;
    }
    return minValue;
}

int SumOfList(Node* head) {
    int sum = 0; 
    Node* current = head;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

bool ContainsList(Node* head, int targetValue) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == targetValue) {
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* DeleteElementFromList(Node* head, int index) {
    if (head == nullptr) {
        return nullptr;
    }
    if (index == 0) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Индекс вне диапазона" << endl;
        return head;
    }

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return head;
}

Node* CopyList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* newHead = new Node();
    newHead->value = head->value;
    Node* currentNew = newHead;
    Node* currentOld = head->next;

    while (currentOld != nullptr) {
        currentNew->next = new Node();
        currentNew = currentNew->next;
        currentNew->value = currentOld->value;
        currentOld = currentOld->next;
    }

    return newHead;
}

void SwapList(Node* head, int index1, int index2) {
    if (index1 == index2) {
        return;
    }

    
    Node* node1 = head;
    Node* node2 = head;

    for (int i = 0; i < index1 && node1 != nullptr; i++) {
        node1 = node1->next;
    }

    for (int i = 0; i < index2 && node2 != nullptr; i++) {
        node2 = node2->next;
    }

    if (node1 == nullptr || node2 == nullptr) {
        cout << "Индекс вне диапазона" << endl;
        return;
    }

    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void DeleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* StaticArrayToList(int array[], int size) {
    if (size <= 0) {
        return nullptr;
    }

    Node* head = new Node();
    head->value = array[0];
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node();
        current = current->next;
        current->value = array[i];
    }

    return head;
}

Node* DynamicArrayToList(int* array, int size) {
    if (size <= 0 || array == nullptr) {
        return nullptr;
    }

    Node* head = new Node();
    head->value = array[0];
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node();
        current = current->next;
        current->value = array[i];
    }

    return head;
}

int GetByIndexList(Node* head, int index) {
    Node* current = head;
    int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) {
            return current->value;
        }
        currentIndex++;
        current = current->next;
    }

    cout << "Индекс вне диапазона" << endl;
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* test = InitializeList(5, 1);

    cout << "Список: ";
    PrintList(test);

    cout << "Max: " << MaxOfList(test) << endl;
    cout << "Min: " << MinOfList(test) << endl;
    cout << "Сумма: " << SumOfList(test) << endl;

    int target = 1;
    if (ContainsList(test, target)) {
        cout << "Список содержит элемент " << target << endl;
    }
    else {
        cout << "Список не содержит элемент " << target << endl;
    }

    cout << "Удаляем элемент с индексом 2: ";
    test = DeleteElementFromList(test, 2);
    PrintList(test);

    cout << "Копия списка: ";
    Node* compiled = CopyList(test);
    PrintList(compiled);

    cout << "Меняем местами элементы 0 и 2: ";
    SwapList(test, 0, 2);
    PrintList(test);

    cout << "Элемент с индексом 1: " << GetByIndexList(test, 1) << endl;

    DeleteList(test);
    DeleteList(compiled);

    return 0;
}

