#pragma once
#include "Droid.h"

class Worker : public Droid {
private:
    int energyProduced;  // количество добываемой энергии

public:
    Worker(int energyConsumption, int energyProduced);

    // Переопределяем метод добычи энергии
    int getEnergyProduction() const override;
};
