#pragma once

#include "Exercise.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 3: Преобразование массива по правилу
    */
    class Task3 : public Exercise
    {
    public:
        /**
        * @brief Конструктор
        * @param matrix Указатель на матрицу
        * @param generator Указатель на генератор
        */
        Task3(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
            : Exercise(std::move(matrix), std::move(generator)) {}

        /**
        * @brief Выполняет задание: преобразует массив по правилу
        * Для четных индексов: элемент = индекс * значение
        * Для нечетных индексов: элемент = -значение
        * @return Указатель на результирующую матрицу
        */
        std::unique_ptr<Matrix> execute() const override;

        /**
        * @brief Возвращает название задания
        * @return Название задания
        */
        std::string get_name() const override;
    };
}