#include "ConstantGenerator.h"

namespace miit::algebra
{
    ConstantGenerator::ConstantGenerator(int value)
        : constant_value(value)
    {
    }

    int ConstantGenerator::generate()
    {
        return constant_value;
    }
}