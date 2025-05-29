#pragma once

class Rebel {
private:
    int attackRadius;  // радиус действия оружия
    int damage;        // степень урона

public:
    Rebel();

    int getAttackRadius() const;
    int getDamage() const;
};
