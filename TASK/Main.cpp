#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <algorithm>
#include <string>
#include <iomanip>
#include "../Decision0/Furniture.h"
#include "../Decision0/Cabinet.h"
#include "../Decision0/Table.h"
#include "../Decision0/Chair.h"
#include "../Decision0/Order.h"
#include "../Decision0/FurnitureStore.h"

using namespace std;

/**
 * @brief Перечисление пунктов главного меню
 */
enum class MenuChoice {
    EXIT = 0,
    SHOW_ASSORTMENT = 1,
    SOLD_FURNITURE_COUNT = 2,
    ORDERS_IN_PERIOD = 3,
    CALCULATE_CUSTOM_ORDER = 4
};

/**
 * @brief Отображает главное меню
 */
void showMainMenu();

/**
 * @brief Обрабатывает выбор пользователя
 */
bool handleUserChoice(MenuChoice choice, FurnitureStore& store);

/**
 * @brief Демонстрирует ассортимент
 */
void demonstrateAssortment(FurnitureStore& store);

/**
 * @brief Демонстрирует количество проданной мебели
 */
void demonstrateSoldFurnitureCount(FurnitureStore& store);

/**
 * @brief Демонстрирует заказы за период
 */
void demonstrateOrdersInPeriod(FurnitureStore& store);

/**
 * @brief Демонстрирует расчет индивидуального заказа
 */
void demonstrateCustomOrder(FurnitureStore& store);

/**
 * @brief Получает ввод от пользователя
 */
string getInput(const string& prompt);

/**
 * @brief Точка входа в программу
 */
int main() {
    setlocale(LC_ALL, "Russian");

    FurnitureStore store;

    // Создаем тестовые данные
    tm prodDate = {};
    prodDate.tm_year = 124; // 2024
    prodDate.tm_mon = 0;    // январь
    prodDate.tm_mday = 15;

    auto cabinet1 = make_shared<Cabinet>("Книжный шкаф", 15000.0, 10,
        prodDate, 6, "Дуб");
    auto cabinet2 = make_shared<Cabinet>("Гардероб", 25000.0, 5,
        prodDate, 8, "Сосна");

    auto table1 = make_shared<Table>("Обеденный стол", 12000.0, 8,
        prodDate, 1.8, 0.9, "Прямоугольный");
    auto table2 = make_shared<Table>("Журнальный столик", 8000.0, 12,
        prodDate, 0.8, 0.8, "Квадратный");

    auto chair1 = make_shared<Chair>("Офисный стул", 4500.0, 15,
        prodDate, true, "Кожа");
    auto chair2 = make_shared<Chair>("Кухонный табурет", 2000.0, 20,
        prodDate, false, "Дерево");

    // Добавляем в магазин
    store.addFurniture(cabinet1);
    store.addFurniture(cabinet2);
    store.addFurniture(table1);
    store.addFurniture(table2);
    store.addFurniture(chair1);
    store.addFurniture(chair2);

    // Создаем тестовые заказы
    tm orderDate1 = {};
    orderDate1.tm_year = 124;
    orderDate1.tm_mon = 1; // февраль
    orderDate1.tm_mday = 10;

    auto order1 = make_shared<Order>(1, orderDate1, "Иванов И.И.");
    order1->addItem(cabinet1);
    order1->addItem(chair1);
    order1->addItem(chair1);
    store.addOrder(order1);

    tm orderDate2 = {};
    orderDate2.tm_year = 124;
    orderDate2.tm_mon = 1;
    orderDate2.tm_mday = 15;

    tm orderDate3 = {};
    orderDate3.tm_year = 124;
    orderDate3.tm_mon = 2; // март
    orderDate3.tm_mday = 5;

    auto order3 = make_shared<Order>(3, orderDate3, "Сидоров В.В.");
    order3->addItem(cabinet2);
    store.addOrder(order3);

    string systemTitle = " СИСТЕМА МЕБЕЛЬНОГО МАГАЗИНА ";
    cout << systemTitle << "\n\n";

    while (true) {
        showMainMenu();

        string choicePrompt = "Выберите операцию (0-4): ";
        cout << choicePrompt;

        int choice;
        cin >> choice;
        cin.ignore();

        if (cin.fail()) {
            string errorMessage = "Ошибка ввода. Попробуйте снова.\n";
            cout << errorMessage;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        bool shouldContinue = handleUserChoice(static_cast<MenuChoice>(choice), store);

        if (!shouldContinue) {
            string exitMessage = "Программа завершена.";
            cout << exitMessage << endl;
            break;
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.get();
    }

    return 0;
}

void showMainMenu() {
    string menuTitle = " ГЛАВНОЕ МЕНЮ СИСТЕМЫ МЕБЕЛЬНОГО МАГАЗИНА ";
    string option1 = "1 - Ассортимент мебели и цены";
    string option2 = "2 - Количество проданной мебели за период";
    string option3 = "3 - Список заказов за период";
    string option4 = "4 - Расчет стоимости индивидуального заказа";
    string option0 = "0 - Выход";

    cout << "\n" << menuTitle << "\n";
    cout << option1 << "\n";
    cout << option2 << "\n";
    cout << option3 << "\n";
    cout << option4 << "\n";
    cout << option0 << "\n";
    cout << "\n";
}

bool handleUserChoice(MenuChoice choice, FurnitureStore& store) {
    try {
        switch (choice) {
        case MenuChoice::SHOW_ASSORTMENT:
            demonstrateAssortment(store);
            break;
        case MenuChoice::SOLD_FURNITURE_COUNT:
            demonstrateSoldFurnitureCount(store);
            break;
        case MenuChoice::ORDERS_IN_PERIOD:
            demonstrateOrdersInPeriod(store);
            break;
        case MenuChoice::CALCULATE_CUSTOM_ORDER:
            demonstrateCustomOrder(store);
            break;
        case MenuChoice::EXIT:
            return false;
        default:
            string invalidChoiceMessage = "Неверный выбор! Попробуйте снова.\n";
            cout << invalidChoiceMessage;
            return true;
        }
    }
    catch (const exception& e) {
        string errorMessage = "Произошла ошибка: ";
        cout << errorMessage << e.what() << "\n";
    }
    catch (...) {
        string unknownErrorMessage = "Неизвестная ошибка.\n";
        cout << unknownErrorMessage;
    }

    return true;
}

string getInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void demonstrateAssortment(FurnitureStore& store) {
    string assortmentTitle = " АССОРТИМЕНТ МЕБЕЛИ И ЦЕНЫ ";
    string noFurnitureMessage = "Мебель отсутствует в ассортименте!";
    string foundMessage = "Найдено позиций: ";

    cout << "\n" << assortmentTitle << "\n";

    auto furnitureList = store.showAssortment();
    if (furnitureList.empty()) {
        cout << noFurnitureMessage << "\n";
    }
    else {
        cout << foundMessage << furnitureList.size() << "\n\n";

        for (size_t i = 0; i < furnitureList.size(); ++i) {
            cout << i + 1 << ". " << furnitureList[i]->getInfo() << "\n";
        }
    }
}

void demonstrateSoldFurnitureCount(FurnitureStore& store) {
    string countTitle = " КОЛИЧЕСТВО ПРОДАННОЙ МЕБЕЛИ ЗА ПЕРИОД ";
    string furnitureNamePrompt = "Введите название мебели: ";
    string startDateMessage = "Введите начальную дату:";
    string endDateMessage = "Введите конечную дату:";
    string dayPrompt = "День: ";
    string monthPrompt = "Месяц (1-12): ";
    string yearPrompt = "Год (например, 2024): ";
    string resultMessage = "Продано единиц: ";

    cout << "\n" << countTitle << "\n";

    string furnitureName = getInput(furnitureNamePrompt);

    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    cout << startDateMessage << "\n";
    cout << dayPrompt; cin >> startDay;
    cout << monthPrompt; cin >> startMonth;
    cout << yearPrompt; cin >> startYear;

    cout << endDateMessage << "\n";
    cout << dayPrompt; cin >> endDay;
    cout << monthPrompt; cin >> endMonth;
    cout << yearPrompt; cin >> endYear;
    cin.ignore();

    tm startDate = {};
    startDate.tm_mday = startDay;
    startDate.tm_mon = startMonth - 1;
    startDate.tm_year = startYear - 1900;

    tm endDate = {};
    endDate.tm_mday = endDay;
    endDate.tm_mon = endMonth - 1;
    endDate.tm_year = endYear - 1900;

    int count = store.getSoldFurnitureCount(furnitureName, startDate, endDate);
    cout << resultMessage << count << "\n";
}

void demonstrateOrdersInPeriod(FurnitureStore& store) {
    string ordersTitle = " СПИСОК ЗАКАЗОВ ЗА ПЕРИОД ";
    string noOrdersMessage = "В указанный период заказов нет.";
    string foundMessage = "Найдено заказов: ";
    string startDateMessage = "Введите начальную дату:";
    string endDateMessage = "Введите конечную дату:";
    string dayPrompt = "День: ";
    string monthPrompt = "Месяц (1-12): ";
    string yearPrompt = "Год (например, 2024): ";

    cout << "\n" << ordersTitle << "\n";

    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    cout << startDateMessage << "\n";
    cout << dayPrompt; cin >> startDay;
    cout << monthPrompt; cin >> startMonth;
    cout << yearPrompt; cin >> startYear;

    cout << endDateMessage << "\n";
    cout << dayPrompt; cin >> endDay;
    cout << monthPrompt; cin >> endMonth;
    cout << yearPrompt; cin >> endYear;
    cin.ignore();

    tm startDate = {};
    startDate.tm_mday = startDay;
    startDate.tm_mon = startMonth - 1;
    startDate.tm_year = startYear - 1900;

    tm endDate = {};
    endDate.tm_mday = endDay;
    endDate.tm_mon = endMonth - 1;
    endDate.tm_year = endYear - 1900;

    auto orders = store.getOrdersInPeriod(startDate, endDate);

    if (orders.empty()) {
        cout << noOrdersMessage << "\n";
    }
    else {
        cout << foundMessage << orders.size() << "\n\n";
        for (size_t i = 0; i < orders.size(); ++i) {
            cout << i + 1 << ". " << orders[i]->getInfo() << "\n\n";
        }
    }
}

void demonstrateCustomOrder(FurnitureStore& store) {
    string customTitle = " РАСЧЕТ СТОИМОСТИ ИНДИВИДУАЛЬНОГО ЗАКАЗА ";
    string basePricePrompt = "Введите базовую цену мебели: ";
    string markupPrompt = "Введите процент наценки за индивидуальный проект: ";
    string resultMessage = "Итоговая стоимость: ";

    cout << "\n" << customTitle << "\n";

    cout << basePricePrompt;
    double basePrice;
    cin >> basePrice;

    cout << markupPrompt;
    double markupPercentage;
    cin >> markupPercentage;
    cin.ignore();

    double finalPrice = store.calculateCustomOrderPrice(basePrice, markupPercentage);
    cout << resultMessage << finalPrice << " руб.\n";
}