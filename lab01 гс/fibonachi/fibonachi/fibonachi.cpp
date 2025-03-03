﻿// fibonachi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "fibonachi.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Числа Фибоначчи" << endl;
    int N;
    clock_t t3 = 0, t4 = 0;
    cout << "Введите количество чисел N: ";
    cin >> N;
    t3 = clock();
    int result = fibonachi(N);
    cout << "Результат функции чисел Фибоначчи: " << result;
    t4 = clock();
    std::cout << std::endl << "Продолжительность (у.е):   " << (t4 - t3);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
