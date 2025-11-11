#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>
#include <vector>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Базовый класс для всех заданий
    */
    class Exercise
    {
    private:
        std::unique_ptr<Matrix> matrix;
        std::unique_ptr<Generator> generator;

    public:
        /**
        * @brief Конструктор упражнения
        */
        Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);

        virtual ~Exercise() = default;

        /**
        * @brief Возвращает исходную матрицу
        */
        const Matrix& get_matrix() const;

        /**
        * @brief Возвращает размер матрицы
        */
        size_t get_matrix_size() const;

        /**
        * @brief Возвращает элемент матрицы по индексу
        */
        int get_matrix_element(size_t index) const;

        /**
        * @brief Проверяет пуста ли матрица
        */
        bool is_matrix_empty() const;

        /**
        * @brief Выполняет задание - виртуальный метод
        */
        virtual std::unique_ptr<Matrix> execute() const = 0;

        /**
        * @brief Возвращает название задания
        */
        virtual std::string get_name() const = 0;
    };
}