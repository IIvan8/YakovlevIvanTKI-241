#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>
#include <vector>

namespace miit::algebra
{
    /**
    * @brief Базовый класс для всех заданий
    */
    class Task
    {
    public:
        virtual ~Task() = default;

        /**
        * @brief Выполняет задание
        * @param matrix Исходная матрица
        * @return Результирующая матрица
        */
        virtual std::unique_ptr<Matrix> execute(const Matrix& matrix) const = 0;
    };

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
        * @brief Выполняет указанное задание
        * @param task_number Номер задания (1, 2 или 3)
        * @return Результат выполнения задания
        */
        virtual std::unique_ptr<Matrix> execute_task(int task_number) const;

        /**
        * @brief Возвращает название указанного задания
        * @param task_number Номер задания (1, 2 или 3)
        * @return Название задания
        */
        virtual std::string get_task_name(int task_number) const;
    };
}   