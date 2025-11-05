#include "CppUnitTest.h"
#include <vector>
#include <memory>
#include <string>
#include "../Decision2/Matrix.h"
#include "../Decision2/RandomGenerator.h"
#include "../Decision2/IStreamGenerator.h"
#include "../Decision2/Exercise.h"
#include "../Decision2/Task1.h"
#include "../Decision2/Task2.h"
#include "../Decision2/Task3.h"
#include "../Decision2/Generator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace MatrixTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestMatrixConstructorWithSize)
        {
            Matrix matrix(5);
            Assert::AreEqual(size_t(5), matrix.size());
        }

        TEST_METHOD(TestMatrixConstructorWithValues)
        {
            std::vector<int> values = { 1, 2, 3, 4, 5 };
            Matrix matrix(values);
            Assert::AreEqual(size_t(5), matrix.size());
        }

        TEST_METHOD(TestMatrixIndexingOperator)
        {
            std::vector<int> values = { 1, 2, 3, 4, 5 };
            Matrix matrix(values);
            Assert::AreEqual(3, matrix[2]);
        }

        TEST_METHOD(TestMatrixIndexingModification)
        {
            Matrix matrix(3);
            matrix[0] = 10;
            matrix[1] = 20;
            matrix[2] = 30;
            Assert::AreEqual(10, matrix[0]);
            Assert::AreEqual(20, matrix[1]);
            Assert::AreEqual(30, matrix[2]);
        }

        TEST_METHOD(TestMatrixToString)
        {
            std::vector<int> values = { 1, 2, 3 };
            Matrix matrix(values);
            std::string result = matrix.to_string();
            Assert::AreEqual(std::string("1 2 3"), result);
        }

        TEST_METHOD(TestEmptyMatrix)
        {
            Matrix matrix(0);
            Assert::IsTrue(matrix.empty());
            Assert::AreEqual(size_t(0), matrix.size());
        }

        TEST_METHOD(TestNonEmptyMatrix)
        {
            Matrix matrix(3);
            Assert::IsFalse(matrix.empty());
        }
        TEST_METHOD(TestMatrixFillWithGenerator)
        {
            Matrix matrix(3);
            auto generator = std::make_unique<ConstantGenerator>(7);
            matrix.fill(std::move(generator));

            Assert::AreEqual(7, matrix[0]);
            Assert::AreEqual(7, matrix[1]);
            Assert::AreEqual(7, matrix[2]);
        }
        TEST_METHOD(TestMatrixDereferenceOperator)
        {
            std::vector<int> values = { 1, 2, 3 };
            Matrix matrix(values);
            const std::vector<int>& data = *matrix;
            Assert::AreEqual(values.size(), data.size());
            for (size_t i = 0; i < values.size(); ++i) {
                Assert::AreEqual(values[i], data[i]);
            }
        }
        TEST_METHOD(TestMatrixIterators)
        {
            std::vector<int> values = { 1, 2, 3 };
            Matrix matrix(values);

            size_t count = 0;
            for (auto it = matrix.begin(); it != matrix.end(); ++it) {
                Assert::AreEqual(values[count], *it);
                count++;
            }
            Assert::AreEqual(values.size(), count);
        }
    };

    TEST_CLASS(Task1Tests)
    {
    public:

        TEST_METHOD(Task1WithNegativeElements)
        {
            std::vector<int> values = { 5, -2, 3, -4, 1 };
            Matrix matrix(values);
            Task1 task;
            auto result = task.execute(matrix);

            // -4 (последний отрицательный) должен быть заменен на |5| = 5
            Assert::AreEqual(5, (*result)[3]);
            // Остальные элементы должны остаться без изменений
            Assert::AreEqual(5, (*result)[0]);
            Assert::AreEqual(-2, (*result)[1]);
            Assert::AreEqual(3, (*result)[2]);
            Assert::AreEqual(1, (*result)[4]);
        }

        TEST_METHOD(Task1WithoutNegativeElements)
        {
            std::vector<int> values = { 1, 2, 3, 4, 5 };
            Matrix matrix(values);
            Task1 task;
            auto result = task.execute(matrix);

            // Массив должен остаться неизменным
            for (size_t i = 0; i < values.size(); ++i) {
                Assert::AreEqual(values[i], (*result)[i]);
            }
        }

        TEST_METHOD(Task1WithEmptyMatrix)
        {
            Matrix matrix(0);
            Task1 task;
            auto result = task.execute(matrix);
            Assert::IsTrue(result->empty());
        }

        TEST_METHOD(Task1WithSingleNegativeElement)
        {
            std::vector<int> values = { -5 };
            Matrix matrix(values);
            Task1 task;
            auto result = task.execute(matrix);

            // -5 должен быть заменен на | -5 | = 5
            Assert::AreEqual(5, (*result)[0]);
        }
        TEST_METHOD(Task1WithAllNegativeElements)
        {
            std::vector<int> values = { -1, -2, -3, -4 };
            Matrix matrix(values);
            Task1 task;
            auto result = task.execute(matrix);

            // Последний отрицательный (-4) должен быть заменен на | -1 | = 1
            Assert::AreEqual(1, (*result)[3]);
            // Остальные остаются без изменений
            Assert::AreEqual(-1, (*result)[0]);
            Assert::AreEqual(-2, (*result)[1]);
            Assert::AreEqual(-3, (*result)[2]);
        }
    };

    TEST_CLASS(Task2Tests)
    {
    public:

        TEST_METHOD(Task2WithRepeatingDigits)
        {
            std::vector<int> values = { 112, 123, 122, 456, 111 };
            Matrix matrix(values);
            Task2 task;
            auto result = task.execute(matrix);

            // Должны остаться только 123 и 456 (без повторяющихся цифр)
            Assert::AreEqual(size_t(2), result->size());
            Assert::AreEqual(123, (*result)[0]);
            Assert::AreEqual(456, (*result)[1]);
        }

        TEST_METHOD(Task2WithoutRepeatingDigits)
        {
            std::vector<int> values = { 123, 456, 789 };
            Matrix matrix(values);
            Task2 task;
            auto result = task.execute(matrix);

            // Все элементы должны остаться
            Assert::AreEqual(size_t(3), result->size());
            Assert::AreEqual(123, (*result)[0]);
            Assert::AreEqual(456, (*result)[1]);
            Assert::AreEqual(789, (*result)[2]);
        }

        TEST_METHOD(Task2WithNegativeNumbers)
        {
            std::vector<int> values = { -112, -123, 456 };
            Matrix matrix(values);
            Task2 task;
            auto result = task.execute(matrix);

            // Должны остаться -123 и 456
            Assert::AreEqual(size_t(2), result->size());
            Assert::AreEqual(-123, (*result)[0]);
            Assert::AreEqual(456, (*result)[1]);
        }

        TEST_METHOD(Task2WithSingleDigitNumbers)
        {
            std::vector<int> values = { 1, 2, 3 };
            Matrix matrix(values);
            Task2 task;
            auto result = task.execute(matrix);

            // Все однозначные числа не имеют повторяющихся цифр
            Assert::AreEqual(size_t(3), result->size());
        }
    };

    TEST_CLASS(Task3Tests)
    {
    public:

        TEST_METHOD(Task3Transformation)
        {
            std::vector<int> values = { 1, 2, 3, 4, 5 };
            Matrix matrix(values);
            Task3 task;
            auto result = task.execute(matrix);

            // Ожидаемый результат: четные индексы - умножение, нечетные - смена знака
            std::vector<int> expected = { 0, -2, 6, -4, 20 };
            Assert::AreEqual(expected.size(), result->size());

            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i], (*result)[i]);
            }
        }

        TEST_METHOD(Task3WithEmptyMatrix)
        {
            Matrix matrix(0);
            Task3 task;
            auto result = task.execute(matrix);
            Assert::IsTrue(result->empty());
        }

        TEST_METHOD(Task3WithSingleElement)
        {
            std::vector<int> values = { 10 };
            Matrix matrix(values);
            Task3 task;
            auto result = task.execute(matrix);

            // Индекс 0 (четный): 0 * 10 = 0
            Assert::AreEqual(0, (*result)[0]);
        }
    };

    TEST_CLASS(ExerciseTests)
    {
    public:

        TEST_METHOD(ExerciseConstructorAndGetMatrix)
        {
            auto matrix = std::make_unique<Matrix>(std::vector<int>{1, 2, 3});
            auto exercise = std::make_unique<Exercise>(
                std::move(matrix),
                std::make_unique<RandomGenerator>(0, 1)
            );

            Assert::AreEqual(size_t(3), exercise->get_matrix().size());
            Assert::AreEqual(1, exercise->get_matrix()[0]);
            Assert::AreEqual(2, exercise->get_matrix()[1]);
            Assert::AreEqual(3, exercise->get_matrix()[2]);
        }

        TEST_METHOD(ExerciseTaskExecution)
        {
            auto matrix = std::make_unique<Matrix>(std::vector<int>{1, -2, 3, -4, 5});
            auto exercise = std::make_unique<Exercise>(
                std::move(matrix),
                std::make_unique<RandomGenerator>(0, 1)
            );

            auto task1_result = exercise->execute_task(1);
            auto task2_result = exercise->execute_task(2);
            auto task3_result = exercise->execute_task(3);

            Assert::IsTrue(task1_result != nullptr);
            Assert::IsTrue(task2_result != nullptr);
            Assert::IsTrue(task3_result != nullptr);
            Assert::AreEqual(size_t(5), task1_result->size());
            Assert::IsTrue(task2_result->size() <= size_t(5));
            Assert::AreEqual(size_t(5), task3_result->size());
        }

        TEST_METHOD(ExerciseTaskNames)
        {
            auto matrix = std::make_unique<Matrix>(std::vector<int>{1, 2, 3});
            auto exercise = std::make_unique<Exercise>(
                std::move(matrix),
                std::make_unique<RandomGenerator>(0, 1)
            );

            Assert::AreEqual(std::string("Task1"), exercise->get_task_name(1));
            Assert::AreEqual(std::string("Task2"), exercise->get_task_name(2));
            Assert::AreEqual(std::string("Task3"), exercise->get_task_name(3));
        }
    };

    TEST_CLASS(GeneratorTests)
    {
    public:

        TEST_METHOD(RandomGeneratorWithinRange)
        {
            RandomGenerator gen(1, 10);
            for (int i = 0; i < 100; ++i) {
                int value = gen.generate();
                Assert::IsTrue(value >= 1 && value <= 10);
            }
        }

        TEST_METHOD(RandomGeneratorBoundaryValues)
        {
            RandomGenerator gen(5, 5);
            int value = gen.generate();
            Assert::AreEqual(5, value);
        }

        TEST_METHOD(ConstantGeneratorReturnsConstantValue)
        {
            ConstantGenerator gen(42);
            Assert::AreEqual(42, gen.generate());
            Assert::AreEqual(42, gen.generate());
            Assert::AreEqual(42, gen.generate());
        }

        TEST_METHOD(ConstantGeneratorWithZero)
        {
            ConstantGenerator gen(0);
            Assert::AreEqual(0, gen.generate());
        }

        TEST_METHOD(ConstantGeneratorWithNegativeValue)
        {
            ConstantGenerator gen(-100);
            Assert::AreEqual(-100, gen.generate()); 
        }

        TEST_METHOD(ConstantGeneratorWithMatrixFill)
        {
            auto matrix = std::make_unique<Matrix>(5);
            auto constant_gen = std::make_unique<ConstantGenerator>(7);

            matrix->fill(std::move(constant_gen));

            for (size_t i = 0; i < matrix->size(); ++i) {
                Assert::AreEqual(7, (*matrix)[i]);
            }
        }
    };
}
