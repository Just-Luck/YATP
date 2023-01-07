#include <iostream>
#include <cmath>
using namespace std;

//Проверка числа на простоту
bool IsPrime(int x){
    if (x <= 1) return false; // Только натуральное число может быть простым | 1 - не натурально число

    for (int i = 2; i <= sqrt(x); i++) { // Поиск всех делителей числа | Корень ускоряет выполнение работы кода в 2 раза в отличии от полного перебора
        if (x % i == 0) return false; // Если нашелся делитьль => число не простое
    }
    return true;
}

//Факторизация числа - разложение числа на простые множетели
int* Factorize(int x, int& outCount){ // функция будет возвращать массив множителей и количество этих множителей
    //sqrt(x) + 1
    int bytes = ceil(sqrt(x) + 1); // находим  сколько байтов необходимо выделить
    int* primes = new int[bytes]{ 0 }; // выделяем память достаточного размера под массив
    int k = 0; // счетчик

 for (int i = 2; i <= sqrt(x); i++) { // циклом перебираем делители числа до корня числа
        while (x % i == 0) { // пока число делится
            primes[k++] = i; // записываем делитель в массив, увеличиваем счетчик
            x /= i; // делим число
        }
    }
    if (x != 1) primes[k++] = x; // Если число простое записываем его в массив

    outCount = k; // По ссылки передаем кол-во делителей
    return primes; // Возращаем массив делителей

}

//Нахождение делителей
int* Dividers(int x, int& outCount2){ // функция будет возвращать массив делителей и количество делителей
    int n = sqrt(x);
    int* dividers = new int[x / 2] { 0 }; // выделяем достаточно памяти для массива
    int k = 0; // счетчик

    for (int i = 2; i <= n; i++){ // циклом перебираем делители до корня
        if (x % i == 0){ // если число делится
            dividers[k++] = i; // записываем в массив найденный делитель
            if (i * i != x) // если делитель не равен корню числа
                dividers[k++] = x / i; // то записываем в массив парный делите
        }
    }

    outCount2 = k; // количество делителей
    return dividers; // массив делителей
}

//Решето Эратосфена - алгоритм нахождения всех простых чисел до некоторого целого числа n.
int* SieveEratosthenes(int n, int& outCount3){
    int count = n;
    int* numbers = new int[count]; // числа от 0 до n не включительно
    int* result = new int[count]; // массив простых чисел
    int k = 0;

    for (int i = 0; i < count; ++i) // заполняем массив числами от 0 до n
        numbers[i] = i;

    for (int p = 2; p < count; ++p) // проходимся по числам
    {
        if (numbers[p] == 0) continue;

        result[k++] = numbers[p]; // записываем в массив простые числа

        for (int j = p * p; j < count; j += p) // фильтруем массив с числами по найденному простому числу | оптимизация программы
            numbers[j] = 0; // вместо фильтрованных чисел записываем нули
    }

    outCount3 = k; // количество простых чисел
    return result; // массив простых чисел
}

int main(){
//Проверка числа на простоту
    cout << IsPrime(19) << endl; // 0 - не простое | 1 - простое

//Факторизация числа - разложение числа на простые множетели
    int outCount = 0;
    auto arr = Factorize(20, outCount);
    for (int i = 0; i < outCount; ++i) cout << arr[i] << " ";
    // 2 2 5
    cout << endl;
//Нахождение делителей
    int outCount2 = 0;
    auto arr2 = Dividers(20, outCount2);
    for (int i = 0; i < outCount2; ++i) cout << arr2[i] << " ";
    // 2 10 4 5
    cout << endl;
//Решето Эратосфена
    int outCount3 = 0;
    auto arr3 = SieveEratosthenes(20, outCount3);
    for (int i = 0; i < outCount3; ++i) cout << arr3[i] << " ";
    // 2 3 5 7 11 13 17 19

    return 0;
}