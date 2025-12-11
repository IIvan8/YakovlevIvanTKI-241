#include "Order.h"
#include "Furniture.h"
#include <sstream>
#include <iomanip>

Order::Order(int orderId, const std::tm& orderDate, const std::string& customerName)
    : orderId(orderId), orderDate(orderDate), customerName(customerName),
    totalPrice(0.0) {}

int Order::getOrderId() const { return orderId; }
std::tm Order::getOrderDate() const { return orderDate; }
std::string Order::getCustomerName() const { return customerName; }
double Order::getTotalPrice() const { return totalPrice; }

void Order::addItem(std::shared_ptr<Furniture> item) {
    items.push_back(item);
    calculateTotalPrice();
}

std::vector<std::shared_ptr<Furniture>> Order::getItems() const {
    return items;
}

void Order::calculateTotalPrice() {
    totalPrice = 0.0;
    for (const auto& item : items) {
        totalPrice += item->getPrice();
    }
}

std::string Order::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << "Заказ #" << orderId
        << " от " << std::put_time(&orderDate, "%d.%m.%Y")
        << ", Клиент: " << customerName
        << ", Стоимость: " << totalPrice << " руб."
        << ", Количество предметов: " << items.size();
    return ss.str();
}