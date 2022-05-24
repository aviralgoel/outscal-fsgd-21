#include <iostream>

using namespace std;

class Enemy {

    public:
    void Walk()
    {
        cout << "Walking from the Enemy Class\n";
    }

    virtual void Attack()
    {
        cout << "Attacking from Base Class (Enemy)\n";
    }
};

class FlyEnemy: public Enemy {

    public:
    void Attack()
    {
        cout << "Attacking from Derived Class (FlyEnemy)\n";
    }
};

class Dragon: public FlyEnemy {

    public:
    void Attack()
    {
        cout << "Attacking from Derived Class (Dragon)\n";
    }
};

int main()
{
 //Are all these examples of static binding?
//    Enemy enemy;
//    FlyEnemy flyenemy;
//
//    enemy.Attack();
//    flyenemy.Attack();

// Is this dynamic binding here? (without virtual keyword)

    Enemy* enemy = new FlyEnemy();
    enemy->Attack();


//    FlyEnemy* enemy2 = new Dragon();
//    enemy2->Walk();
//
//    Dragon droggo;
//    droggo.Attack();

// Why is this dynamic binding? what information is the compiler lacking that it cannot decide at compile time?
//    Enemy* enemy3 = new Dragon();
//    enemy3->Attack();


// do we have any other scenarios/context apart from virtual functions where dynamic binding happens?

    return 0;
}
