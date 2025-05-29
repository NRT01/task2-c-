#include "Stormtrooper.h"

Stormtrooper::Stormtrooper(int energyConsumption, int separatistsKilled)
    : Droid(energyConsumption), separatistsKilled(separatistsKilled) {
}

int Stormtrooper::getSeparatistsKilled() const {
    return separatistsKilled;
}
