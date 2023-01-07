#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int *ptr = new int; // для ptr выделяется 4 байта из кучи
    int *array = new int[10]; // для array выделяется 40 байт из кучи
    char *str = new char; // для str выделяется 1 байт из кучи

    // int stack[1000000000]; - переполнение стека

    int value = 1;

    int *a; // объявление указателя
    a = &value; // присваивание указателю значиние
    cout << *a << endl; // 1

    int &b = value; // объявление ссылки и присваивание ей значение
    cout << b << endl; // 1

    b++;
    cout << b << endl; // 2
    cout << value << endl; // 2

    char* arr = new char[25]; // создание массива с резервированием памяти
    delete [] arr; // удаление массива и освобождение памяти

    int *value2 = new (nothrow) int; // запрос на выделение динамической памяти для целочисленного значения
    if (!value2) cout << "Could not allocate memory"; // если память не удалось выделить
    else cout << "All is ok!"; // Удачное выделение памяти
    return 0;
}