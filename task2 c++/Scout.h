#pragma once
#include "Droid.h"

class Scout : public Droid {
private:
    double foodIncreasePercent; // ������� ���������� ������ ���� (�������)

public:
    Scout(int energyConsumption, double foodIncreasePercent);

    double getFoodIncreasePercent() const;  

    // ������������� ������ ������� � ������ �������� ����������
    int getEnergyProduction() const override;
};
