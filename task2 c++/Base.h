#pragma once

#include <vector>
#include <memory>
#include "Droid.h"
#include "GeneralGrievous.h"
#include "Rebel.h"

class Base {
private:
    int energy;  // ������� ����� �������

    std::vector<std::unique_ptr<Droid>> droids;
    std::vector<Rebel> rebels;

    GeneralGrievous general;

public:
    Base(int initialEnergy, const GeneralGrievous& general);

    void addDroid(std::unique_ptr<Droid> droid);
    void addRebel(const Rebel& rebel);

    // ��������� ������ ���� (������� ����������)
    void simulateStep();

    bool isCaptured() const;

    int getEnergy() const;

    // ����� ��������� ���� (��� �������)
    void printStatus() const;
};
