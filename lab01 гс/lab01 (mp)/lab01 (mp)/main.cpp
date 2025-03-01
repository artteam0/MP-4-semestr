#include "pch.h"

#define CYCLE 10000000  // Количество циклов

int main() {
    setlocale(LC_ALL, "rus");

    double av1 = 0, av2 = 0;
    clock_t t1 = 0, t2 = 0;

    auxil::start();  // Инициализация генератора случайных чисел
    t1 = clock();  // Фиксация времени

    for (int i = 0; i < CYCLE; i++) {
        av1 += (double)auxil::iget(-100, 100);  // Генерация случайных чисел
        av2 += auxil::dget(-100, 100);
    }

    t2 = clock();  // Фиксация времени после выполнения

    std::cout << std::endl << "Количество циклов: " << CYCLE;
    std::cout << std::endl << "Среднее значение (int): " << av1 / CYCLE;
    std::cout << std::endl << "Среднее значение (double): " << av2 / CYCLE;
    std::cout << std::endl << "Продолжительность (у.е): " << (t2 - t1);
    std::cout << std::endl << "                  (сек): " << ((double)(t2 - t1)) / CLOCKS_PER_SEC; //кол-во тактов процессора за одну секунду
    std::cout << std::endl;


    


    return 0;
}
