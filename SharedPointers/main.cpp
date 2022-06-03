#include <iostream>
#include <memory>
using namespace std;


class Actor{

    public:
    int health = 100;


    virtual int getHealth() = 0;
    virtual ~Actor() = default;
};

class Enemy : public Actor {

    int getHealth() override
    {
        return health;
    }


};

void foo(unique_ptr<Actor> _actor)
{
    cout << _actor->getHealth();
}
void foo(shared_ptr<Actor> _actor)
{
    cout << _actor->getHealth();
}

int main()
{
    unique_ptr<Actor> ptr = make_unique<Enemy>();
    shared_ptr<Actor> ptr1 = make_shared<Enemy>();
    foo(ptr1);
//    cout << ptr->getHealth();
//    Actor* ptr1 = new Enemy();
//    cout << ptr1->getHealth();


}
