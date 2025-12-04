#pragma once
#include <string>
#include <memory>
#include <vector>
#include <ctime>

/**
 *@brief Базовый класс представляющий мебель
 */
class Furniture {
protected:
    /** 
    *@brief Название мебели
    */
    std::string name;   

    /** 
    *@brief Тип мебели
    */ 
    std::string type;   
    
    /**
    *@brief Цена мебели
    */
    double price;  
    
    /**
    *@brief Количество на складе
    */
    int quantity;              

    /**
    *@brief Дата производства
    */
    std::tm productionDate;         

public:
    /**
     *@brief Конструктор мебели
     */
    Furniture(const std::string& name, const std::string& type,
        double price, int quantity, const std::tm& productionDate);

    virtual ~Furniture() = default;

    std::string getName() const;
    std::string getType() const;
    double getPrice() const;
    int getQuantity() const;
    std::tm getProductionDate() const;

    void setPrice(double price);
    void setQuantity(int quantity);
    bool sell();
    void addToStock(int amount);

    virtual std::string getInfo() const;
};