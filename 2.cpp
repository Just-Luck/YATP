#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

void generator(int *array ,int n){
    if (n < 1) return;
    //array[0] = 1;
    for (int i = 0; i < n; ++i){
        int number_len_i = 1 + 2*(i - 1);
        string number;
        for (int left = 0; left < i + 1; ++left) number += to_string(left + 1);
        for (int right = number_len_i; right > i - 1; --right) number += to_string(right - i + 1);
        array[i] = stoi(number);
    }
}

int main(){
    int n = 5;
    int *array = new int[n+1]{};
    generator(array,n);

    for (int i = 0;i < n; ++i){
        cout << array[i] << " ";
    }

    return 0;
}