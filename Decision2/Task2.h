#pragma once

#include "Exercise.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 2: Удаление элементов с повторяющимися цифрами
    */
    class Task2 : public Exercise
    {
    public:
        /**
        * @brief Конструктор
        * @param matrix Указатель на матрицу
        * @param generator Указатель на генератор
        */
        Task2(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
            : Exercise(std::move(matrix), std::move(generator)) {}

        /**
        * @brief Выполняет задание: удаляет элементы с повторяющимися цифрами
        * @return Указатель на результирующую матрицу
        */
        std::unique_ptr<Matrix> execute() const override;

        /**
        * @brief Возвращает название задания
        * @return Название задания
        */
        std::string get_name() const override;

    private:
        /**
        * @brief Проверяет есть ли в числе повторяющиеся цифры
        * @param number Число для проверки
        * @return true если есть повторяющиеся цифры, иначе false
        */
        bool has_repeating_digits(int number) const;
    };
}