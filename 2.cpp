#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 1 байт = 8 бит -> число вариаций 2^8 = 256
    bool a = false; // !1 байт! true [1,255] | false [0]
    cout << "Bool size " << pow(2,sizeof(bool)*8) << endl;
    char b = 'a'; // !1 байт! таблица ASCII
    cout << "Char size " << pow(2,sizeof(char)*8) << endl;
    int c = 1; // !4 байта! [-2_147_483_648,2_147_483_647]
    cout << "Int size " << pow(2,sizeof(int)*8) << endl;
    float d = 1.0001; // !4 байта!
    double e = 1.00000000000001; // !8 байтов!
    
    //short - сокращает в 2 раза байтов
    //long - увеличивает в 2 раза байт
    //unsigned - неотрицательные числа

    // void func_name() - функция ничего не вернёт
    // int func_name(void) - функция ничего не приймет
    // void* data - неизвестный тип


    double d1(100 - 99.99);
    double d2(10 - 9.99);
    double epsilon = 0.0000000001;
    bool check = fabs(d1 - d2) <= epsilon;
    // 1 - разница минимальна , иначе 0
    cout << check << endl;

    int f = 22;
    char f2 = '2';
    cout << "*= 22 | " << f*2 << endl; // 44
    cout << "/= 22 | " << f/2 << endl; // 11
    cout << "%= 22 | " << f%2 << endl; // 0
    cout << "+= 22 | " << f+2 << endl; // 24
    cout << "-= 22 | " << f-2 << endl; // 20
    cout << "<<= 22 | " << f << 2 << endl; // 222 | Сдвиг значения первого операнда влево на количество битов
    cout << ">>= 22 | " << (f2 >> 2) << endl; // 12 | Сдвиг значения первого операнда вправо на количество битов
    cout << "&= 22 | " << (f2 & 2) << endl; // 2 | Выполнение операции побитового И 
    cout << "^= 22 |" << (f2 ^ 2) << endl; // 48 | Выполнение операции побитового исключающего ИЛИ 
    cout << "|= 22 |" << (f2 | 2) << endl; // 50 | Выполнение операции побитового включающего ИЛИ

    int x1 = 1;
    int y1 = x1++;
    cout << x1++ << " " << y1 << endl;
    // Вывод 2 1
    int x2 = 1;
    int y2 = ++x2;
    cout << ++x2 << " " << y2 << endl;
    // Вывод 3 1


    int(x); //Следует использовать
    (int) x; 

    //static_cast<type>(param) | преобразование одного типа в другой, чаще всего для чисел
    //dynamic_cast<type>(param) | преобразование одного типа в другой более безопасный
    //reinterpret_cast<type>(param) | преобразование без проверки
    //const_cast<const type>(param) | добавление или снятие константы с переменной

    unsigned short int x_x = 65535;
    cout << "X before +1 = " << x_x << endl;
    cout << "X before +1 = " << ++x_x << endl;
    //Переполнение и переход через границу
    
    return 0;
}
