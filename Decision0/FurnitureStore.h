#pragma once
#include <vector>
#include <memory>
#include <string>
#include <ctime>
#include "Furniture.h"
#include "Order.h"

/**
 *@brief Основной класс мебельного магазина
 */
    class FurnitureStore {
    private:
        /**
        *@brief Ассортимент мебели в магазине
        */
        std::vector<std::shared_ptr<Furniture>> furniture;

        /**
        *@brief Список всех заказов
        */
        std::vector<std::shared_ptr<Order>> orders;

        /**
        *@brief Следующий доступный ID для заказа
        */
        int nextOrderId;

    public:
        FurnitureStore();

        void addFurniture(std::shared_ptr<Furniture> furnitureItem);
        std::vector<std::shared_ptr<Furniture>> showAssortment() const;

        int getSoldFurnitureCount(const std::string& furnitureName,
            const std::tm& start, const std::tm& end) const;

        std::vector<std::shared_ptr<Order>> getOrdersInPeriod(const std::tm& start,
            const std::tm& end) const;

        double calculateCustomOrderPrice(double basePrice, double markupPercentage) const;

        void addOrder(std::shared_ptr<Order> order);
};