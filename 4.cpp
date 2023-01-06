#include <iostream>
#include <cmath>
using namespace std;

int main(){

    // for(;;) - бесконечный цикл
    // while (true) - бесконечный цикл

    for (int counter = 0; counter <= 10; ++counter){
        cout << counter << endl;
    }
    // 0 1 2 3 4 5 6 7 8 9 10

    int counter = 0;
    while (counter <= 10){
        cout << counter << endl;
        counter++;
    }
    // 0 1 2 3 4 5 6 7 8 9 10
    int counter2 = 0;
    do {
        cout << counter2 << endl;
        counter2++;
    } while (counter2 <= 10);
    //Выполняеться тело, а потом проверяется условие
    // 0 1 2 3 4 5 6 7 8 9 10

    
    return 0;
}