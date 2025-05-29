#pragma once
#include "Droid.h"

class Stormtrooper : public Droid {
private:
    int separatistsKilled;

public:
    Stormtrooper(int energyConsumption, int separatistsKilled);

    int getSeparatistsKilled() const;
};
