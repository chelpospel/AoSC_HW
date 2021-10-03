//
// functional.h - содержит описание функционального языка и его интерфейса
//
#ifndef HOMEWORKABC_FUNCTIONAL_H
#define HOMEWORKABC_FUNCTIONAL_H

#include "rnd.h"

struct functional{
    float procent_popular;
    int creation_year;
    int name_lenght;

    // типизация
    enum typing{
        // строгая
        strong,
        // слабая
        weak
    };

    typing type;

    bool lazy_calculator;
};

// Ввод параметров функционального языка из файла
void In(functional &f, std::ifstream &ifst);

// Случайный ввод параметров функционального языка
void InRnd(functional &f);

// Вывод параметров функционального языка в форматируемый поток
void Out(functional &f, std::ofstream &ofst);

#endif //HOMEWORKABC_FUNCTIONAL_H
