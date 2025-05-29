#pragma once

class Droid {
protected:
    int energyConsumption;  // ���������� ������������ �������

public:
    explicit Droid(int energyConsumption);
    virtual ~Droid() = default;

    // ���������� ���������� �������, ������� ���������� ������ �����
    virtual int getEnergyConsumption() const;

    // ���������� ���������� �������, ������� �������� ������ ����� (�� ��������� 0)
    virtual int getEnergyProduction() const;

    // ����� �������� ����� ��� ���������� ��������� ������ (��������, ��� ��������)
    virtual void update() {}
};
