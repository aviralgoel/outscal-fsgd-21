#include <iostream>

using namespace std;

class Player {

    private:

    int health;
    int score;
    string name;
    int mana;
    bool isAlive;

    public:

    Player() {
    health = 100;
    score = 1;
    name = "Unnamed Player";
    cout << "Hi, I am a default constructor of Class Player, basically developers use me to initialize important variables/parameters of the player\n";
    bool isAlive = true;
    mana = 100;
    }

    int getHealth() {
        return health;
    }

    int getScore() {
        return score;
    }
    string getName() {
        return name;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    Player player;
    cout << player.getScore() << endl << player.getName() << endl << player.getHealth() << endl;
    return 0;
}
