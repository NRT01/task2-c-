#pragma once
#include "Droid.h"
#include <memory>

class GeneralGrievous : public Droid {
private:
    int scoutsCreated;

public:
    explicit GeneralGrievous(int energyConsumption);

    int getScoutsCreated() const;
    void incrementScoutsCreated();

    // Создаёт нового дроида, выбирая тип случайно (штурмовик, разведчик, рабочий или базовый)
    // Возвращает умный указатель на нового дроида
    std::unique_ptr<Droid> createRandomDroid();

    void update() override;
};
