#include <iostream>
#include <memory>

using namespace std;

class Player {

    private:
    int health;
    int lives;

    public:
    Player(int _health, int _lives) {
        health = _health;
        lives = _lives;
        cout << "I'm a Player object, I just got spawned. My current health is " << health << endl;
    }
    ~Player() {
        cout << "I'm a Player object, I just got killed. My current health is " << health <<endl;
    }


};

class FastPlayer: public Player {

    private:
    int speed;

    public:
    FastPlayer(int x, int h, int l ) : Player (h, l) {
    speed = x;
    cout << "I'm a Fast Player object, I just spawned.\n";
    }

    ~FastPlayer() {
        cout << "I'm a Fast Player object, I just got killed.\n";
    }
};

void localObjects()
{
    unique_ptr<Player> player1 (new Player(50, 2));
    unique_ptr<FastPlayer>player4(new FastPlayer(140,111,5));
}
int main()
{
    unique_ptr<Player> player1 (new Player(100, 3));
    unique_ptr<Player> player2 (new Player(150, 4));
    unique_ptr<Player> player3 (new Player(200, 5));
    unique_ptr<FastPlayer>player4(new FastPlayer(120,100,3));
    localObjects();

    //FastPlayer fp(120, 100, 3);

    return 0;
}
