#pragma once

#include "Generator.h"
#include <iostream>
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Генератор значений из входного потока
    */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
        * @brief Конструктор генератора из потока
        * @param in Входной поток (по умолчанию std::cin)
        */
        explicit IStreamGenerator(std::istream& in = std::cin);

        /**
        * @brief Читает значение из потока
        * @return Прочитанное значение
        */
        int generate() override;
    };
}