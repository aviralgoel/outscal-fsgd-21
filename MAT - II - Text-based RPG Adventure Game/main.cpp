#include <iostream>
#include <memory>
#include <map>
#include <string>
using namespace std;

class Actor {

    protected:
    int health;
    public:
    virtual ~Actor() = default;
};

class Enemy: public Actor {
    int damage;
    public:
    virtual ~Enemy() = default;
};

class BossEnemy: public Enemy {

    map<string, int> specialAbilities;
    public:
    BossEnemy()
    {
    }
};


class Hero: public Actor {

    int meleeDamange;
    int rangedDamage;
    int defence;
    map<string, int> specialAbilities;
    map<string, bool> gearsOfArms;

    public:
    Hero()
    {   health = 100;
        meleeDamange = 10;
        rangedDamage = 5;
        defence = 5;
        specialAbilities = {{"CriticalHit", false},{"Blocker", true}, {"LifeSteal", false}, {"RangedAttack", false}};
        gearsOfArms = {{"Sword", false},{"Shield", false}, {"Armour", false}, {"Bow", false}};
    }
    void DisplayPlayerStats() {
        cout << "PLAYER STATS:\n";
        cout << "Health of Hero: " << health << "\n";
        cout << "Melee Damage: " << meleeDamange << "\t Ranged Damage: " << rangedDamage << "\n";
        cout << "Defence Power: " << defence << "\n";
        cout << "Gears of Arms Collected: ";
        for (const auto &ele : gearsOfArms)
        {
            if(ele.second==true)
                cout << ele.first << " ";
        }
        cout << endl;
        cout << "Special Abilities Unlocked: ";
        for (const auto &ele : specialAbilities)
        {
            if(ele.second==true)
                cout << ele.first << " ";
        }

    }


};
class Game {

    unique_ptr<Hero> player;
    public: void Start()
    {
        Monologue();
        Rules();
        SpawnPlayer();
    }
    public: void Update()
    {
        //isplayPlayerStats();
        //DisplayGameStats();
    }
    private: void Monologue()
    {
        cout << "\"Ancient legends speak of four gears of arms, one for each element of the earth.\"\n\nToegther they have the power of annihilate the most powerful of the evil...\n";
        cout << "Our hero Malhar, first of his name, bearer of the House Outscal, begins his journey in quest of all the four gear of arms.\nHe must find 'em all to rescue his village.\n";

    }
    private: void Rules()
    {
        cout << "\nRules:\n";
        cout << "1. You hero has the ability to perform melee as well as ranged attack.\n";
        cout << "2. You can also perform a special attack once every level.\n";
        cout << "3. Kill enemies, collect all four gear of arms and survie till the end to fight Murlocs.\n";
        cout << "4. If your hero dies, the game is over.\n";
    }
    private: void SpawnPlayer()
    {
        player = make_unique<Hero>();
        player->DisplayPlayerStats();
    }


};

int main()
{
    Game game;
    game.Start();

    return 0;
}
