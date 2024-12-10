#include<iostream>
#include<string>
using namespace std;

string* returnTest(string& str) {
    string* stringPtr = new string; //Создание памяти под string по адресу 00000ABCX54                                             <- пример выполнения, адреса брать настоящие
    *stringPtr = str; //Берем по адресу 00000ABCX54 значение и устанавливаем его в "test" по адресу str            <- пример выполнения, адреса брать настоящие
    return stringPtr;// Возвращает stringPtr
}

int main()
{
    string str = "test";// создаётся строка test
    string* newStr = returnTest(str);//Вызывается функция returnTest. И возвращает tringPtr

    cout << newStr << endl;//Выводится адрес, хранящийся в newStr
    cout << *newStr << endl;// Выводится значение, хранящееся по адресу, на который указывает newStr
    cout << &*newStr << endl;//*newStr разыменовывает указатель, получая строку. & берет адрес этой строки, который равен
    cout << *&*newStr << endl;//*&*newStr эквивалентно *newStr, поэтому выводится "test"
    cout << &*&*newStr << endl;// Эквивалентно &*newStr, выводится 0000018875A23320 
    cout << *&*&*newStr << endl;//Эквивалентно *newStr, выводится "test".
}
