#include "RandomGenerator.h"

miit::algebra::RandomGenerator::RandomGenerator(int min, int max)
    : generator(std::random_device{}())
    , distribution(min, max)
{
}

int miit::algebra::RandomGenerator::generate()
{
    return distribution(generator);
}