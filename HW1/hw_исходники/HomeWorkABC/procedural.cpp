//
// procedural.cpp - содержит процедуры обработки процедурного языка
//

#include "procedural.h"

//------------------------------------------------------------------------------
// Ввод содержимого процедурного языка из указанного потока
void InProcedural(procedural &p, std::ifstream &ifst) {
    // ввод уникального для процедурного языка значения поддержки АТД
    ifst >> p.ATD;
    // ввод общих для всех языков значений
    ifst >> p.name_lenght >> p.creation_year >> p.procent_popular;
}

//------------------------------------------------------------------------------
// Cлучайный ввод параметров процедурного языка
void InRnd(procedural &p) {
    // Случайное определение значения уникального
    // параметра процедурного языка
    p.ATD = IntRandom(2) == 1;

    // Случайные определения значений общих параметров языков
    p.procent_popular = FloatRandom();
    p.creation_year = IntRandom(1965, 1995);
    p.name_lenght = IntRandom(1, 10);
}

//------------------------------------------------------------------------------
// Вывод параметров процедурного языка в форматируемый поток
void Out(procedural &p, std::ofstream &ofst) {
    // вывод уникальных параметров процедурного языка
    ofst << "{It is procedural language: ATD = " << p.ATD;

    // вывод общих для всех языков параметров
    ofst << ", lenght of name = " << p.name_lenght << ", year of creation = "
         << p.creation_year << ", procent of popular = "
         << p.procent_popular << "}\n";
    /*
    // вывод уникальных параметров процедурного языка
    ofst << "0\n" << p.ATD;

    // вывод общих для всех языков параметров
    ofst << " " << p.name_lenght << " "
         << p.creation_year << " "
         << p.procent_popular << "\n";*/
}

