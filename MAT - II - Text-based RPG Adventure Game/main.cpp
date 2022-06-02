#include <iostream>
#include <memory>
#include <map>
#include <string>

using namespace std;

class Actor {

    protected:
    int health;
    int meleeDamange;
    public:
    virtual ~Actor() = default;
    void setHealth(int _health)
    {
        health = _health;
    }
    int getHealth()
    {
        return health;
    }
    void TakeDamage(int _damage)
    {
        health -= _damage;
    }
    virtual int attackMelee() = 0;
    virtual int Heal() = 0;

};

class Enemy: public Actor {

    public:
    Enemy () = default;
    Enemy(int _currentLevel)
    {
        cout << "A Enemy has spawned near you!\n";
        health = 50 + (5*_currentLevel)/2;
        meleeDamange = 5 + (5*_currentLevel)/2;

    }
   // public:
    virtual ~Enemy() {
        cout <<"The enemy has been killed\n";
    };
    char RandomChoice()
    {
        srand(time(0));
        return (rand() % 5) ? 'M' : 'H'; // 20% chance of H 80% of M
    }
    int attackMelee() override
    {
        cout << "The enemy fights back with " << meleeDamange << " damage.";
        return meleeDamange;
    }
    int Heal() override {
        cout << "Behold! The enemy drank his healing potion!\n";
        health += 5;
        return 0;
    }

};

class BossEnemy: public Enemy {

    map<string, int> specialAbilities;
    public:
    BossEnemy()
    {
    }
};


class Hero: public Actor {

    int rangedDamage;
    int defence;
    int currentLevel;
    map<string, int> specialAbilities;
    map<string, bool> gearsOfArms;

    public:
    Hero()
    {   health = 100;
        meleeDamange = 10;
        rangedDamage = 5;
        defence = 5;
        currentLevel = 1;
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
    void setCurrentLevel(int _level)
    {
        currentLevel = _level;
    }
    int getCurrentLevel ()
    {
        return currentLevel;
    }
    int attackMelee() override
    {
        cout << "Your hero slams his weapon across the enemy's face\n";
        return meleeDamange;
    }
    int attackRanged()
    {
        cout << "Your hero sneaks a ranged projectile towards the enemy!\n";
        return rangedDamage;
    }
    int Heal() override {
        cout << "Behold! The hero summons the spirits and heals himself!\n";
        health += (currentLevel * 10);
        return 0;
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
        if(!player)
        {
            cout << "Player is has not been spawned correctly!\n";
            return;
        }
        player->DisplayPlayerStats();
        LoadLevel(2);
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
    }
    private: void LoadLevel(int _currentPlayerLevel)
    {   int temp = _currentPlayerLevel;
        cout <<"You have stepped in to level 1.\n";
        cout <<"Tread lighty, danger awaits at every corner!\n";
        shared_ptr<Enemy> e1 = make_shared<Enemy>(_currentPlayerLevel);
        temp--;
        while(player->getHealth() > 0 && e1->getHealth() > 0)
        {
            cout <<"Quick Press H (Heal) or M (Melee Attack) or R (Ranged Attack)\n";
            char ch;
            do {
                cin >> ch;
            } while(ch!='H' && ch!='M' && ch!='R');
            int damageToEnemy = PlayerChoice(ch);
            e1->TakeDamage(damageToEnemy);
            int damageToPlayer = EnemyChoice(e1->RandomChoice(), e1);
            player->TakeDamage(damageToPlayer);
            cout << "Player Health is: " << player->getHealth() << endl;
            cout << "Enemy Health is: " << e1->getHealth() << endl;
            if(temp && e1->getHealth() <= 0)
            {
                e1.reset();
                e1 = make_shared<Enemy>(_currentPlayerLevel);
                temp--;
            }

        }


    }
    private: int PlayerChoice(char _ch)
    {
        if(_ch=='H')
        {
            player->Heal();
            return 0;
        }
        else if(_ch=='M')
        {
            return player->attackMelee();
        }
        else
        {
            return player->attackRanged();
        }

    }
     private: int EnemyChoice(char _ch, shared_ptr<Enemy> actor)
    {
        if(_ch=='M')
        {
            return actor->attackMelee();
        }
        else
        {
            return actor->Heal();
        }
    }

};

int main()
{
   Game game;
   game.Start();
   game.Update();
//    Hero hero;
//    cout << hero.getHealth();
    //nemy e1(1);
    //cout << e1.RandomChoice();




    return 0;
}
