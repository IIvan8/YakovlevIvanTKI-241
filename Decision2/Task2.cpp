#include "Task2.h"
#include <string>
#include <cmath>
#include <vector>

namespace miit::algebra
{
    std::unique_ptr<Matrix> Task2::execute() const
    {
        std::vector<int> new_data;

        const Matrix& mat = get_matrix();
        for (const auto& element : mat)
        {
            if (!has_repeating_digits(element))
            {
                new_data.push_back(element);
            }
        }

        return std::make_unique<Matrix>(new_data);
    }

    bool Task2::has_repeating_digits(int number) const
    {
        std::string num_str = std::to_string(std::abs(number));

        for (size_t i = 0; i < num_str.length() - 1; ++i)
        {
            if (num_str[i] == num_str[i + 1])
            {
                return true;
            }
        }

        return false;
    }

    std::string Task2::get_name() const
    {
        return "Task2 - Удаление элементов с повторяющимися цифрами";
    }
}