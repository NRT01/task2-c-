#include "GeneralGrievous.h"
#include "Stormtrooper.h"
#include "Scout.h"
#include "Worker.h"
#include "BasicDroid.h"

#include <cstdlib>  // ��� rand()
#include <ctime>

GeneralGrievous::GeneralGrievous(int energyConsumption)
    : Droid(energyConsumption), scoutsCreated(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // ������������� �������
}

int GeneralGrievous::getScoutsCreated() const {
    return scoutsCreated;
}

void GeneralGrievous::incrementScoutsCreated() {
    scoutsCreated++;
}

std::unique_ptr<Droid> GeneralGrievous::createRandomDroid() {
    int choice = std::rand() % 4; // 0..3

    switch (choice) {
    case 0: // ���������
        return std::make_unique<Stormtrooper>(30, 5); // ������ ����������
    case 1: // ���������
        incrementScoutsCreated();
        return std::make_unique<Scout>(15, 10.0); // ��������, 10% ���������� ����
    case 2: // �������
        return std::make_unique<Worker>(10, 20); // ������: ���������� 10, �������� 20 �������
    default: // ������� �����
        return std::make_unique<BasicDroid>(5); // ���������� 5 �������
    }
}

void GeneralGrievous::update() {
    // ����� ����� ����������� ������ ��������� �������, ���� �����
    // ��������, �������� ������� ������ ������, �������� ��� � ���� (���� ��������� ��������� �� ����)
}
