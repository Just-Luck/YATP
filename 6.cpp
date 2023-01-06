#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int main(){
    char mystring[] = "string";
    cout << sizeof(mystring) << endl;
    // Вывод 7 | string - 6 символов + '\0' (нуль-терминатор)

    char str2[50];

    //#include <cstring>
    strcpy_s(str2, mystring);
    cout << str2 << endl; // string

    cout << strlen(str2) << endl; // 6 | длина без '\0'

    strcat(str2, " test");
    cout << str2 << endl; // string test

    strncat(str2, " test2" , 10);
    cout << str2 << endl; // string test test2

    bool check = strcmp(mystring,str2); // 1 - false | 0 - true
    cout << check << endl; // 1

    bool check2 = strncmp(mystring,str2 , 6); // 1 - false | 0 - true | 3 параметр кол-во символов
    cout << check2 << endl; // 0

    //#include <string>
    string a = "qwerty";
    cout << a.capacity() << endl; // 15 | вместимость

    cout << a.empty() << endl; // 0 - false | 1 - true | проверка на пустоту

    cout << a.length() << endl; // 6 | длина
    cout << a.size() << endl; // 6 | длина

    cout << a.max_size() << endl; // 4611686018427387903 | максимальный размер

    cout << a[2] << endl; // e | 3 символ строки
    cout << a.at(2) << endl; // e | 3 символ строки

    a.clear(); // очистка строки
    cout << a << endl; // ' '

    /*
    assign() — присваивают новое значение строке
    append(), push_back() — добавляют символы к концу строки
    insert() — вставляет символы в произвольный индекс строки
    replace() — заменяет символы произвольных индексов строки другими символами
    swap() — меняет местами значения двух строк
    c_str() — конвертирует строку в строку C-style с нуль-терминатором в конце
    copy() — копирует содержимое строки (которое без нуль-терминатора) в массив типа char
    data() — возвращает содержимое строки в виде массива типа char, который не заканчивается нуль-терминатором
    */

    string b = "qwerty";
    string c = "qwerty";
    string d = "qwerty11";
    cout << b.compare(c) << endl; // 0 - равны
    cout << b.compare(d) << endl; // -2 | на сколько символов они не равны
    cout << d.compare(b) << endl; // 2 | на сколько символов они не равны

    cout << b.find('e') << endl; // 2 | индекс искомого символа
    cout << b.find_first_of ("wrty") << endl; // 1 | ищет индекс первого символа из набора символов

    return 0;
}