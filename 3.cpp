#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a = 0;
    if (a == 0){
        cout << "Zero" << endl;
    } else if(a == 1){
        cout << "One" << endl;
    } else {
        cout << "Two" << endl;
    }
    
    int b = 0;
    bool b2 = b == 0 ? true : false;
    cout << b2 << endl;

    int c = 0; 
    switch (c) // only int type or arrays
    {
    case 0:
        cout << "0 floor" << endl;
        break;
    case 1:
        cout << "1 floor" << endl;
        break;
    case 2:
        cout << "2 floor" << endl;
        break;
    default:
        cout << "err floor" << endl;
        break;
    }

    return 0;
}
