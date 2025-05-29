#include "Base.h"
#include <iostream>

Base::Base(int initialEnergy, const GeneralGrievous& general)
    : energy(initialEnergy), general(general) {
    // Добавляем генерала в список дроидов
    droids.push_back(std::make_unique<GeneralGrievous>(general));
}

void Base::addDroid(std::unique_ptr<Droid> droid) {
    droids.push_back(std::move(droid));
}

void Base::addRebel(const Rebel& rebel) {
    rebels.push_back(rebel);
}

void Base::simulateStep() {
    int totalEnergyConsumed = 0;
    int totalEnergyProduced = 0;

    // Считаем суммарное потребление и добычу энергии дроидами
    for (auto& droid : droids) {
        totalEnergyConsumed += droid->getEnergyConsumption();
        totalEnergyProduced += droid->getEnergyProduction();
    }

    // Учтём влияние повстанцев — например, отнимем от энергии урон повстанцев
    int totalDamage = 0;
    for (const auto& rebel : rebels) {
        totalDamage += rebel.getDamage();
    }

    // Обновляем запас энергии
    energy += totalEnergyProduced - totalEnergyConsumed - totalDamage;

    if (energy < 0) {
        energy = 0;
    }

    // Можно добавить логику генерала для создания новых дроидов (если есть энергия)
    GeneralGrievous* genPtr = nullptr;
    for (auto& droid : droids) {
        genPtr = dynamic_cast<GeneralGrievous*>(droid.get());
        if (genPtr) break;
    }

    if (genPtr && energy > genPtr->getEnergyConsumption()) {
        auto newDroid = genPtr->createRandomDroid();
        int cost = newDroid->getEnergyConsumption();
        if (energy >= cost) {
            energy -= cost;
            droids.push_back(std::move(newDroid));
        }
    }
}

bool Base::isCaptured() const {
    return energy <= 0;
}

int Base::getEnergy() const {
    return energy;
}

void Base::printStatus() const {
    std::cout << "Base energy: " << energy << std::endl;
    std::cout << "Droids count: " << droids.size() << std::endl;
    std::cout << "Rebels count: " << rebels.size() << std::endl;

    // Выводим количество созданных разведчиков
    const GeneralGrievous* genPtr = nullptr;
    for (const auto& droid : droids) {
        genPtr = dynamic_cast<const GeneralGrievous*>(droid.get());
        if (genPtr) break;
    }
    if (genPtr) {
        std::cout << "Scouts created: " << genPtr->getScoutsCreated() << std::endl;
    }
}
