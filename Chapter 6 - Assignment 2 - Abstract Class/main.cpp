#include <iostream>
#include<memory>
using namespace std;

class Enemy {

    public:
    virtual void Attack()  = 0;
     //https://stackoverflow.com/questions/69081119/that-is-abstract-but-has-non-virtual-destructor-the-delete-is-causing-an-error
    virtual ~Enemy() = default;
};

class BossEnemy : public Enemy {

    public:
    void Attack() {
        cout << "Boss enemy is attacking!\n";
    }


};

int main()
{
    //raw pointer, have to be explicitly deleted from the heap
    Enemy* enemy = new BossEnemy();
    enemy->Attack();
    delete enemy;

    //smart pointer, automatically gets deleted
    unique_ptr<Enemy> enemy = make_unique<BossEnemy>();
    enemy->Attack();
    return 0;
}
