#pragma once
#include "Droid.h"
#include <memory>

class GeneralGrievous : public Droid {
private:
    int scoutsCreated;

public:
    explicit GeneralGrievous(int energyConsumption);

    int getScoutsCreated() const;
    void incrementScoutsCreated();

    // ������ ������ ������, ������� ��� �������� (���������, ���������, ������� ��� �������)
    // ���������� ����� ��������� �� ������ ������
    std::unique_ptr<Droid> createRandomDroid();

    void update() override;
};
