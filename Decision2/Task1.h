#pragma once

#include "Exercise.h"
#include "Matrix.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 1: Замена последнего отрицательного элемента на модуль первого
    */
    class Task1 : public Task
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
        * @brief Находит индекс последнего отрицательного элемента
        * @param matrix Матрица для поиска
        * @return Индекс последнего отрицательного элемента или size если не найден
        */
        size_t find_last_negative(const Matrix& matrix) const;
    };
}   