#include <iostream>

using namespace std;

class Player{

    private:
    int health;
    int score;
    string name;
    int mana;
    int shield;


    public:
    Player(int _health, int _mana, int _shield)
    {
        health = _health;
        cout << "Hi, I am a custom constructor of Class Player, some call me parameterized constructor as well. Basically, developers use me to set the specific values to the variables.";
        mana = _mana;
        shield = _shield;
    }

    int getHealth()
    {
        return health;
    }






};

int main()
{
    Player player(500,250,100);
    cout << endl << player.getHealth();

    return 0;
}
