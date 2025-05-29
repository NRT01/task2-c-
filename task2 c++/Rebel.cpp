#include "Rebel.h"
#include <random>

Rebel::Rebel() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> radiusDist(1, 10);  // ��������, ������ 1�10
    std::uniform_int_distribution<> damageDist(5, 20);  // ���� 5�20

    attackRadius = radiusDist(gen);
    damage = damageDist(gen);
}

int Rebel::getAttackRadius() const {
    return attackRadius;
}

int Rebel::getDamage() const {
    return damage;
}
