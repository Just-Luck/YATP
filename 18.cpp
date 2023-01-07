#include <iostream>
#include <cmath>

using namespace std;

//Меняем 2 переменные местами
void Swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSort(int* pArray, int n){
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (pArray[j] > pArray[j+1]){
                Swap(pArray[j],pArray[j+1]);
            }
        }
    }
}

void Shaker(int* pArray, int n){
    int left = 1;
    int right = n - 2;
    while (left <= right){
        for (int i = right;i >= left; --i){
            if (pArray[i] < pArray[i - 1]){
                Swap(pArray[i],pArray[i-1]);
            }
        }
        left++;

        for(int i = left; i <= right; ++i){
            if(pArray[i] > pArray[i+1]){
                Swap(pArray[i],pArray[i+1]);
            }
        }
    }
}

void SelectionSort(int* pArray, int n){
    for (int i = 0; i < n - 1; ++i){
        int min = i;
        for (int j = i + 1; j < n; ++j){
            if(pArray[j] < pArray[min]) min = j;
        }
        Swap(pArray[i],pArray[min]);
    }
}

void InsertSort(int* pArray, int n){
    for (int i = 1; i < n; ++i){
        int current = pArray[i];

        int j;
        for(j = i - 1; j >= 0 && pArray[j] > current; --j){
            pArray[j + 1] = pArray[j];
        }

        pArray[j+1] = current;
    }
}

void HoareSort(int* pArray, int left, int right){
    int l = left;
    int r = right;
    int mid = pArray[(l + r) / 2];

    do{
        while (pArray[l] < mid) ++l;
        while (pArray[r] > mid) --r;

        if (l < r){
            Swap(pArray[l],pArray[r]);
            ++l;
            --r;
        }
    } while (l < r);

    if (left < r) HoareSort(pArray,left,r);
    if (l < right) HoareSort(pArray,l,right);
}

void HoareSort(int* pArray, int n){
    HoareSort(pArray, 0, n - 1);
}

int main(){
    int arr[] = {1,10,6,7,4,2,3,2};
    BubbleSort(arr, size(arr));
    //1 2 2 3 4 6 7 10
    for (int i = 0; i < size(arr); ++i){
        cout << arr[i] << " ";
    }

    cout << endl;

    int arr2[] = {1,10,6,7,4,2,3,2};
    Shaker(arr2, size(arr2));
    //1 2 2 3 4 6 7 10
    for (int i = 0; i < size(arr2); ++i){
        cout << arr2[i] << " ";
    }

    cout << endl;

    int arr3[] = {1,10,6,7,4,2,3,2};
    SelectionSort(arr3, size(arr3));
    //1 2 2 3 4 6 7 10
    for (int i = 0; i < size(arr3); ++i){
        cout << arr3[i] << " ";
    }
    
    cout << endl;

    int arr4[] = {1,10,6,7,4,2,3,2};
    InsertSort(arr4, size(arr4));
    //1 2 2 3 4 6 7 10
    for (int i = 0; i < size(arr4); ++i){
        cout << arr4[i] << " ";
    }

    cout << endl;

    int arr5[] = {1,10,6,7,4,2,3,2};
    HoareSort(arr5, size(arr5));
    //1 2 2 3 4 6 7 10
    for (int i = 0; i < size(arr5); ++i){
        cout << arr5[i] << " ";
    }   
    return 0;
}