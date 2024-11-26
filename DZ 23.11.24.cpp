#include <iostream> 
 
using namespace std; 
 
struct Node{ 
  int value;     
  Node* next = nullptr; 
}; 
 
Node* InitializeList(int size){ 
  Node* head = new Node(); // Создаем голову списка 
  Node* current = head; //Текущий элемент = голова списка 
  current->value = 0; //Значение текущего элемента = 0 
  for (int i = 0; i < size-1; i++){ 
    current->next = new Node(); //В поле next как указатель на следующий элемент указываем следующий элемент 
    current = current->next; //Текущий элемент = следующий за текущим 
    current->value = 0;  //value у текущего элемента = 0 
  } 
  return head; //Возвращаем голову списка 
} 
 
Node* InitializeList(int size, int defaultValue){ 
  Node* head = new Node(); // Создаем голову списка 
  Node* current = head; //Текущий элемент = голова списка 
  current->value = defaultValue; //Значение текущего элемента = 0 
  for (int i = 0; i < size-1; i++){ 
    current->next = new Node(); //В поле next как указатель на следующий элемент указываем следующий элемент 
    current = current->next; //Текущий элемент = следующий за текущим 
    current->value = defaultValue;  //value у текущего элемента = 0 
  } 
  return head; //Возвращаем голову списка 
} 
 
void PrintList(Node* head){ 
  Node* current = head; 
  while (current != nullptr){ 
    cout << current->value << " "; 
    current = current->next; 
  } 
  cout << endl; 
} 
 
 
 
int MaxOfList(Node* head){ 
    if (head==nullptr){ 
        return -1; 
    } 
    int maxValue=head->value; 
    Node* current=head; 
    while (current !=nullptr){ 
        if(current->value > maxValue){ 
            maxValue=current->value; 
        } 
        current=current->next; 
    } 
    return maxValue; 
} 
 
 
 
 
int MinOfList(Node* head){ 
    if (head==nullptr){ 
        return 1; 
    } 
    int minValue=head->value; 
    Node* current=head; 
    while (current != nullptr){ 
        if(current->value<minValue){ 
            minValue=current->value; 
        } 
        current=current->next; 
    } 
    return minValue; 
} 
 
 
 
 
int SumOfList(Node* head){ 
    int sum; 
    Node* current=head; 
    while (current != nullptr){ 
        sum+=current->value; 
        current=current->next; 
    } 
    return sum; 
} 
 
 
 
 
 
bool ContainsList(Node* head, int targetValue){ 
    Node* current=head; 
    while (current != nullptr){ 
        if (current -> value == targetValue){ 
            return true; 
        } 
        current = current->next;  
    } 
    return false; 
} 
 
 
 
Node* DeleteElementFromList(Node* head, int index){ 
    if (head==nullptr){ 
        return nullptr; 
    } 
    if (index==0){ 
        Node* newHead=head->next; 
        delete head; 
        return newHead; 
    } 
    Node* current=head; 
    for (int i=0;current!=nullptr && i<index -1;i++){ 
        current=current->next; 
    } 
    if(current==nullptr || current->next==nullptr){ 
        cout<<"Индекс вне диапозона"<<endl; 
        return head; 
    } 
    Node* next = current->next->next; 
    delete current->next; 
    current->next=next; 
    return head; 
     
} 
 
Node* CopyList(Node* head){ 
    if (head==nullptr){ 
        return nullptr; 
    } 
    Node* newHead=new Node{head->value}; 
    Node* currentNew=newHead; 
    Node* currentOld=head->next; 
    while(currentOld != nullptr){ 
        currentNew->next=new Node{currentOld->value}; 
        currentNew=currentNew->next; 
        currentOld=currentOld->next; 
    } 
    currentNew->next=nullptr; 
    return newHead; 
     
} 
 
 
void SwapList(Node* head, int index1, int index2){ 
    if(index1==index2){ 
        return; 
    } 
    Node* prev1 = nullptr; 
    Node* curr1 = head; 
    for(int i=0; curr1 != nullptr && i<index1; i++){ 
        prev1=curr1; 
        curr1= curr1->next; 
    } 
    Node* prev2 = nullptr; 
    Node* curr2 = head; 
    for(int i=0; curr2 != nullptr && i<index2; i++){ 
        prev2=curr2; 
        curr2= curr2->next; 
    } 
    if(curr1==nullptr||curr2==nullptr){ 
        return; 
    } 
    if (prev1 != nullptr){ 
        prev1->next=curr2; 
    }else{
    head=curr2; 
    } 
    if (prev2 != nullptr){ 
        prev2->next=curr1; 
    }else{ 
        head=curr1; 
    } 
    Node* temp = curr1->next; 
    curr1->next = curr2->next; 
    curr2->next=temp; 
} 
 
void DeleteList(Node* head){ 
    while (head != nullptr){ 
        Node* temp=head; 
        head=head->next; 
        delete temp; 
    } 
} 
 
 
Node* StaticArrayToList(int array[], int size){ 
    if (size<=0){ 
        return nullptr; 
    } 
    Node* head = new Node(array[0]); 
    Node* current=head; 
    for(int i=1; i<size;i++){ 
        current->next=new Node{array[i]}; 
    } 
    return head; 
} 
 
 
Node* DynamicArrayToList(int* array, int size){ 
    if (size<=0 || array ==nullptr){ 
        return nullptr; 
    } 
    Node* head = new Node(array[0]); 
    Node* current=head; 
    for(int i=1; i<size;i++){ 
        current->next=new Node{array[i]}; 
    } 
    return head; 
} 
 
 
 
 
 
 
int GetByIndexList(Node* head, int index){ 
  Node* current = head; 
  while (current != nullptr){ 
    if (index == 0){ 
        return current->value; 
    } 
    index--; 
    current = current->next; 
  } 
  return -1; 
} 
 
int main()  
{ 
    Node* test = InitializeList(5, 1); 
  
    cout << "Max: "<<MinOfList<<endl; 
    cout << "Min: "<<MinOfList<<endl;   
    cout << "Сумма: "<<SumOfList<<endl; 
    int target=1; 
    cout<<(ContainsList(test,target) ? "Список содержит элемент" + to_string(target):"Список не содержит элемент"+to_string(target))<<endl; 
    test=DeleteElementFromList(test,2); 
    PrintList(test); 
    Node* compiled=CopyList(test); 
    PrintList(compiled); 
    DeleteList(test); 
    PrintList(compiled); 
    return 0; 
     
}
