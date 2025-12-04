#pragma once
#include "Furniture.h"

/**
 *@brief Класс представляющий шкаф
 */
class Cabinet : public Furniture {
private:
    /** 
    *@brief Количество полок в шкафу 
    */
    int shelvesCount;

    /** 
    *@brief Материал изготовления шкафа 
    */
    std::string material;

public:
    Cabinet(const std::string& name, double price, int quantity,
        const std::tm& productionDate, int shelvesCount,
        const std::string& material);

    int getShelvesCount() const;
    std::string getMaterial() const;

    std::string getInfo() const override;
};