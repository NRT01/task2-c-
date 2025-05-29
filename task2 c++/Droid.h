#pragma once

class Droid {
protected:
    int energyConsumption;  // количество потребл€емой энергии

public:
    explicit Droid(int energyConsumption);
    virtual ~Droid() = default;

    // ¬озвращает количество энергии, которое потребл€ет данный дроид
    virtual int getEnergyConsumption() const;

    // ¬озвращает количество энергии, которое добывает данный дроид (по умолчанию 0)
    virtual int getEnergyProduction() const;

    // ћожно добавить метод дл€ обновлени€ состо€ни€ дроида (например, при апгрейде)
    virtual void update() {}
};
