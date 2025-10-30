#include "Matrix.h"
#include <sstream>

namespace miit::algebra
{
    Matrix::Matrix(size_t size)
        : data(size)
    {
    }

    Matrix::Matrix(const std::vector<int>& values)
        : data(values)
    {
    }

    void Matrix::fill(std::unique_ptr<Generator> generator)
    {
        for (auto& element : data)
        {
            element = generator->generate();
        }
    }

    std::string Matrix::to_string() const
    {
        std::ostringstream oss;
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (i > 0) oss << " ";
            oss << data[i];
        }
        return oss.str();
    }

    size_t Matrix::size() const
    {
        return data.size();
    }

    bool Matrix::empty() const
    {
        return data.empty();
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        os << matrix.to_string();
        return os;
    }

    std::istream& operator>>(std::istream& is, Matrix& matrix)
    {
        for (auto& element : matrix.data)
        {
            is >> element;
        }
        return is;
    }

    int& Matrix::operator[](size_t index)
    {
        return data[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        return data[index];
    }

    const std::vector<int>& Matrix::operator*() const
    {
        return data;
    }
}