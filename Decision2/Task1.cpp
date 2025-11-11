#include "Task1.h"
#include <cmath>

namespace miit::algebra
{
    std::unique_ptr<Matrix> Task1::execute() const
    {
        auto result = std::make_unique<Matrix>(get_matrix());
        size_t last_neg_index = find_last_negative(get_matrix());

        if (last_neg_index < get_matrix_size() && !is_matrix_empty())
        {
            (*result)[last_neg_index] = std::abs(get_matrix_element(0));
        }

        return result;
    }

    size_t Task1::find_last_negative(const Matrix& matrix) const
    {
        for (size_t i = matrix.size(); i-- > 0;)
        {
            if (matrix[i] < 0)
            {
                return i;
            }
        }
        return matrix.size();
    }

    std::string Task1::get_name() const
    {
        return "Task1 - Замена последнего отрицательного элемента на модуль первого";
    }
}