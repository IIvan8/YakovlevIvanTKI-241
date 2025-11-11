#include "Exercise.h"
#include <stdexcept>

namespace miit::algebra
{
    Exercise::Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
        : matrix(std::move(matrix)), generator(std::move(generator))
    {
        if (this->matrix == nullptr)
        {
            throw std::invalid_argument("Matrix cannot be null");
        }
    }

    const Matrix& Exercise::get_matrix() const
    {
        return *matrix;
    }

    size_t Exercise::get_matrix_size() const
    {
        return matrix->size();
    }

    int Exercise::get_matrix_element(size_t index) const
    {
        return (*matrix)[index];
    }

    bool Exercise::is_matrix_empty() const
    {
        return matrix->empty();
    }
}