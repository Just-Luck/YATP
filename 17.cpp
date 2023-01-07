#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

//Алгоритм поиска подстроки в строке перебором 
int SearchSubString(char* templateString, char* dataString){
    int index = -1;
    int n = strlen(dataString);
    int m = strlen(templateString);

    for (int i = 0; i < n; ++i){
        int j = 0;
        while (dataString[i + j] == templateString[j] && i + j < n && j < m) ++j;

        if (j == m){
            index = i;
            break;
        }
    }

    return index;
}

//Функция определения индекса строки
int IndexOf(char* dataString, char ch){
    int k = strlen(dataString) - 1;
    while (k > -1){
        if (dataString[k] == ch) return k;
        --k;
    }
    return -1;
}
//Алгоритм Бойера-Мура-Хорспула 
int SearchBMHSubString(char* dataString, int n, char* templateString, int m){
    if (n == 0 || m == 0) return -1;

    int* pIndex = new int[m];

    for (int i = 0; i < m; ++i){
        char ch = templateString[i];
        int length = m - i - 1;
        pIndex[i] = length;
    }

    pIndex[m - 1] = strlen(templateString);
    int i = m - 1;

    int j = i;
    int k = i;

    while (i < n){
        k = i;
        j = m - 1;
        while(j > -1 && dataString[k] == templateString[j]){
            k--;
            j--;
        }
        if (j == -1) return k + 1;

        char currentChar = dataString[i];
        int index = IndexOf(templateString,currentChar);
        if (index == -1) index = m - 1;

        i += pIndex[index];
    }
    return -1;
}

int main(){
    char str[] = "qwerty test";
    char value[] = "y te";

    cout << SearchSubString(value, str) << endl;
    // 7 | если не нашло выводит -1 , иначе индекс начала искомой строки

    cout << SearchBMHSubString(str, strlen(str), value , strlen(value)) << endl;
    // 7 | если не нашло выводит -1 , иначе индекс начала искомой строки
    return 0;
}