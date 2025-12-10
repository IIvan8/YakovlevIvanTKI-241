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

void FurnitureStore::addOrder(std::shared_ptr<Order> order) {
    orders.push_back(order);
}