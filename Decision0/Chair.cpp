#include "Chair.h"
#include <sstream>
#include <string>

Chair::Chair(const std::string& name, double price, int quantity,
    const std::tm& productionDate, bool hasBackrest,
    const std::string& upholstery)
    : Furniture(name, "Стул", price, quantity, productionDate),
    hasBackrest(hasBackrest), upholstery(upholstery) {
}

bool Chair::getHasBackrest() const {
    return hasBackrest;
}

std::string Chair::getUpholstery() const {
    return upholstery;
}

std::string Chair::getInfo() const {
    std::stringstream ss;
    ss << Furniture::getInfo() << ", Спинка: "
        << (hasBackrest ? "есть" : "нет") << ", Обивка: " << upholstery;
    return ss.str();
}