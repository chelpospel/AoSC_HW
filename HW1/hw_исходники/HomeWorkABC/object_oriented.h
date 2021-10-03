//
// procedural.h - содержит описание ОО языка и его интерфейса
//
#ifndef HOMEWORKABC_OBJECT_ORIENTED_H
#define HOMEWORKABC_OBJECT_ORIENTED_H

#include "rnd.h"

struct object_oriented{
    float procent_popular;
    int creation_year;
    int name_lenght;

    // наследование
    enum inheritance{
        // унарное
        unary,
        // множественное
        multiple,
        // интерфейсное
        interface
    };

    inheritance inh;
};

// Ввод параметров объектно-ориентированного языка из файла
void In(object_oriented &o, std::ifstream &ifst);

// Случайный ввод параметров ОО языка
void InRnd(object_oriented &o);

// Вывод параметров объектно-ориентированного языка
// в форматируемый поток
void Out(object_oriented &o, std::ofstream &ofst);

#endif //HOMEWORKABC_OBJECT_ORIENTED_H
