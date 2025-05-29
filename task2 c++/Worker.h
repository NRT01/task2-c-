#pragma once
#include "Droid.h"

class Worker : public Droid {
private:
    int energyProduced;  // ���������� ���������� �������

public:
    Worker(int energyConsumption, int energyProduced);

    // �������������� ����� ������ �������
    int getEnergyProduction() const override;
};
