#include <iostream>

using namespace std;

class Enemy {

    public:
    virtual void Attack()  = 0;
};

class BossEnemy : public Enemy {

    public:
    void Attack() {
        cout << "Boss enemy is attacking!\n";
    }
    //https://stackoverflow.com/questions/69081119/that-is-abstract-but-has-non-virtual-destructor-the-delete-is-causing-an-error
    virtual ~Enemy() = default;

};

int main()
{
    Enemy* enemy = new BossEnemy();
    enemy->Attack();
    delete enemy;
    return 0;
}
