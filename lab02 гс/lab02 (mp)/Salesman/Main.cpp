//#include <tchar.h>
//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include "Salesman.h"
//#define N 10
//#define INF 1000000
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    srand(time(0));
//    int d[N][N];
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (i == j) d[i][j] = 0;
//            else d[i][j] = (rand() % 301);
//        }
//    }
//
//    d[1][4] = d[4][1] = INF;
//    d[2][7] = d[7][2] = INF;
//    d[5][9] = d[9][5] = INF;
//
//    int r[N];
//    int s = salesman(
//        N,       //количество городов
//        (int*)d, //матрица расстояний
//        r        //оптимальный маршрут
//    );
//
//    std::cout << std::endl << "-- Задача коммивояжера -- ";
//    std::cout << std::endl << "-- Количество городов: " << N;
//    std::cout << std::endl << "-- Матрица расстояний : ";
//
//    for (int i = 0; i < N; i++) {
//        std::cout << std::endl;
//        for (int j = 0; j < N; j++) {
//            if (d[i][j] != INF) std::cout << std::setw(4) << d[i][j] << " ";
//            else std::cout << std::setw(4) << "INF" << " ";
//        }
//    }
//
//    std::cout << std::endl << "-- Оптимальный маршрут: ";
//    for (int i = 0; i < N; i++) std::cout << r[i] << " --> ";
//    std::cout << "0";
//
//    std::cout << std::endl << "-- Длина маршрута: " << s;
//    std::cout << std::endl;
//    system("pause");
//    return 0;
//}




#include <tchar.h>
#include <iostream>
#include <iomanip> 
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "Salesman.h"

#define SPACE(n) std::setw(n)<<" "
#define N 12

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int d[N * N + 1], r[N];
    srand(time(0));
    for (int i = 0; i <= N * N; i++)
        d[i] = rand() % 91 + 10;

    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "      городов           (сек)  ";

    for (int i = 6; i <= N; i++)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        salesman(i, (int*)d, r);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = t2 - t1;

        std::cout << std::endl << SPACE(7) << std::setw(2) << i
            << SPACE(15) << std::fixed << std::setprecision(6)
            << duration.count();
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}



//#include <iostream>
//#include <chrono>
//#include "Salesman.h"
//
//#define INF 1000000000  
//
//void testSalesman(int n) {
//    int** d = new int* [n];
//    for (int i = 0; i < n; i++) {
//        d[i] = new int[n];
//        for (int j = 0; j < n; j++)
//            d[i][j] = (i == j) ? 0 : rand() % 100 + 1;
//    }
//
//    int* r = new int[n];
//
//    auto start = std::chrono::high_resolution_clock::now();
//    int s = salesman(n, (int*)d, r);
//    auto stop = std::chrono::high_resolution_clock::now();
//
//    double duration = std::chrono::duration<double>(stop - start).count();
//
//    std::cout << "Город: " << n << ", Время: " << duration << " сек" << std::endl;
//
//    for (int i = 0; i < n; i++) delete[] d[i];
//    delete[] d;
//    delete[] r;
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    srand(time(0));
//
//    for (int n = 6; n <= 12; n++) {
//        testSalesman(n);
//    }
//
//    return 0;
//}
