#include "Worker.h"

Worker::Worker(int energyConsumption, int energyProduced)
    : Droid(energyConsumption), energyProduced(energyProduced) {
}

int Worker::getEnergyProduction() const {
    return energyProduced;
}
