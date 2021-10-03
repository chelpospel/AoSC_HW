//
// shape.cpp - содержит процедуры обработки обобщенного языка
//

#include "shape.h"

//------------------------------------------------------------------------------
// Ввод содержимого обобщенного языка из указанного потока
bool InShape(shape &s, std::ifstream &ifst) {
    int n;
    ifst >> n;
    switch (n) {
        case 0:
            s.k = shape::PROCEDURAL;
            InProcedural(s.p, ifst);
            return true;
        case 1:
            s.k = shape::OBJECT_ORIENTED;
            In(s.o, ifst);
            return true;
        case 2:
            s.k = shape::FUNCTIONAL;
            In(s.f, ifst);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенного языка
bool InRnd(shape &s) {
    int r = rand() % 3 + 1;
    switch (r) {
        case 1:
            s.k = shape::PROCEDURAL;
            InRnd(s.p);
            return true;
        case 2:
            s.k = shape::OBJECT_ORIENTED;
            InRnd(s.o);
            return true;
        case 3:
            s.k = shape::FUNCTIONAL;
            InRnd(s.f);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего языка в поток
void Out(shape &s, std::ofstream &ofst) {
    switch (s.k) {
        case shape::PROCEDURAL:
            Out(s.p, ofst);
            break;
        case shape::OBJECT_ORIENTED:
            Out(s.o, ofst);
            break;
        case shape::FUNCTIONAL:
            Out(s.f, ofst);
            break;
        default:
            ofst << "Incorrect language!" << std::endl;
    }
}

//------------------------------------------------------------------------------
// Частное от деления года создания обобщенного
// языка на кол-во символов в названии
double QuotientYearName(shape &s) {
    switch (s.k) {
        case 0:
            return (float) s.p.creation_year / (float) s.p.name_lenght;
        case 1:
            return (float) s.o.creation_year / (float) s.o.name_lenght;
        case 2:
            return (float) s.f.creation_year / (float) s.f.name_lenght;
        default:
            throw;
    }
}

//------------------------------------------------------------------------------
// Компаратор для двух вещественных чисел
bool CompareTo(shape a, shape b) {
    return QuotientYearName(a) < QuotientYearName(b);
}

//------------------------------------------------------------------------------
// Сортировка Шелла для массива обобщенных языков.
// parameter<n> - кол-во элементов массива
void Sort_shell_shape(shape *arr, int n) {
    int i, j, step;
    shape tmp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            tmp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (CompareTo(tmp,arr[j - step]))
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
    }
}