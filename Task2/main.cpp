#include <iostream>
#include <memory>
#include <locale>
#include "../Decision2/Generator.h"           
#include "../Decision2/ConstantGenerator.h"   
#include "../Decision2/IStreamGenerator.h"
#include "../Decision2/RandomGenerator.h"
#include "../Decision2/Matrix.h"
#include "../Decision2/Exercise.h"
#include "../Decision2/Task1.h"
#include "../Decision2/Task2.h"
#include "../Decision2/Task3.h"

using namespace miit::algebra;
using namespace std;

/**
* @brief Очищает буфер ввода
*/
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
* @brief Enum для выбора способа заполнения массива
*/
enum InputMethod
{
    RANDOM = 0,
    KEYBOARD = 1,
    CONSTANT = 2
};

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        cout << "Выберите способ заполнения массива:" << endl;
        cout << RANDOM << " - случайный ввод" << endl;
        cout << KEYBOARD << " - ввод с клавиатуры" << endl;
        cout << CONSTANT << " - с константой" << endl;
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;
        clearInputBuffer();

        unique_ptr<Matrix> matrix;
        size_t size;

        switch (choice) {
        case RANDOM: {
            cout << "Введите размер массива: ";
            cin >> size;
            clearInputBuffer();

            if (size == 0) {
                throw invalid_argument("Размер массива не может быть 0");
            }

            matrix = make_unique<Matrix>(size);

            int min_val = 0, max_val = 0;
            cout << "Минимальное значение: ";
            cin >> min_val;
            cout << "Максимальное значение: ";
            cin >> max_val;
            clearInputBuffer();

            auto random_gen = make_unique<RandomGenerator>(min_val, max_val);
            matrix->fill(move(random_gen));
            cout << "Массив заполнен случайными числами от " << min_val << " до " << max_val << endl;
            break;
        }
        case KEYBOARD: {
            cout << "Введите размер массива: ";
            cin >> size;
            clearInputBuffer();

            if (size == 0) {
                throw invalid_argument("Размер массива не может быть 0");
            }

            matrix = make_unique<Matrix>(size);
            auto input_gen = make_unique<IStreamGenerator>();
            cout << "Введите " << size << " элементов массива: ";
            matrix->fill(move(input_gen));
            clearInputBuffer();
            cout << "Массив заполнен вручную" << endl;
            break;
        }
        case CONSTANT: {
            cout << "Введите размер массива: ";
            cin >> size;
            clearInputBuffer();

            if (size == 0) {
                throw invalid_argument("Размер массива не может быть 0");
            }

            int constant_value = 0;
            cout << "Введите значение для заполнения: ";
            cin >> constant_value;
            clearInputBuffer();

            matrix = make_unique<Matrix>(size);
            auto const_gen = make_unique<ConstantGenerator>(constant_value);
            matrix->fill(move(const_gen));
            cout << "Массив заполнен константой " << constant_value << endl;
            break;
        }
        default:
            throw invalid_argument("Неверный выбор метода ввода");
        }

        cout << "\nИсходный массив: " << *matrix << endl;
        cout << endl;

        // Создание и выполнение Task1
        auto task1 = make_unique<Task1>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        auto result1 = task1->execute();
        cout << task1->get_name() << ":" << endl;
        cout << "Результат: " << *result1 << endl;
        cout << endl;

        // Создание и выполнение Task2
        auto task2 = make_unique<Task2>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        auto result2 = task2->execute();
        cout << task2->get_name() << ":" << endl;
        cout << "Результат: " << *result2 << endl;
        cout << endl;

        // Создание и выполнение Task3
        auto task3 = make_unique<Task3>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        auto result3 = task3->execute();
        cout << task3->get_name() << ":" << endl;
        cout << "Результат: " << *result3 << endl;

        cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}