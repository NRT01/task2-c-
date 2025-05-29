#include "Random.h"
#include <chrono>

Random::Random() {
    gen.seed(static_cast<unsigned int>(
        std::chrono::steady_clock::now().time_since_epoch().count()));
}

int Random::getInt(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

double Random::getDouble(double min, double max) {
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}
