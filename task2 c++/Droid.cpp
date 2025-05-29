#include "Droid.h"

Droid::Droid(int energyConsumption) : energyConsumption(energyConsumption) {}

int Droid::getEnergyConsumption() const {
    return energyConsumption;
}

int Droid::getEnergyProduction() const {
    return 0; // базовый дроид не добывает энергию
}
