#include "Base.h"
#include <iostream>

Base::Base(int initialEnergy, const GeneralGrievous& general)
    : energy(initialEnergy), general(general) {
    // ��������� �������� � ������ �������
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

    // ������� ��������� ����������� � ������ ������� ��������
    for (auto& droid : droids) {
        totalEnergyConsumed += droid->getEnergyConsumption();
        totalEnergyProduced += droid->getEnergyProduction();
    }

    // ���� ������� ���������� � ��������, ������� �� ������� ���� ����������
    int totalDamage = 0;
    for (const auto& rebel : rebels) {
        totalDamage += rebel.getDamage();
    }

    // ��������� ����� �������
    energy += totalEnergyProduced - totalEnergyConsumed - totalDamage;

    if (energy < 0) {
        energy = 0;
    }

    // ����� �������� ������ �������� ��� �������� ����� ������� (���� ���� �������)
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

    // ������� ���������� ��������� �����������
    const GeneralGrievous* genPtr = nullptr;
    for (const auto& droid : droids) {
        genPtr = dynamic_cast<const GeneralGrievous*>(droid.get());
        if (genPtr) break;
    }
    if (genPtr) {
        std::cout << "Scouts created: " << genPtr->getScoutsCreated() << std::endl;
    }
}
