#include "Scout.h"

Scout::Scout(int energyConsumption, double foodIncreasePercent)
    : Droid(energyConsumption), foodIncreasePercent(foodIncreasePercent) {
}

double Scout::getFoodIncreasePercent() const {
    return foodIncreasePercent;
}

// Разведчик увеличивает запас пищи, считаем, что "пища" — это энергия,
// поэтому возвращаем процент от некоторого базового значения.
// Для примера возьмём 10 единиц базовой энергии, умножаем на процент.

int Scout::getEnergyProduction() const {
    const int baseEnergyProduction = 10; // базовая добыча, можно настроить
    return static_cast<int>(baseEnergyProduction * (foodIncreasePercent / 100.0));
}
