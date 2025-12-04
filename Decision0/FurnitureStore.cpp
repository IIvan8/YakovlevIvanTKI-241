#include "FurnitureStore.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>

FurnitureStore::FurnitureStore() : nextOrderId(1) {}

void FurnitureStore::addFurniture(std::shared_ptr<Furniture> furnitureItem) {
    furniture.push_back(furnitureItem);
}

std::vector<std::shared_ptr<Furniture>> FurnitureStore::showAssortment() const {
    return furniture;
}

int FurnitureStore::getSoldFurnitureCount(const std::string& furnitureName,
    const std::tm& start,
    const std::tm& end) const {
    int count = 0;

    for (const auto& order : orders) {
        std::tm orderDate = order->getOrderDate();

        if (std::difftime(std::mktime(const_cast<std::tm*>(&orderDate)),
            std::mktime(const_cast<std::tm*>(&start))) >= 0 &&
            std::difftime(std::mktime(const_cast<std::tm*>(&orderDate)),
                std::mktime(const_cast<std::tm*>(&end))) <= 0) {

            for (const auto& item : order->getItems()) {
                if (item->getName() == furnitureName) {
                    count++;
                }
            }
        }
    }

    return count;
}

std::vector<std::shared_ptr<Order>> FurnitureStore::getOrdersInPeriod(
    const std::tm& start, const std::tm& end) const {

    std::vector<std::shared_ptr<Order>> result;

    for (const auto& order : orders) {
        std::tm orderDate = order->getOrderDate();

        if (std::difftime(std::mktime(const_cast<std::tm*>(&orderDate)),
            std::mktime(const_cast<std::tm*>(&start))) >= 0 &&
            std::difftime(std::mktime(const_cast<std::tm*>(&orderDate)),
                std::mktime(const_cast<std::tm*>(&end))) <= 0) {
            result.push_back(order);
        }
    }

    return result;
}

double FurnitureStore::calculateCustomOrderPrice(double basePrice,
    double markupPercentage) const {
    return basePrice * (1 + markupPercentage / 100.0);
}

std::shared_ptr<Furniture> FurnitureStore::findFurnitureByName(
    const std::string& name) const {

    for (const auto& item : furniture) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

void FurnitureStore::addOrder(std::shared_ptr<Order> order) {
    orders.push_back(order);
}

std::shared_ptr<Order> FurnitureStore::createOrder(const std::string& customerName) {
    std::time_t t = std::time(nullptr);
    std::tm orderDate;
    localtime_s(&orderDate, &t);  // ИСПРАВЛЕНО: заменено localtime(&t)

    auto order = std::make_shared<Order>(nextOrderId++, orderDate, customerName);
    return order;
}

std::shared_ptr<CustomOrder> FurnitureStore::createCustomOrder(
    const std::string& customerName, double markupPercentage,
    const std::string& specialRequirements) {

    std::time_t t = std::time(nullptr);
    std::tm orderDate;
    localtime_s(&orderDate, &t);  // ИСПРАВЛЕНО: заменено localtime(&t)

    auto order = std::make_shared<CustomOrder>(
        nextOrderId++, orderDate, customerName,
        markupPercentage, specialRequirements
    );

    return order;
}

std::string FurnitureStore::getStatistics() const {
    std::stringstream ss;

    int cabinets = 0, tables = 0, chairs = 0;
    for (const auto& item : furniture) {
        std::string type = item->getType();
        if (type == "Шкаф") cabinets++;
        else if (type == "Стол") tables++;
        else if (type == "Стул") chairs++;
    }

    double totalInventoryValue = 0;
    for (const auto& item : furniture) {
        totalInventoryValue += item->getPrice() * item->getQuantity();
    }

    double totalRevenue = 0;
    int customOrders = 0;
    for (const auto& order : orders) {
        totalRevenue += order->getTotalPrice();
        if (dynamic_cast<CustomOrder*>(order.get())) {
            customOrders++;
        }
    }

    ss << std::fixed << std::setprecision(2);
    ss << "СТАТИСТИКА МАГАЗИНА:\n"
        << "Ассортимент: " << furniture.size() << " позиций\n"
        << "Шкафы: " << cabinets << " шт.\n"
        << "Столы: " << tables << " шт.\n"
        << "Стулья: " << chairs << " шт.\n"
        << "Заказов всего: " << orders.size() << "\n"
        << "Индивидуальных заказов: " << customOrders << "\n"
        << "Товаров на складе: " << totalInventoryValue << " руб.\n"
        << "Общая выручка: " << totalRevenue << " руб.";

    return ss.str();
}

std::vector<std::shared_ptr<Order>> FurnitureStore::getAllOrders() const {
    return orders;
}