#include <iostream>
#include <memory>
#include <locale>
#include "../Decision2/Matrix.h"
#include "../Decision2/RandomGenerator.h"
#include "../Decision2/IStreamGenerator.h"
#include "../Decision2/Exercise.h"
#include "../Decision2/Generator.h"


using namespace miit::algebra;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    try
    {
        std::cout << "=== Демонстрация работы с случайным заполнением ===" << std::endl;

        // Заполняем матрицу ДО создания Exercise
        auto random_matrix = std::make_unique<Matrix>(8);
        auto random_generator = std::make_unique<RandomGenerator>(-50, 50);
        random_matrix->fill(std::move(random_generator));

        auto random_exercise = std::make_unique<Exercise>(
            std::move(random_matrix),
            std::make_unique<RandomGenerator>(-50, 50) // второй генератор для Exercise
        );

        std::cout << "Исходный массив: " << random_exercise->get_matrix() << std::endl;

        auto task1_random = random_exercise->execute_task(1);
        std::cout << random_exercise->get_task_name(1) << ": " << *task1_random << std::endl;

        auto task2_random = random_exercise->execute_task(2);
        std::cout << random_exercise->get_task_name(2) << ": " << *task2_random << std::endl;

        auto task3_random = random_exercise->execute_task(3);
        std::cout << random_exercise->get_task_name(3) << ": " << *task3_random << std::endl;

        std::cout << "\n=== Демонстрация работы с вводом с клавиатуры ===" << std::endl;

        std::cout << "Введите размер массива: ";
        size_t size;
        std::cin >> size;

        if (size == 0)
        {
            std::cout << "Размер массива должен быть больше 0" << std::endl;
            return 1;
        }

        // Заполняем матрицу ДО создания Exercise
        auto keyboard_matrix = std::make_unique<Matrix>(size);
        auto keyboard_generator = std::make_unique<IStreamGenerator>();
        keyboard_matrix->fill(std::move(keyboard_generator));

        auto keyboard_exercise = std::make_unique<Exercise>(
            std::move(keyboard_matrix),
            std::make_unique<IStreamGenerator>() // второй генератор для Exercise
        );

        std::cout << "Введенный массив: " << keyboard_exercise->get_matrix() << std::endl;

        auto task1_keyboard = keyboard_exercise->execute_task(1);
        std::cout << keyboard_exercise->get_task_name(1) << ": " << *task1_keyboard << std::endl;

        auto task2_keyboard = keyboard_exercise->execute_task(2);
        std::cout << keyboard_exercise->get_task_name(2) << ": " << *task2_keyboard << std::endl;

        auto task3_keyboard = keyboard_exercise->execute_task(3);
        std::cout << keyboard_exercise->get_task_name(3) << ": " << *task3_keyboard << std::endl;

        std::cout << "\n=== Демонстрация работы с постоянным заполнением ===" << std::endl;

        // Заполняем матрицу ДО создания Exercise
        auto constant_matrix = std::make_unique<Matrix>(6);
        auto constant_generator = std::make_unique<ConstantGenerator>(42);
        constant_matrix->fill(std::move(constant_generator));

        auto constant_exercise = std::make_unique<Exercise>(
            std::move(constant_matrix),
            std::make_unique<ConstantGenerator>(42) // второй генератор для Exercise
        );

        std::cout << "Массив, заполненный ConstantGenerator(42): " << constant_exercise->get_matrix() << std::endl;

        auto task1_constant = constant_exercise->execute_task(1);
        std::cout << constant_exercise->get_task_name(1) << ": " << *task1_constant << std::endl;

        auto task2_constant = constant_exercise->execute_task(2);
        std::cout << constant_exercise->get_task_name(2) << ": " << *task2_constant << std::endl;

        auto task3_constant = constant_exercise->execute_task(3);
        std::cout << constant_exercise->get_task_name(3) << ": " << *task3_constant << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}