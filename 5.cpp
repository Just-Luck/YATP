#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int array[] = {1,2,3,4,5};
    for (int i=0; i < 5; ++i){
        cout << array[i] << endl;
    }
    // 1 2 3 4 5
    int array2[5] = {};
    for (int i=0; i < 5; ++i){
        cout << array2[i] << endl;
    }
    // 0 0 0 0 0

    int array3[2][5] = {
        {1,2,3,4,5},
        {5,4,3,2,1}
    };
    for (int i=0; i < 2; ++i){
        for (int j=0; j < 5; ++j){
            cout << array3[i][j] << endl;
        }
    }
    // 1 2 3 4 5 5 4 3 2 1

    return 0;
}