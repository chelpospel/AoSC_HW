#include <cstdlib>
#include <ctime>
#include <cstring>
#include <chrono>

#include "container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile\n"
                 "  Or:\n"
                 "     command -n number outfile\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile\n"
                 "  Or:\n"
                 "     command -n number outfile\n";
}

// Проверка существования файла
bool FileIsExist(std::string filePath) {
    bool isExist = false;
    std::ifstream fin(filePath.c_str());

    if (fin.is_open())
        isExist = true;

    fin.close();
    return isExist;
}

int main(int argc, char *argv[]) {
    // получение точки во времени перед началом
    // выполнения основной программы
    auto start_time = std::chrono::high_resolution_clock::now();

    if (argc != 4) {
        errMessage1();
        return 1;
    }
// -f /Users/savelijsuncov/CLionProjects/test/test.txt
    // проверка существования входного файла
    if (!strcmp(argv[1], "-f") && !FileIsExist(argv[2])) {
        std::cout << "File \"infile\" not exist.";
        return 2;
    }

    std::cout << "Start" << std::endl;
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        In(c, ifst);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of languages = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(nullptr)));
        // заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    } else {
        errMessage2();
        return 4;
    }

    // вывод исходного содержимого контейнера в выходной файл
    std::ofstream ofst(argv[3]);
    ofst << "Filled container:\n";
    Out(c, ofst);

    ofst << "\n";

    // вывод обработанного содержимого контейнера в выходной файл
    ofst << "Sorted container:\n";
    Sort_shell_shape(c.entity, c.len);
    Out(c, ofst);


    // освобождение контейнера
    Clear(c);
    std::cout << "Stop" << std::endl;

    // получение точки во времени сразу после завершения выполнения
    // основной программы, и вывод её продолжительности в консоль
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end_time - start_time;
    std::cout << "\nВремя выполнения программы: " << duration.count() << " сек\n" << std::endl;

    return 0;
}
