#pragma once

namespace miit::algebra
{
    /**
    * @brief Абстрактный генератор значений для заполнения матрицы
    */
    class Generator
    {
    public:
        virtual ~Generator() = default;

        /**
        * @brief Генерирует следующее значение
        * @return Сгенерированное значение
        */
        virtual int generate() = 0;
    };
}