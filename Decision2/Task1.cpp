#include "Task1.h"
#include <cmath>

namespace miit::algebra
{
    std::unique_ptr<Matrix> Task1::execute(const Matrix& matrix) const
    {
        auto result = std::make_unique<Matrix>(matrix);
        size_t last_neg_index = find_last_negative(matrix);

        if (last_neg_index < matrix.size() && !matrix.empty())
        {
            (*result)[last_neg_index] = std::abs(matrix[0]);
        }

        return result;
    }

    std::string Task1::get_name() const
    {
        return "Замена последнего отрицательного элемента на модуль первого";
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
}