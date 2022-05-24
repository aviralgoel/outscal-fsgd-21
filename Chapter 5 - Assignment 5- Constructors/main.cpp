#include <iostream>

using namespace std;

class Player {

    protected:
    int health;
    int lives;

    public:
    Player() {
        // default number of lives
        lives = 3;
        health = 500;
    }
    Player(int _health, int _lives) {

        health = _health;
        lives = _lives;
        cout << "I am a player, I just got spwaned! with " << health << " health.\n";
    }

    ~Player() {
        cout << "I am a player and I died with " << health << " remaining.\n";
    }


};
class FastPlayer: public Player {

    private:
    float speed;
    public:
    FastPlayer(float _speed) {
        speed = _speed;
        // how to access this?
        cout << "Constructing FastPlayer object with " << health << " health, " << lives << " lives and " << speed << " speed.\n";
    }
    ~FastPlayer() {
        cout << "FastPlayer object destroyed\n";
    }



};
// does it never get destrcucted? where does it go then? (without delete keyword)
void localObjects()
{
    Player* player = new Player(0, 0);
    FastPlayer* fastPlayer = new FastPlayer(20.00);

    delete player;
    delete fastPlayer;
}
int main()
{
    Player* player1 = new Player(100,1);
    Player* player2 = new Player(200,2);
    Player* player3 = new Player(300,3);

    //FastPlayer fastPlayer = new FastPlayer();

    localObjects();
    delete player1;
    delete player2;
    delete player3;

    return 0;
}
