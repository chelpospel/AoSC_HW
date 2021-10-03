//
// object_oriented.cpp - содержит процедуры обработки ОО языка
//

#include "object_oriented.h"

//------------------------------------------------------------------------------
// Ввод содержимого ОО языка из указанного потока
void In(object_oriented &o, std::ifstream &ifst){
    int n;
    // ввод уникального для функционального языка значения наследования
    ifst >> n;
    switch (n) {
        case 0:
            o.inh = o.unary;
            break;
        case 1:
            o.inh = o.multiple;
            break;
        case 2:
            o.inh = o.interface;
            break;
        default:
            break;
    }

    // ввод общих для всех языков значений
    ifst >> o.name_lenght >> o.creation_year >> o.procent_popular;
}

//------------------------------------------------------------------------------
// Cлучайный ввод параметров ОО языка
void InRnd(object_oriented &o){
    // Случайное определение значения уникального
    // параметра ОО языка
    int n = IntRandom(3);
    switch (n) {
        case 0:
            o.inh = o.unary;
            break;
        case 1:
            o.inh = o.multiple;
            break;
        case 2:
            o.inh = o.interface;
            break;
        default:
            break;
    }

    // Случайные определения значений общих параметров языков
    o.procent_popular = FloatRandom();
    o.creation_year = IntRandom(1965, 1995);
    o.name_lenght = IntRandom(1,10);
}

//------------------------------------------------------------------------------
// Вывод параметров ОО языка в форматируемый поток
void Out(object_oriented &o, std::ofstream &ofst) {
    // вывод уникальных параметров ОО языка
    std::string arr_inh[] = {"unary", "multiple", "interface"};
    ofst << "{It is object oriented language: inheritance = " << arr_inh[o.inh];

    // вывод общих для всех языков параметров
    ofst << ", lenght of name = " << o.name_lenght << ", year of creation = "
         << o.creation_year << ", procent of popular = "
         << o.procent_popular << "}\n";

    /*
    ofst << "1\n" << o.inh << " ";

    // вывод общих для всех языков параметров
    ofst << o.name_lenght << " "
         << o.creation_year << " "
         << o.procent_popular << "\n";*/
}
