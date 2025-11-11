#include "Task3.h"

namespace miit::algebra
{
    std::unique_ptr<Matrix> Task3::execute() const
    {
        auto result = std::make_unique<Matrix>(get_matrix_size());

        for (size_t i = 0; i < get_matrix_size(); ++i)
        {
            if (i % 2 == 0)
            {
                (*result)[i] = static_cast<int>(i) * get_matrix_element(i);
            }
            else
            {
                (*result)[i] = -get_matrix_element(i);
            }
        }

        return result;
    }

    std::string Task3::get_name() const
    {
        return "Task3 - Преобразование массива по правилу";
    }
}