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
            Assert::IsTrue(result.find("1") != std::string::npos);
            Assert::IsTrue(result.find("2") != std::string::npos);
            Assert::IsTrue(result.find("3") != std::string::npos);
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

        TEST_METHOD(Task1GetName)
        {
            Task1 task;
            Assert::AreEqual(std::string("Замена последнего отрицательного элемента на модуль первого"), task.get_name());
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

        TEST_METHOD(Task2GetName)
        {
            Task2 task;
            Assert::AreEqual(std::string("Удаление элементов с повторяющимися цифрами"), task.get_name());
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

        TEST_METHOD(Task3GetName)
        {
            Task3 task;
            Assert::AreEqual(std::string("Преобразование массива по правилу: четные индексы - умножение, нечетные - смена знака"), task.get_name());
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
        }

        TEST_METHOD(ExerciseTaskExecution)
        {
            auto matrix = std::make_unique<Matrix>(std::vector<int>{1, -2, 3, -4, 5});
            auto exercise = std::make_unique<Exercise>(
                std::move(matrix),
                std::make_unique<RandomGenerator>(0, 1)
            );

            auto task1_result = exercise->execute_task1();
            auto task2_result = exercise->execute_task2();
            auto task3_result = exercise->execute_task3();

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

            Assert::IsFalse(exercise->get_task1_name().empty());
            Assert::IsFalse(exercise->get_task2_name().empty());
            Assert::IsFalse(exercise->get_task3_name().empty());
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
    };
}