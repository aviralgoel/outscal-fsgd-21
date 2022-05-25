#include <iostream>
using namespace std;

class Player {

    public:
    void TakeDamage()
    {
        cout << "Base class Take Damage\n";
    }

};

class TankPlayer: public Player {

    public:
    void TakeDamage()
    {
        cout << "Derived class Take Damage\n";
    }
};

int main() {

    Player player;
    player.TakeDamage();
    TankPlayer tank;
    tank.TakeDamage();

}
