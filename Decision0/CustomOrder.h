#pragma once
#include "Order.h"

/**
 *@brief Класс представляющий индивидуальный заказ
 */
class CustomOrder : public Order {
private:
    /** 
    *@brief Процент наценки за индивидуальный заказ 
    */
    double markupPercentage;

    /** 
    *@brief Особые требования к заказу 
    */
    std::string specialRequirements;

public:
    CustomOrder(int orderId, const std::tm& orderDate,
        const std::string& customerName,
        double markupPercentage,
        const std::string& specialRequirements);

    double getMarkupPercentage() const;
    std::string getSpecialRequirements() const;

    void addItem(std::shared_ptr<Furniture> item) override;
    void calculateTotalPrice() override;
    double applyMarkup(double basePrice) const;

    std::string getInfo() const override;
};