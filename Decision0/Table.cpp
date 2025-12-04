#include "Table.h"
#include <sstream>
#include <iomanip>

Table::Table(const std::string& name, double price, int quantity,
    const std::tm& productionDate, double length,
    double width, const std::string& shape)
    : Furniture(name, "Стол", price, quantity, productionDate),
    length(length), width(width), shape(shape) {}

double Table::getLength() const { return length; }
double Table::getWidth() const { return width; }
std::string Table::getShape() const { return shape; }

std::string Table::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1);
    ss << Furniture::getInfo() << ", Размер: " << length
        << "x" << width << " м, Форма: " << shape;
    return ss.str();
}