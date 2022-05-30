#include <iostream>
#include <memory>
using namespace std;

class Player {

    public:
    Player() {
        cout << "I am a player, I just not spawned\n";
    }
    ~Player() {
        cout << "Ops, that enemy killed me, I just died!\n";
    }
};

int main()
{
    unique_ptr<Player> player1 (new Player());
    Player* player2 = new Player();
    delete player2;
    return 0;
}
