//
// container.h - содержит тип данных,
// представляющий простейший контейнер
//
#ifndef HOMEWORKABC_CONTAINER_H
#define HOMEWORKABC_CONTAINER_H

#include "shape.h"

#include "procedural.h"
#include "object_oriented.h"
#include "functional.h"

#include <cstring>


struct container{
    enum {max_lenght = 10000};
    int len;

    // массив обощенных языков
    shape entity[max_lenght];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst);

#endif //HOMEWORKABC_CONTAINER_H
