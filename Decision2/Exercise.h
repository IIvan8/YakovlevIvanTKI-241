#pragma once

#include "Matrix.h"
#include "Generator.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include <memory>
#include <vector>

namespace miit::algebra
{
    /**
    * @brief Класс для выполнения заданий над матрицей
    */
    class Exercise
    {
    private:
        std::unique_ptr<Matrix> matrix;
        std::unique_ptr<Generator> generator;

    public:
        /**
        * @brief Конструктор упражнения
        * @param matrix Умный указатель на матрицу
        * @param generator Умный указатель на генератор
        */
        Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);

        /**
        * @brief Возвращает исходную матрицу
        * @return Ссылка на исходную матрицу
        */
        const Matrix& get_matrix() const;

        /**
        * @brief Заполняет матрицу с помощью генератора
        */
        void fill_matrix();

        /**
        * @brief Выполняет задание 1
        * @return Результат выполнения задания 1
        */
        std::unique_ptr<Matrix> execute_task1() const;

        /**
        * @brief Выполняет задание 2
        * @return Результат выполнения задания 2
        */
        std::unique_ptr<Matrix> execute_task2() const;

        /**
        * @brief Выполняет задание 3
        * @return Результат выполнения задания 3
        */
        std::unique_ptr<Matrix> execute_task3() const;

        /**
        * @brief Возвращает название задания 1
        */
        std::string get_task1_name() const;

        /**
        * @brief Возвращает название задания 2
        */
        std::string get_task2_name() const;

        /**
        * @brief Возвращает название задания 3
        */
        std::string get_task3_name() const;
    };
}