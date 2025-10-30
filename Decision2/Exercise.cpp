#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
        : matrix(std::move(matrix))
        , generator(std::move(generator))
    {
    }

    const Matrix& Exercise::get_matrix() const
    {
        return *matrix;
    }

    void Exercise::fill_matrix()
    {
        if (matrix && generator)
        {
            matrix->fill(std::move(generator));
        }
    }

    std::unique_ptr<Matrix> Exercise::execute_task1() const
    {
        Task1 task;
        return task.execute(*matrix);
    }

    std::unique_ptr<Matrix> Exercise::execute_task2() const
    {
        Task2 task;
        return task.execute(*matrix);
    }

    std::unique_ptr<Matrix> Exercise::execute_task3() const
    {
        Task3 task;
        return task.execute(*matrix);
    }

    std::string Exercise::get_task1_name() const
    {
        Task1 task;
        return task.get_name();
    }

    std::string Exercise::get_task2_name() const
    {
        Task2 task;
        return task.get_name();
    }

    std::string Exercise::get_task3_name() const
    {
        Task3 task;
        return task.get_name();
    }
}