#pragma once
#include "Furniture.h"

/**
 *@brief Класс представляющий стол
 */
class Table : public Furniture {
private:
    /** 
    *@brief Длина стола 
    */
    double length;

    /** 
    *@brief Ширина стола 
    */
    double width;

    /** 
    *@brief Форма стола (прямоугольный, круглый и т.д.) 
    */
    std::string shape;

public:
    Table(const std::string& name, double price, int quantity,
        const std::tm& productionDate, double length,
        double width, const std::string& shape);

    double getLength() const;
    double getWidth() const;
    std::string getShape() const;

    std::string getInfo() const override;
};