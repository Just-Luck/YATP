#include <iostream>
#include <cmath>
using namespace std;

// функция вывода массива
void printArray(int *x, int n){
    for (int i = 0;i < n;i++){
        cout << x[i] << endl;
    }
}

//функция поиска элемента в массиве find_elem(ссылка на массив, размер массива, искомое значение)
bool find_elem(int * m, int size, int value){
    for (int i = 0; i != size; i++){
        if (m[i] == value) return true;
    }
    return false;
}

bool find_elem2(int *p, int *q, int value){
    for (; p!= q; ++p){
        if (*p == value) return true;
    }
    return false;
}
int main(){
    int* m1d = new int [100]; // одномерный динамический массив

    int m[10] = {1,2,3,4,5};
    //printArray(m, size(m));
    // 1 2 3 4 5 0 0 0 0 0

    int *p = &m[0]; // адресс первого элемента массива
    int *q = &m[9]; // адресс последнего элемента массива
    cout << (q - p) << endl; // 9 кол-во ячеек между указателями

    int arr[10] = {};
    // 0 0 0 0 0 0 0 0 0 0
    int *p2 = &arr[0]; // адресс первого элемента массива
    int *q2 = &arr[9]; // адресс последнего элемента массива
    for (int *p2 = arr; p2 <= arr + 9; p2++){
        *p2 = (p2 - arr) + 1;
    }
    printArray(arr, size(arr));
    // 1 2 3 4 5 6 7 8 9 10

    malloc(10); // Выделяет память для программы без инициализации
    int * buffer1 = (int*) malloc(100 * sizeof(int)); // выделяем память под 100 элементов массива типа int
    free(buffer1); //Освобождает память занятую malloc()

    int * arr_ay = new int(5); // Выделение памяти для массива
    delete arr_ay; // Освобождение памяти

    arr_ay = new int[1000]; // Выделение памяти для массива
    delete [] arr_ay; // Освобождение памяти



    return 0;
}