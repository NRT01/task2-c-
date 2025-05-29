#pragma once
#include "Droid.h"

class Scout : public Droid {
private:
    double foodIncreasePercent; // процент увеличения запаса пищи (энергии)

public:
    Scout(int energyConsumption, double foodIncreasePercent);

    double getFoodIncreasePercent() const;  

    // Переопределим добычу энергии с учётом процента увеличения
    int getEnergyProduction() const override;
};
