#include <iostream>
#include <memory>
#include <locale>
#include "../Decision2/Matrix.h"
#include "../Decision2/RandomGenerator.h"
#include "../Decision2/IStreamGenerator.h"
#include "../Decision2/Exercise.h"


using namespace miit::algebra;

void demonstrate_random_fill();
void demonstrate_keyboard_fill();

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    try
    {
        std::cout << "=== Демонстрация работы с случайным заполнением ===" << std::endl;
        demonstrate_random_fill();

        std::cout << "\n=== Демонстрация работы с вводом с клавиатуры ===" << std::endl;
        demonstrate_keyboard_fill();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

void demonstrate_random_fill()
{
    // Создаем матрицу размером 8 элементов
    auto matrix = std::make_unique<Matrix>(8);

    // Создаем упражнение
    auto exercise = std::make_unique<Exercise>(
        std::move(matrix),
        std::make_unique<RandomGenerator>(-50, 50)
    );

    // Заполняем матрицу
    exercise->fill_matrix();

    std::cout << "Исходный массив: " << exercise->get_matrix() << std::endl;

    // Выполняем задания
    auto task1_result = exercise->execute_task1();
    std::cout << exercise->get_task1_name() << ": " << *task1_result << std::endl;

    auto task2_result = exercise->execute_task2();
    std::cout << exercise->get_task2_name() << ": " << *task2_result << std::endl;

    auto task3_result = exercise->execute_task3();
    std::cout << exercise->get_task3_name() << ": " << *task3_result << std::endl;
}

void demonstrate_keyboard_fill()
{
    std::cout << "Введите размер массива: ";
    size_t size;
    std::cin >> size;

    if (size == 0)
    {
        std::cout << "Размер массива должен быть больше 0" << std::endl;
        return;
    }

    auto matrix = std::make_unique<Matrix>(size);
    auto exercise = std::make_unique<Exercise>(
        std::move(matrix),
        std::make_unique<IStreamGenerator>()
    );

    std::cout << "Введите " << size << " элементов массива: ";
    exercise->fill_matrix();

    std::cout << "Введенный массив: " << exercise->get_matrix() << std::endl;

    // Выполняем задания
    auto task1_result = exercise->execute_task1();
    std::cout << exercise->get_task1_name() << ": " << *task1_result << std::endl;

    auto task2_result = exercise->execute_task2();
    std::cout << exercise->get_task2_name() << ": " << *task2_result << std::endl;

    auto task3_result = exercise->execute_task3();
    std::cout << exercise->get_task3_name() << ": " << *task3_result << std::endl;
}