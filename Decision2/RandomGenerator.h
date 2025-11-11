#pragma once

#include "Generator.h"
#include <random>
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Генератор случайных чисел
    */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
        * @brief Конструктор генератора случайных чисел
        * @param min Минимальное значение
        * @param max Максимальное значение
        */
        RandomGenerator(int min, int max);

        /**
        * @brief Генерирует случайное число
        * @return Случайное число в заданном диапазоне
        */
        int generate() override;
    };
}