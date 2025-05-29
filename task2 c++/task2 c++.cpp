#include <cassert>
#include <iostream>
#include <memory>
#include "Droid.h"
#include "GeneralGrievous.h"
#include "Stormtrooper.h"
#include "Scout.h"
#include "Worker.h"
#include "BasicDroid.h"
#include "Rebel.h"
#include "Base.h"
#include "Random.h"

void testDroid() {
    Droid d(10);
    assert(d.getEnergyConsumption() == 10);
    assert(d.getEnergyProduction() == 0);
    std::cout << "Droid test passed.\n";
}

void testGeneralGrievous() {
    GeneralGrievous gen(50);
    assert(gen.getEnergyConsumption() == 50);
    assert(gen.getScoutsCreated() == 0);

    auto newDroid = gen.createRandomDroid();
    assert(newDroid != nullptr);

    std::cout << "GeneralGrievous test passed.\n";
}

void testStormtrooper() {
    Stormtrooper st(30, 7);
    assert(st.getEnergyConsumption() == 30);
    assert(st.getSeparatistsKilled() == 7);
    std::cout << "Stormtrooper test passed.\n";
}

void testScout() {
    Scout sc(15, 10.0);
    assert(sc.getEnergyConsumption() == 15);
    assert(sc.getFoodIncreasePercent() == 10.0);

    int energyProduced = sc.getEnergyProduction();
    assert(energyProduced >= 0);
    std::cout << "Scout test passed.\n";
}

void testWorker() {
    Worker w(8, 25);
    assert(w.getEnergyConsumption() == 8);
    assert(w.getEnergyProduction() == 25);
    std::cout << "Worker test passed.\n";
}

void testBasicDroid() {
    BasicDroid b(5);
    assert(b.getEnergyConsumption() == 5);
    assert(b.getEnergyProduction() == 0);
    std::cout << "BasicDroid test passed.\n";
}

void testRebel() {
    Rebel r;
    int radius = r.getAttackRadius();
    int damage = r.getDamage();
    assert(radius >= 1 && radius <= 10);
    assert(damage >= 5 && damage <= 20);
    std::cout << "Rebel test passed.\n";
}

void testRandom() {
    Random rnd;
    for (int i = 0; i < 100; ++i) {
        int val = rnd.getInt(1, 10);
        assert(val >= 1 && val <= 10);

        double dval = rnd.getDouble(0.0, 1.0);
        assert(dval >= 0.0 && dval <= 1.0);
    }
    std::cout << "Random test passed.\n";
}

void testBase() {
    GeneralGrievous general(50);
    Base base(1000, general);

    base.addDroid(std::make_unique<BasicDroid>(10));
    base.addDroid(std::make_unique<Stormtrooper>(30, 5));
    base.addDroid(std::make_unique<Scout>(15, 10.0));
    base.addDroid(std::make_unique<Worker>(8, 25));

    for (int i = 0; i < 5; ++i) {
        base.addRebel(Rebel());
    }

    int initialEnergy = base.getEnergy();

    base.simulateStep();
    int energyAfterStep = base.getEnergy();

    assert(energyAfterStep != initialEnergy); // энергия должна измениться

    base.printStatus();

    std::cout << "Base test passed.\n";
}

int main() {
    testDroid();
    testGeneralGrievous();
    testStormtrooper();
    testScout();
    testWorker();
    testBasicDroid();
    testRebel();
    testRandom();
    testBase();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
