//
// shape.h - содержит описание обобщающего языка и его интерфейсы
//
#ifndef HOMEWORKABC_SHAPE_H
#define HOMEWORKABC_SHAPE_H

#include "procedural.h"
#include "object_oriented.h"
#include "functional.h"


struct shape{
    enum key {PROCEDURAL, OBJECT_ORIENTED, FUNCTIONAL};
    key k;

    union {
        procedural p;
        object_oriented o;
        functional f;
    };
};

// Ввод обобщенного языка
bool InShape(shape &s, std::ifstream &ifst);

// Случайный ввод обобщенного языка
bool InRnd(shape &s);

// Вывод обобщенного языка
void Out(shape &s, std::ofstream &ofst);

// Частное от деления года создания обобщенного
// языка на кол-во символов в названии
double QuotientYearName(shape &s);

// Компаратор для двух целых чисел
bool CompareTo(double a, double b);

// Сортировка Шелла для массива обобщенных языков.
void Sort_shell_shape(shape *arr, int n);

#endif //HOMEWORKABC_SHAPE_H
