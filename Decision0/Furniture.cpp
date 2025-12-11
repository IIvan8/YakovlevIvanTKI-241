#include "Furniture.h"
#include <sstream>
#include <iomanip>

Furniture::Furniture(const std::string& name, const std::string& type,
    double price, int quantity, const std::tm& productionDate)
    : name(name), type(type), price(price), quantity(quantity),
    productionDate(productionDate) {}

std::string Furniture::getName() const { return name; }
std::string Furniture::getType() const { return type; }
double Furniture::getPrice() const { return price; }
int Furniture::getQuantity() const { return quantity; }
std::tm Furniture::getProductionDate() const { return productionDate; }

void Furniture::setPrice(double price) { this->price = price; }
void Furniture::setQuantity(int quantity) { this->quantity = quantity; }

bool Furniture::sell() {
    if (quantity > 0) {
        quantity--;
        return true;
    }
    return false;
}

void Furniture::addToStock(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}

std::string Furniture::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << name << " (" << type << "), Цена: " << price
        << " руб., В наличии: " << quantity << " шт.";
    return ss.str();
}