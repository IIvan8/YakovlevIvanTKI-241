#include "Task3.h"

namespace miit::algebra
{
    std::unique_ptr<Matrix> Task3::execute(const Matrix& matrix) const
    {
        auto result = std::make_unique<Matrix>(matrix.size());

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (i % 2 == 0)
            {
                (*result)[i] = static_cast<int>(i) * matrix[i];
            }
            else
            {
                (*result)[i] = -matrix[i];
            }
        }

        return result;
    }
}