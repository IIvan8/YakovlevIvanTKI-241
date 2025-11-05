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
    /**
    * @brief Генератор постоянных значений
    */
    class ConstantGenerator : public Generator
    {
    private:
        int constant_value;

    public:
        /**
        * @brief Конструктор генератора постоянных значений
        * @param value Постоянное значение, которое будет возвращаться
        */
        explicit ConstantGenerator(int value) : constant_value(value) {}

        /**
        * @brief Всегда возвращает одно и то же значение
        * @return Заданное постоянное значение
        */
        int generate() override 
        {
            return constant_value;
        }
    };
}