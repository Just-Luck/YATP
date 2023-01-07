#include <iostream>
#include <cmath>
using namespace std;

//Линейный поиск
int LineSearch(int* pArray, int n, int key){
    for (int i = 0; i < n; ++i){ // пробегаемся по всему массиву
        if (pArray[i] == key) return i;
    }
    return -1;  
}

//Функция рекурсионного поиска
int BinaryRecursiveSearch(int* pArray, int left, int right, int key){
    if (right < left) return -1;

    int midd = left + (right - left) / 2;

    if (key == pArray[midd]) return midd;

    if (key < pArray[midd]) return BinaryRecursiveSearch(pArray, left, midd - 1, key);

    return BinaryRecursiveSearch(pArray, midd + 1, right, key);
}
//Функция бинарного поиска
int BinarySearch(int* pArray, int n, int key){
    return BinaryRecursiveSearch(pArray, 0, n, key);
}
//Интерполяционный поиск
int InterpolationSearch(int* pArray, int n, int key){
    if (n == 0) return -1;
    int left = 0;
    int right = n;

    int midd = 0;

    while(true){
        double factor = (key - pArray[left]) / (pArray[right] - pArray[left]); // 1 / 2
        int diff = right - left;

        midd = left + factor * diff;

        if (key < pArray[midd]){
            right = midd - 1;
            continue;
        }
        if (key > pArray[midd]){
            right = midd + 1;
            continue;
        }
        if (left > right) return -1;

        return midd;
    }
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    int value = 5;

    cout << LineSearch(array, size, value) << endl;
    // 4 | Возращает индекс элемента в массиве, иначе -1

    cout << BinarySearch(array, size, value) << endl;
    // 4 | Возращает индекс элемента в массиве, иначе последний индекс + 1
    //да

    // объявлем новые тк рекурсионный метод выполняеться дольше чем приходит очередь следущей функции
    int array2[] = {1,2,3,4,5,6,7,8,9,10};
    int size2 = 10;
    int value2 = 5;
    cout << InterpolationSearch(array2, size2, value2) << endl;
    // 4 | Возращает индекс элемента в массиве, при отрицательных значениях может зациклиться


    return 0;
}