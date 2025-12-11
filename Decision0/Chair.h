#pragma once
#include "Furniture.h"
#include <string>

/**
 *@brief Класс представляющий стул
 */
class Chair : public Furniture {
private:
    /** 
    *@brief Наличие спинки у стула 
    */
    bool hasBackrest;

    /** 
    *@brief Материал обивки стула 
    */
    std::string upholstery;

public:
    Chair(const std::string& name, double price, int quantity,
        const std::tm& productionDate, bool hasBackrest,
        const std::string& upholstery);

    bool getHasBackrest() const;
    std::string getUpholstery() const;

    std::string getInfo() const override;
};