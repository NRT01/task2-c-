#pragma once

class Rebel {
private:
    int attackRadius;  // ������ �������� ������
    int damage;        // ������� �����

public:
    Rebel();

    int getAttackRadius() const;
    int getDamage() const;
};
