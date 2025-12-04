#include "CustomOrder.h"
#include "Furniture.h"
#include <sstream>
#include <iomanip>

CustomOrder::CustomOrder(int orderId, const std::tm& orderDate,
    const std::string& customerName,
    double markupPercentage,
    const std::string& specialRequirements)
    : Order(orderId, orderDate, customerName),
    markupPercentage(markupPercentage),
    specialRequirements(specialRequirements) {}

double CustomOrder::getMarkupPercentage() const {
    return markupPercentage;
}

std::string CustomOrder::getSpecialRequirements() const {
    return specialRequirements;
}

void CustomOrder::addItem(std::shared_ptr<Furniture> item) {
    // Создаем копию с наценкой
    auto customItem = std::make_shared<Furniture>(
        item->getName(),
        item->getType(),
        applyMarkup(item->getPrice()),
        item->getQuantity(),
        item->getProductionDate()
    );

    Order::addItem(customItem);
}

void CustomOrder::calculateTotalPrice() {
    totalPrice = 0.0;
    for (const auto& item : items) {
        totalPrice += item->getPrice();
    }
}

double CustomOrder::applyMarkup(double basePrice) const {
    return basePrice * (1 + markupPercentage / 100.0);
}

std::string CustomOrder::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << "ИНДИВИДУАЛЬНЫЙ ЗАКАЗ #" << orderId
        << " от " << std::put_time(&orderDate, "%d.%m.%Y")
        << "\nЗаказчик: " << customerName
        << "\nНаценка: " << markupPercentage << "%"
        << "\nТребования: " << specialRequirements
        << "\nСтоимость: " << totalPrice << " руб."
        << "\nПредметов: " << items.size();

    if (!items.empty()) {
        ss << "\nСостав:";
        for (size_t i = 0; i < items.size(); ++i) {
            ss << "\n  " << i + 1 << ". " << items[i]->getInfo();
        }
    }

    return ss.str();
}
