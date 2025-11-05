#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "Generator.h"

namespace miit::algebra
{
    /**
    * @brief Класс для работы с одномерным массивом (матрицей-вектором)
    */
    class Matrix
    {
    private:
        std::vector<int> data;

    public:
        // Конструкторы по умолчанию
        Matrix() = default;
        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) = default;
        ~Matrix() = default;

        /**
        * @brief Конструктор с заданным размером
        * @param size Размер матрицы
        */
        explicit Matrix(size_t size);

        /**
        * @brief Конструктор с инициализацией значениями
        * @param values Вектор значений
        */
        explicit Matrix(const std::vector<int>& values);

        /**
        * @brief Заполняет матрицу с помощью генератора
        * @param generator Умный указатель на генератор
        */
        void fill(std::unique_ptr<Generator> generator);

        /**
        * @brief Возвращает строковое представление матрицы
        * @return Строка с элементами матрицы
        */
        std::string to_string() const;

        /**
        * @brief Возвращает размер матрицы
        * @return Размер матрицы
        */
        size_t size() const;

        /**
        * @brief Проверяет пуста ли матрица
        * @return true если матрица пуста
        */
        bool empty() const;

        // Операторы
        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) = default;

        /**
        * @brief Оператор сдвига влево (вывод)
        * @param os Выходной поток
        * @param matrix Матрица для вывода
        * @return Ссылка на выходной поток
        */
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

        /**
        * @brief Оператор сдвига вправо (ввод)
        * @param is Входной поток
        * @param matrix Матрица для ввода
        * @return Ссылка на входной поток
        */
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);

        /**
        * @brief Оператор индексирования
        * @param index Индекс элемента
        * @return Ссылка на элемент
        */
        int& operator[](size_t index);

        /**
        * @brief Константный оператор индексирования
        * @param index Индекс элемента
        * @return Константная ссылка на элемент
        */
        const int& operator[](size_t index) const;

        /**
        * @brief Оператор разыменования (возвращает внутренний вектор)
        * @return Внутренний вектор данных
        */
        const std::vector<int>& operator*() const;

        /**
        * @brief Возвращает итератор на начало
        */
        auto begin() { return data.begin(); }

        /**
        * @brief Возвращает константный итератор на начало
        */
        auto begin() const { return data.begin(); }

        /**
        * @brief Возвращает итератор на конец
        */
        auto end() { return data.end(); }

        /**
        * @brief Возвращает константный итератор на конец
        */
        auto end() const { return data.end(); }
    };
}   