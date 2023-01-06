#include <iostream>
#include <cmath>
#include <string>
#include <fstream> // для работы с файлами
using namespace std;

int fileread(){
    FILE * ptrFile = fopen("7.txt" , "rb");
    int n = 200;
    char* buffer3 = new char[n+1];
    buffer3[n]=0;

    size_t result = fread(buffer3, 1, n, ptrFile); // считываем файл в буфер

    puts(buffer3); // помещаем содержимое файла в buffer3
    
    fclose(ptrFile);
    delete [] buffer3;

    return 0;
}

int main(){
    ifstream file ("7.txt");
    cout << file.is_open() << endl; // 1 | 1 - открыт 0 - закрыт

    string s; 
    getline(file,s); // читает 1 строку
    cout << s << endl; // qwerty file

    int n = 50;
    //Создаем буффер для чтения
    char* buffer = new char[n+1];
    buffer[n]=0;
    
    cout << " - - - - -" << endl;

    file.get(buffer,n); // считываем n символов
    cout << buffer; // test | выводим считанное | выводит 2 строку тк 1 строка была считана выше
    file.getline(buffer,n,' '); // чтение до первого пробела
    cout << buffer << endl; //abcdefg | выводим считанное
    delete [] buffer; //Освобождаем буффер

    cout << " - - - - -" << endl;

    int n2=50;
    //Создаем буффер
    char* buffer2=new char[n2+1]; 
    buffer2[n2]=0;
    file.read(buffer2,n2); // считывает нужное кол-во байт
    cout << buffer2 << endl; //выводит все строки , но не превышая требуемые кол-во байт
    delete [] buffer2;

    cout << file.eof() << endl; // 0 | 0 - не конец файла 1 - конец файла -1 - ошибка

    file.close(); // закрытие файла

    fileread(); // считывание бинарного файла
    return 0;
}

