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

    std::unique_ptr<Matrix> Exercise::execute_task(int task_number) const
    {
        switch (task_number)
        {
        case 1:
        {
            Task1 task1; 
            return task1.execute(*matrix); 
        }
        case 2:
        {
            Task2 task2; 
            return task2.execute(*matrix); 
        }
        case 3:
        {
            Task3 task3; 
            return task3.execute(*matrix); 
        }
        default:
            throw std::invalid_argument("Invalid task number: " + std::to_string(task_number) +
                ". Valid values are 1, 2, 3.");
        }
    }

    std::string Exercise::get_task_name(int task_number) const
    {
        switch (task_number)
        {
        case 1:
            return "Task1";
        case 2:
            return "Task2";
        case 3:
            return "Task3";
        default:
            throw std::invalid_argument("Invalid task number: " + std::to_string(task_number) +
                ". Valid values are 1, 2, 3.");
        }
    }
}