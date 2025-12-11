#pragma once
#include <string>
#include <memory>
#include <vector>
#include <ctime>

class Furniture;

/**
 *@brief Класс представляющий заказ в магазине
 */
class Order {
protected:
    /**
    *@brief Уникальный идентификатор заказа
    */
    int orderId;

    /**
    *@brief Дата оформления заказа
    */
    std::tm orderDate;

    /**
    *@brief Имя заказчика
    */
    std::string customerName;

    /**
    *@brief Список мебели в заказе
    */
    std::vector<std::shared_ptr<Furniture>> items;

    /**
    *@brief Общая стоимость заказа
    */
    double totalPrice;

public:
    Order(int orderId, const std::tm& orderDate, const std::string& customerName);
    virtual ~Order() = default;

    int getOrderId() const;
    std::tm getOrderDate() const;
    std::string getCustomerName() const;
    double getTotalPrice() const;

    virtual void addItem(std::shared_ptr<Furniture> item);
    std::vector<std::shared_ptr<Furniture>> getItems() const;
    virtual void calculateTotalPrice();

    virtual std::string getInfo() const;
};