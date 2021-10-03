//
// Created by Савелий on 02.10.2021.
//

#include "functional.h"

//------------------------------------------------------------------------------
// Ввод содержимого функционального языка из указанного потока
void In(functional &f, std::ifstream &ifst) {
    int n;
    // ввод уникального для функционального языка значения типизациии
    ifst >> n;
    switch (n) {
        case 0:
            f.type = f.strong;
            break;
        case 1:
            f.type = f.weak;
        default:
            break;
    }

    // ввод уникального для функционального языка значения поддержки
    // ленивых вычислений
    ifst >> f.lazy_calculator;

    // ввод общих для всех языков значений
    ifst >> f.name_lenght >> f.creation_year >> f.procent_popular;
}

//------------------------------------------------------------------------------
// Cлучайный ввод параметров функционального языка
void InRnd(functional &f){
    // Случайное определение значения уникального
    // параметра функционального языка
    int n = IntRandom(2);
    switch (n) {
        case 0:
            f.type = f.strong;
            break;
        case 1:
            f.type = f.weak;
            break;
        default:
            break;
    }

    // Случайные определения значений общих параметров языков
    f.procent_popular = FloatRandom();
    f.creation_year = IntRandom(1965, 1995);
    f.name_lenght = IntRandom(1,10);
}

//------------------------------------------------------------------------------
// Вывод параметров функционального языка в форматируемый поток
void Out(functional &f, std::ofstream &ofst) {
    std::string arr_type[] = {"strong", "weak"};
    // вывод уникальных параметров функционального языка
    ofst << "{It is functional language: typing = " << arr_type[f.type]
         << ", implementation of lazy calculations = " << f.lazy_calculator;

    // вывод общих для всех языков параметров
    ofst << ", lenght of name = " << f.name_lenght << ", year of creation = "
         << f.creation_year << ", procent of popular = "
         << f.procent_popular << "}\n";
/*
    ofst << "2\n" << f.type
         << " " << f.lazy_calculator;

    // вывод общих для всех языков параметров
    ofst << " " << f.name_lenght << " "
         << f.creation_year << " "
         << f.procent_popular << "\n";*/
}

