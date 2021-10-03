//
// procedural.h - содержит описание процедурного языка и его интерфейса
//
#ifndef HOMEWORKABC_PROCEDURAL_H
#define HOMEWORKABC_PROCEDURAL_H

#include <fstream>
#include "rnd.h"

struct procedural{
    float procent_popular;
    int creation_year;
    int name_lenght;

    // наличие абстрактных типов данных
    bool ATD;
};

// Ввод параметров процедурного языка из файла
void InProcedural(procedural& p, std::ifstream &ifst);

// Случайный ввод параметров процедурного языка
void InRnd(procedural& p);

// Вывод параметров процедурного языка в форматируемый поток
void Out(procedural& p, std::ofstream &ofst);


#endif //HOMEWORKABC_PROCEDURAL_H
