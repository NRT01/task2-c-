#pragma once
#include <random>

class Random {
private:
    std::mt19937 gen;

public:
    Random();

    int getInt(int min, int max);
    double getDouble(double min, double max);
};
