#pragma once
#include "Generator.h"

namespace miit::algebra
{
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
        explicit ConstantGenerator(int value);

        /**
        * @brief Всегда возвращает одно и то же значение
        * @return Заданное постоянное значение
        */
        int generate() override;
    };
}