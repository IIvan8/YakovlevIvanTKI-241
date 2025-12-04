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
#include "../Decision0/CustomOrder.h"
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
    CALCULATE_CUSTOM_ORDER = 4,
    DATABASE_STATISTICS = 5,
    ADD_NEW_FURNITURE = 6,
    ADD_NEW_ORDER = 7,
    ADD_NEW_CUSTOM_ORDER = 8
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
 * @brief Демонстрирует статистику
 */
void demonstrateDatabaseStatistics(FurnitureStore& store);

/**
 * @brief Добавляет новую мебель
 */
void addNewFurniture(FurnitureStore& store);

/**
 * @brief Добавляет новый заказ
 */
void addNewOrder(FurnitureStore& store);

/**
 * @brief Добавляет новый индивидуальный заказ
 */
void addNewCustomOrder(FurnitureStore& store);

/**
 * @brief Создает тестовые данные
 */
void createTestData(FurnitureStore& store);

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
    createTestData(store);

    string systemTitle = " СИСТЕМА МЕБЕЛЬНОГО МАГАЗИНА ";
    cout << systemTitle << "\n\n";

    showMainMenu();

    string choicePrompt = "Выберите операцию: ";
    cout << choicePrompt;

    int choice;
    cin >> choice;
    cin.ignore();

    if (cin.fail()) {
        string errorMessage = "Ошибка ввода. Программа завершена.";
        cout << errorMessage << endl;
        return 1;
    }

    bool shouldContinue = handleUserChoice(static_cast<MenuChoice>(choice), store);

    if (!shouldContinue) {
        string exitMessage = "Программа завершена.";
        cout << exitMessage << endl;
        return 0;
    }

    return 0;
}

void showMainMenu() {
    string menuTitle = " ГЛАВНОЕ МЕНЮ СИСТЕМЫ МЕБЕЛЬНОГО МАГАЗИНА ";
    string option1 = "1 - Ассортимент мебели и цены";
    string option2 = "2 - Количество проданной мебели за период";
    string option3 = "3 - Список заказов за период";
    string option4 = "4 - Расчет стоимости индивидуального заказа";
    string option5 = "5 - Статистика магазина";
    string option6 = "6 - Добавить новую мебель";
    string option7 = "7 - Создать новый заказ";
    string option8 = "8 - Создать индивидуальный заказ";
    string option0 = "0 - Выход";

    cout << "\n" << menuTitle << "\n";
    cout << option1 << "\n";
    cout << option2 << "\n";
    cout << option3 << "\n";
    cout << option4 << "\n";
    cout << option5 << "\n";
    cout << option6 << "\n";
    cout << option7 << "\n";
    cout << option8 << "\n";
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
        case MenuChoice::DATABASE_STATISTICS:
            demonstrateDatabaseStatistics(store);
            break;
        case MenuChoice::ADD_NEW_FURNITURE:
            addNewFurniture(store);
            break;
        case MenuChoice::ADD_NEW_ORDER:
            addNewOrder(store);
            break;
        case MenuChoice::ADD_NEW_CUSTOM_ORDER:
            addNewCustomOrder(store);
            break;
        case MenuChoice::EXIT:
            return false;
        default:
            string invalidChoiceMessage = "Неверный выбор! Программа завершена.";
            cout << invalidChoiceMessage << endl;
            return false;
        }
    }
    catch (const exception& e) {
        string errorMessage = "Произошла ошибка: ";
        string exitMessage = "Программа завершена.";
        cout << errorMessage << e.what() << "\n" << exitMessage << endl;
        return false;
    }
    catch (...) {
        string unknownErrorMessage = "Неизвестная ошибка. Программа завершена.";
        cout << unknownErrorMessage << endl;
        return false;
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

        // СОЗДАЕМ КОЛЛЕКЦИЮ БАЗОВОГО ТИПА
        vector<shared_ptr<Furniture>> furnitureCollection;
        for (const auto& item : furnitureList) {
            furnitureCollection.push_back(item);
        }

        // ПРОИТЕРИРУЕМ КАК КОЛЛЕКЦИЮ БАЗОВОГО КЛАССА
        for (size_t i = 0; i < furnitureCollection.size(); ++i) {
            cout << i + 1 << ". " << furnitureCollection[i]->getInfo() << "\n";
        }
    }
}

void demonstrateSoldFurnitureCount(FurnitureStore& store) {
    string countTitle = " КОЛИЧЕСТВО ПРОДАННОЙ МЕБЕЛИ ЗА ПЕРИОД ";
    string furnitureNamePrompt = "Введите название мебели: ";
    string startDateMessage = "Введите начальную дату:";
    string endDateMessage = "Введите конечную дату:";
    string dayPrompt = "День: ";
    string monthPrompt = "Месяц: ";
    string yearPrompt = "Год: ";
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
    string monthPrompt = "Месяц: ";
    string yearPrompt = "Год: ";

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

void demonstrateDatabaseStatistics(FurnitureStore& store) {
    string statsTitle = " СТАТИСТИКА МАГАЗИНА ";
    cout << "\n" << statsTitle << "\n";
    cout << store.getStatistics() << "\n";
}

void addNewFurniture(FurnitureStore& store) {
    string addTitle = " ДОБАВЛЕНИЕ НОВОЙ МЕБЕЛИ ";
    cout << "\n" << addTitle << "\n";

    string namePrompt = "Название мебели: ";
    string typePrompt = "Тип мебели (Шкаф/Стол/Стул): ";
    string pricePrompt = "Цена: ";
    string quantityPrompt = "Количество: ";

    string name = getInput(namePrompt);
    string type = getInput(typePrompt);

    cout << pricePrompt;
    double price;
    cin >> price;

    cout << quantityPrompt;
    int quantity;
    cin >> quantity;
    cin.ignore();

    tm productionDate = {};
    std::time_t t = std::time(nullptr);
    localtime_s(&productionDate, &t);  // ИСПРАВЛЕНО: localtime_s вместо localtime

    shared_ptr<Furniture> furniture;

    if (type == "Шкаф") {
        string shelvesPrompt = "Количество полок: ";
        string materialPrompt = "Материал: ";

        cout << shelvesPrompt;
        int shelves;
        cin >> shelves;
        cin.ignore();

        string material = getInput(materialPrompt);

        furniture = make_shared<Cabinet>(name, price, quantity,
            productionDate, shelves, material);
    }
    else if (type == "Стол") {
        string lengthPrompt = "Длина (м): ";
        string widthPrompt = "Ширина (м): ";
        string shapePrompt = "Форма: ";

        cout << lengthPrompt;
        double length;
        cin >> length;

        cout << widthPrompt;
        double width;
        cin >> width;
        cin.ignore();

        string shape = getInput(shapePrompt);

        furniture = make_shared<Table>(name, price, quantity,
            productionDate, length, width, shape);
    }
    else if (type == "Стул") {
        string backrestPrompt = "Есть спинка? (1-да, 0-нет): ";
        string upholsteryPrompt = "Обивка: ";

        cout << backrestPrompt;
        bool hasBackrest;
        cin >> hasBackrest;
        cin.ignore();

        string upholstery = getInput(upholsteryPrompt);

        furniture = make_shared<Chair>(name, price, quantity,
            productionDate, hasBackrest, upholstery);
    }
    else {
        furniture = make_shared<Furniture>(name, type, price,
            quantity, productionDate);
    }

    store.addFurniture(furniture);
    cout << "Мебель успешно добавлена!\n";
}

void addNewOrder(FurnitureStore& store) {
    string orderTitle = " СОЗДАНИЕ НОВОГО ЗАКАЗА ";
    cout << "\n" << orderTitle << "\n";

    string customerPrompt = "Имя заказчика: ";
    string customerName = getInput(customerPrompt);

    auto order = store.createOrder(customerName);

    while (true) {
        string itemPrompt = "Введите название мебели (или 'готово' для завершения): ";
        string itemName = getInput(itemPrompt);

        if (itemName == "готово") {
            break;
        }

        auto furniture = store.findFurnitureByName(itemName);
        if (furniture) {
            if (furniture->getQuantity() > 0) {
                furniture->sell();
                order->addItem(furniture);
                cout << "Добавлено: " << furniture->getName() << "\n";
            }
            else {
                cout << "Нет в наличии!\n";
            }
        }
        else {
            cout << "Мебель не найдена!\n";
        }
    }

    if (!order->getItems().empty()) {
        store.addOrder(order);
        cout << "Заказ #" << order->getOrderId() << " успешно создан!\n";
        cout << "Общая стоимость: " << order->getTotalPrice() << " руб.\n";
    }
    else {
        cout << "Заказ не создан (нет товаров).\n";
    }
}

void addNewCustomOrder(FurnitureStore& store) {
    string customTitle = " СОЗДАНИЕ ИНДИВИДУАЛЬНОГО ЗАКАЗА ";
    cout << "\n" << customTitle << "\n";

    string customerPrompt = "Имя заказчика: ";
    string markupPrompt = "Процент наценки за индивидуальность: ";
    string requirementsPrompt = "Особые требования: ";

    string customerName = getInput(customerPrompt);

    cout << markupPrompt;
    double markup;
    cin >> markup;
    cin.ignore();

    string requirements = getInput(requirementsPrompt);

    auto order = store.createCustomOrder(customerName, markup, requirements);

    while (true) {
        string itemPrompt = "Введите название мебели (или 'готово' для завершения): ";
        string itemName = getInput(itemPrompt);

        if (itemName == "готово") {
            break;
        }

        auto furniture = store.findFurnitureByName(itemName);
        if (furniture) {
            if (furniture->getQuantity() > 0) {
                furniture->sell();
                order->addItem(furniture);
                cout << "Добавлено: " << furniture->getName() << " (с наценкой)\n";
            }
            else {
                cout << "Нет в наличии!\n";
            }
        }
        else {
            cout << "Мебель не найдена!\n";
        }
    }

    if (!order->getItems().empty()) {
        store.addOrder(order);
        cout << "Индивидуальный заказ #" << order->getOrderId() << " успешно создан!\n";
        cout << "Общая стоимость (с наценкой): " << order->getTotalPrice() << " руб.\n";
    }
    else {
        cout << "Заказ не создан (нет товаров).\n";
    }
}

void createTestData(FurnitureStore& store) {
    // Создаем тестовую мебель
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

    auto customOrder1 = make_shared<CustomOrder>(2, orderDate2, "Петрова А.С.",
        15.0, "Черный матовый цвет");
    customOrder1->addItem(table2);
    customOrder1->addItem(chair2);
    store.addOrder(customOrder1);
}