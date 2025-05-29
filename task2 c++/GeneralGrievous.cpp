#include "GeneralGrievous.h"
#include "Stormtrooper.h"
#include "Scout.h"
#include "Worker.h"
#include "BasicDroid.h"

#include <cstdlib>  // для rand()
#include <ctime>

GeneralGrievous::GeneralGrievous(int energyConsumption)
    : Droid(energyConsumption), scoutsCreated(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // инициализация рандома
}

int GeneralGrievous::getScoutsCreated() const {
    return scoutsCreated;
}

void GeneralGrievous::incrementScoutsCreated() {
    scoutsCreated++;
}

std::unique_ptr<Droid> GeneralGrievous::createRandomDroid() {
    int choice = std::rand() % 4; // 0..3

    switch (choice) {
    case 0: // Штурмовик
        return std::make_unique<Stormtrooper>(30, 5); // пример параметров
    case 1: // Разведчик
        incrementScoutsCreated();
        return std::make_unique<Scout>(15, 10.0); // например, 10% увеличения пищи
    case 2: // Рабочий
        return std::make_unique<Worker>(10, 20); // пример: потребляет 10, добывает 20 энергии
    default: // Базовый дроид
        return std::make_unique<BasicDroid>(5); // потребляет 5 энергии
    }
}

void GeneralGrievous::update() {
    // Здесь можно реализовать логику генерации дроидов, если нужно
    // Например, рандомно создать нового дроида, добавить его в базу (если передадим указатель на базу)
}
