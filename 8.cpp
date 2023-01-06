#include <iostream>
#include <cmath>
using namespace std;

void printError(string s){
    cout << s << endl;
}

int square(int a){
    a = a * a;
    return a;
}

int square2(int &a){
    a = a * a;
    return a;
}

int main(){
    printError("Test error");
    int a = 10;
    cout << "func result = " << square(a) << " a = " << a << endl; // 100 | a = 10
    cout << "func2 result = " << square2(a) << " a = " << a << endl; // 100 | a = 100
    return 0;
}