#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int* pInt = new int;
    int* pTestInt = new int;
    *pInt = 1;
    *pTestInt = 2;
    cout << *pInt << endl; // 1
    cout << *pTestInt << endl; // 2

    const int* pInt1 = pInt; // !Указатель на константу!
    cout << *pInt1 << endl; // 1

    pInt1 = pTestInt; // Несмотря на константность значение удалось поменять
    cout << *pInt1 << endl; // 2
    pInt1 = new int(3); // Несмотря на константность значение удалось поменять
    cout << *pInt1 << endl; // 3

    //*pInt1 = 3; // Выдает ошибку

    int* const pInt2 = pInt; // !Константный указатель!
    cout << *pInt2 << endl; // 1

    *pInt2 = 5;
    cout << *pInt2 << endl; // 5

    //pInt2 = pTestInt; // Выдает ошибку
    //pInt2 = new int(3); // Выдает ошибку

    const int* const pInt3 = pInt; // !Константный указатель на константу!
    //Для такой структуры способов изменить переменную есть, но её можно прочитать:
    int x = *pInt3;
    cout << x << endl; // 5
    
    return 0;
}