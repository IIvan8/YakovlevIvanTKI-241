#pragma once

#include "Matrix.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 3: Преобразование массива по правилу
    */
    class Task3
    {
    public:
        /**
        * @brief Выполняет задание
        * @param matrix Исходная матрица
        * @return Результирующая матрица
        */
        std::unique_ptr<Matrix> execute(const Matrix& matrix) const;

        /**
        * @brief Возвращает название задания
        * @return Название задания
        */
        std::string get_name() const;
    };
}