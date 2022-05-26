#include <iostream>

using namespace std;

class PlayerInterface {

    public:
    virtual void DoubleJump() = 0;
    virtual void Fire() = 0;
};

class Player : public PlayerInterface {

    public:
    void DoubleJump() {
        cout << "Hehey, I'm flyin'!(Double jump is overrriden)\n";
    }
    void Fire() {
        cout << "If you order now, I'll throw in a second beatin', absolutely free.(Fire is overrriden)\n";

    }

};
int main()
{
    Player player;
    player.DoubleJump();
    player.Fire();
    return 0;
}
