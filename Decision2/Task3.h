#pragma once

#include "Exercise.h"
#include "Matrix.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 3: Преобразование массива по правилу
    */
    class Task3 : public Task
    {
    public:
        /**
        * @brief Выполняет задание
        * @param matrix Исходная матрица
        * @return Результирующая матрица
        */
        std::unique_ptr<Matrix> execute(const Matrix& matrix) const override;
    };
}