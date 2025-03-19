#include "Combi.h"
#include <algorithm>
#define NINF  ((short)0x8000)
namespace combi
{
    permutation::permutation(short n)
    {
        this->n = n;
        this->sset = new short[n]; // массив из целых чисел для перестановки
        this->dart = new bool[n]; // массив направлений
        this->reset();
    };
    void  permutation::reset()
    {
        this->getfirst(); // сброс перестановки в начальное состояние
    };
    __int64  permutation::getfirst()
    {
        this->np = 0; // счетчик перестановок
        for (int i = 0; i < this->n; i++)
        {
            this->sset[i] = i; 
            this->dart[i] = L; // все элементы направлены влево
        };
        return  (this->n > 0) ? this->np : -1;
    };
    __int64  permutation::getnext()   // 
    {
        __int64 rc = -1;
        short maxm = NINF, // максимальный подвижный элемент
        idx = -1;
        for (int i = 0; i < this->n; i++)
        {
            if (i > 0 &&
                this->dart[i] == L &&
                this->sset[i] > this->sset[i - 1] && // если влево и больше соседа, то подвижный
                maxm < this->sset[i])  maxm = this->sset[idx = i];
            if (i < (this->n - 1) &&
                this->dart[i] == R &&
                this->sset[i] > this->sset[i + 1] && // если вправо и больше соседа, то подвижный
                maxm < this->sset[i])  maxm = this->sset[idx = i];
        };
        if (idx >= 0) // если есть подвижный элемент
        {
            std::swap(this->sset[idx],
                this->sset[idx + (this->dart[idx] == L ? -1 : 1)]); //смена направления
            std::swap(this->dart[idx],
                this->dart[idx + (this->dart[idx] == L ? -1 : 1)]);
            for (int i = 0; i < this->n; i++)
                if (this->sset[i] > maxm) this->dart[i] = !this->dart[i];
            rc = ++this->np; // счетчик перестановок
        }
        return rc;
    };
    short permutation::ntx(short i) { return  this->sset[i]; }; //получение элемента i-й перестановки
    unsigned __int64 fact(unsigned __int64 x) { return (x == 0) ? 1 : (x * fact(x - 1)); }; //рекурсивно факторивал
    unsigned __int64 permutation::count() const { return fact(this->n); }; //n!
} 










//#include "Combi.h"
//
//namespace combi
//{
//    permutation::permutation(short n) : n(n), np(0)
//    {
//        sset = new short[n];
//        dart = new bool[n];
//
//        for (short i = 0; i < n; i++)
//        {
//            sset[i] = i;
//            dart[i] = L; // Все стрелки направлены влево
//        }
//    }
//
//    permutation::~permutation()
//    {
//        delete[] sset;
//        delete[] dart;
//    }
//
//    __int64 permutation::getfirst()
//    {
//        np = 0;
//        return np;
//    }
//
//    __int64 permutation::getnext()
//    {
//        if (++np < count())
//            return np;
//        else
//            return -1; // Нет следующей перестановки
//    }
//
//    unsigned __int64 permutation::count() const
//    {
//        unsigned __int64 result = 1;
//        for (short i = 2; i <= n; i++)
//            result *= i;
//        return result;
//    }
//}
