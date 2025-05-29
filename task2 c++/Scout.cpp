#include "Scout.h"

Scout::Scout(int energyConsumption, double foodIncreasePercent)
    : Droid(energyConsumption), foodIncreasePercent(foodIncreasePercent) {
}

double Scout::getFoodIncreasePercent() const {
    return foodIncreasePercent;
}

// ��������� ����������� ����� ����, �������, ��� "����" � ��� �������,
// ������� ���������� ������� �� ���������� �������� ��������.
// ��� ������� ������ 10 ������ ������� �������, �������� �� �������.

int Scout::getEnergyProduction() const {
    const int baseEnergyProduction = 10; // ������� ������, ����� ���������
    return static_cast<int>(baseEnergyProduction * (foodIncreasePercent / 100.0));
}
