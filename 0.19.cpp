#include <iostream>
#include <cmath>
using namespace std;

bool check(char* str, int n){
    int counter = 0;
    int index = 0;
    int array[n] = {};
    for (int i = 0;i<n;++i){
        if (str[i] == ' ' || str[i] == '\0'){
            array[index] = counter;
            if(index > 0 && array[index] != array[index - 1]) return false;
            ++index;
            counter = 0; 
        } else counter++;
    }
    return true;
}

int main(){
    char str[] = "qwerty qwerty qwerty";
    cout << check(str, size(str)) << endl; 
    return 0;
}