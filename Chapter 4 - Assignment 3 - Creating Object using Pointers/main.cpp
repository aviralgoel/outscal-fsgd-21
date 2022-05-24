#include <iostream>

using namespace std;

class Player {

    private:
    int playerHealth;

    public:
    void setPlayerHealth(int _health)
    {
        playerHealth = _health;
    }
    int getPlayerHealth()
    {
        return playerHealth;
    }


};

int main()
{
    Player* player = new Player();
    player->setPlayerHealth(100);
    cout << player->getPlayerHealth() << endl;
    delete player;

    return 0;
}
