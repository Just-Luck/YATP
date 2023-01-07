#include <iostream>
#include <cmath>
using namespace std;

//функция создания массива
int ** create_array2d(size_t a, size_t b){
    int ** m = new int *[a];
    for (size_t i = 0; i != a; ++i){
        m[i] = new int[b];
    }
    return m;
}

//функция удаления массива
void free_array2d(int ** m, size_t a, size_t b){
    for (size_t i = 0; i != a; ++i){
        delete [] m[i];
    }
    delete [] m;
}

//функция оптимизированного создания массива
int ** create_array2d_opt(size_t a, size_t b){
    int ** m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i){
        m[i] = m[i - 1] + b;
    }
    return m;
}

//функция оптимизированного удаления массива
void free_array2d_opt(int ** m){
    delete [] m[0];
    delete [] m;
}

int main(){
    int ** m = new int * [5];
    for (size_t i = 0; i != 5; ++i) m[i] = new int[4];
    // создали массив 5 x 4

    int ** array = new int * [5];
    array[0] = new int [5 * 4];
    for (size_t i = 1; i != 5; ++i) array[i] = array[i-1] + 4;
    // более эффективное создание массива 5 x 4

    int ** a = create_array2d(3,4); // вызов функции создания массива
    free_array2d(a ,3,4); // функция удаления массива

    int ** b = create_array2d_opt(3,4); // вызов оптимизированной функции создания массива
    free_array2d_opt(b); // функция оптимизированного удаления массива

    int *c = new int[5]; //указатель на первый элем массива

    int **d = new int* [3];
    for (int i = 0; i < 3; i++)
        d[i] = new int[4];
    // массив с указателями на массивы

    int arr[2][3] = {
        {1,2,3},
        {1,2,3}
    };
    int size = 2*3;

    for (int i = 0; i < size; ++i){
        
        auto pTemp1 = arr + i; // Итерация по подмассивам
        int* pTemp2 = *pTemp1; // pTemp2 указатель на i-подмассив

        int temp2 = pTemp2[0]; // temp2 первый элемент i-подмассива
        int temp3 = *(pTemp2 + i); // temp3 i-элемент i-подмассива

        int tempInt = *(arr[0] + i); // Вывод всех элементов
        cout << tempInt << endl;
        // 1 2 3 1 2 3
    }
    
    int arr2[2][3][2] = {
        {
            {1,2},
            {3,4},
            {5,6}
        },
        {
            {7,8},
            {9,10},
            {11,12}
        },
    };
    int size2 = 2*3*2;
    for (int i = 0; i < size2; ++i){
        
        auto pTemp1 = arr2 + i; // Итерация по подмассивам
        auto pTemp2 = *pTemp1; // pTemp2 указатель на i-подмассив
        int* pTemp3 = *pTemp2; // pTemp3 указатель на i-подмассив

        int temp3 = pTemp3[0]; // temp3 первый элемент i-подмассива
        int temp4 = *pTemp3; // temp4 i-элемент i-подмассива

        cout << *(arr2[0][0] + i) << endl; // Вывод всех элементов
        // 1 2 3 4 5 6 7 8 9 10 11 12
    }
    return 0;
}