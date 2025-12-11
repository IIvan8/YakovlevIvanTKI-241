#include "Cabinet.h"
#include <sstream>

Cabinet::Cabinet(const std::string& name, double price, int quantity,
    const std::tm& productionDate, int shelvesCount,
    const std::string& material)
    : Furniture(name, "Шкаф", price, quantity, productionDate),
    shelvesCount(shelvesCount), material(material) {}

int Cabinet::getShelvesCount() const { return shelvesCount; }
std::string Cabinet::getMaterial() const { return material; }

std::string Cabinet::getInfo() const {
    std::stringstream ss;
    ss << Furniture::getInfo() << ", Полок: " << shelvesCount
        << ", Материал: " << material;
    return ss.str();
}