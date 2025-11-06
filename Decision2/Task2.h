#pragma once

#include "Exercise.h"
#include "Matrix.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 2: Удаление элементов с повторяющимися цифрами
    */
    class Task2 : public Task
    {
    public:
        /**
        * @brief Выполняет задание
        * @param matrix Исходная матрица
        * @return Результирующая матрица
        */
        std::unique_ptr<Matrix> execute(const Matrix& matrix) const override;  

    private:
        /**
        * @brief Проверяет есть ли в числе повторяющиеся цифры
        * @param number Число для проверки
        * @return true если есть повторяющиеся цифры
        */
        bool has_repeating_digits(int number) const;
    };
}