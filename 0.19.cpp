/*
Напишите функцию, которая в заданной строке, состоящей из слов и знаков препинания, проверит, что все слова одинаковой длины
*/

#include <iostream>
#include <cmath>
using namespace std;

bool check(char* str, int n){
    int counter = 0;
    int index = 0;
    int *array = new int[n]{};
    for (int i = 0;i<n;++i){
        if (str[i] == ' ' || str[i] == '\0'){
            if (counter != 0){
            array[index] = counter;
            if(index > 0 && array[index] != array[index - 1]){
                delete[] array;
                return false;
            }
            ++index;
            counter = 0;
            }
        } else counter++;
    }
    delete[] array;
    return true;
}

int main(){
    char str[] = "qwerty&  qwert*y qw$erty";
    cout << check(str, size(str)) << endl; // 1 | 0 - не равны , 1 - равны
    return 0;
}
