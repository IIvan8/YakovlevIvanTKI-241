#pragma once

#include "Exercise.h"
#include <memory>
#include <string>

namespace miit::algebra
{
    /**
    * @brief Задание 1: Замена последнего отрицательного элемента на модуль первого
    */
    class Task1 : public Exercise
    {
    public:
        /**
        * @brief Конструктор
        * @param matrix Указатель на матрицу
        * @param generator Указатель на генератор
        */
        Task1(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
            : Exercise(std::move(matrix), std::move(generator)) {}

        /**
        * @brief Выполняет задание: заменяет последний отрицательный элемент на модуль первого элемента
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
        * @brief Находит индекс последнего отрицательного элемента
        * @param matrix Матрица для поиска
        * @return Индекс последнего отрицательного элемента или размер матрицы если не найден
        */
        size_t find_last_negative(const Matrix& matrix) const;
    };
}