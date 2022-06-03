#include <iostream>
#include <memory>
#include <map>
#include <string>

using namespace std;

// This is the base class for all actors of the game, both Hero and Enemy inherit from it.
class Actor
{

protected:
    int health;
    int meleeDamange;
    int lastDamageTaken; // variable to store the amount of damage that was taken by last attack
public:
    virtual ~Actor() = default;
    /* setters*/
    void setHealth(int _health)
    {
        health = _health;
        lastDamageTaken = 0;
    }
    /* getters */
    int getHealth()
    {
        return health;
    }
    /* other functions */
    virtual void TakeDamage(int _damage)
    {
        health -= _damage; // reduce health by the damage
        lastDamageTaken = _damage; //keep track of last damage taken (for special ability)

    }
    virtual int attackMelee() = 0; // function common and with different implementations for each derived class
    virtual int Heal() = 0;

};

// this is a base class for all enemies which inherits from Actor class
class Enemy: public Actor
{

public:
    Enemy () = default; // default constructor does nothing
    Enemy(int _currentLevel) // set enemy health and damage according to the level player is on
    {

        health = 50 + (5*_currentLevel)/2;
        cout << "A Enemy has spawned near you with " << health << " health!\n";
        meleeDamange = 5 + (5*_currentLevel)/2;

    }
    // public:
    virtual ~Enemy()
    {
        cout <<"The enemy has been killed\n";
    };
    virtual char RandomChoice() // method to decide whether the enemy chooses to attack or heal randomly
    {

        return (rand() % 5) ? 'M' : 'H'; // 20% chance of H 80% of M
    }
    virtual int attackMelee() override //this method returns how much damage the enemy will do for an attack
    {
        cout << "The enemy fights back with " << meleeDamange << " damage.\n";
        return meleeDamange; // this value will later be passed onto another actor as an arguement for how much health to reduce
    }
    virtual int Heal() override //enemy heals himself by incresing health
    {
        cout << "Behold! The enemy drank his healing potion!\n";
        health += 5;
        return 0;
    }
    virtual void TakeDamage(int _damage) override // take damage and reduce health
    {

        if(!(bool)(rand()%10)) // if 1/10 chance of enemy avoiding the damage (blocker)
        {
            cout << "The Enemy has blocked your damage!!\n";
            _damage = 0;
        }
        lastDamageTaken = _damage;
        health -= _damage;
    }

};

class BossEnemy: public Enemy // class specialy designed for the boss (Murlocks), it inherits from Enemy class
{

    //map<string, int> specialAbilities;

public:
    BossEnemy()
    {
        health = 100;
        meleeDamange = 20;
    }
    char RandomChoice()
    {

        return (rand() % 5) ? 'M' : 'H'; // 20% chance of H 80% of M
    }
    int attackMelee() override
    {
        cout << "Murlocks hits you with his Hammaer, inflicting " << meleeDamange << " damage.\n";
        return meleeDamange;
    }
    virtual int Heal() override
    {
        cout << "Behold! The Murlocks has used his Health Regeneration!!!\n";
        health += 10;
        return 0;
    }
    void TakeDamage(int _damage) override
    {

        if(!(bool)(rand()%5))
        {
            cout << "Murlock has blocked your damage with his shield!!!!\n";
            _damage = 0;
        }
        lastDamageTaken = _damage;
        health -= _damage;
    }

};

// the hero class for players
class Hero: public Actor
{

    int rangedDamage;
    int currentLevel;
    int specialAbilityChance; // chance for special ability to happen, we will modify this for boss level.
    bool isInvincible; // if hero invinsible, then he will not take damage, it is part of special ability
    map<string, int> specialAbilities; // list of special ability unlocked
    map<string, bool> gearsOfArms; // list of special items found

public:
    Hero()
    {
        health = 500;
        meleeDamange = 10;
        rangedDamage = 5;
        isInvincible = false;
        currentLevel = 1; //player starts from level 1, as level increases his stats also increases
        specialAbilityChance = 10;
        // at the beginning of the game, no ability and no items are with the player.
        specialAbilities = {{"CriticalHit", false},{"Blocker", false}, {"LifeSteal", false}, {"RangedAttack", false}};
        gearsOfArms = {{"Map", false},{"Sword", false},{"Shield", false}, {"Armour", false}, {"Bow", false}};
    }
    // method to display all the stats of the player
    void DisplayPlayerStats()
    {
        cout << "PLAYER STATS:\n";
        cout << "Health of Hero: " << health << "\n";
        cout << "Melee Damage: " << meleeDamange << "\t Ranged Damage: " << rangedDamage << "\n";

        cout << "Gears of Arms Collected: ";
        // display all the items that have been found
        for (const auto &ele : gearsOfArms)
        {
            if(ele.second==true)
                cout << ele.first << ", ";
        }
        cout << endl;
        cout << "Special Abilities Unlocked: ";
        // display all the special abilities that have been unlocked
        for (const auto &ele : specialAbilities)
        {
            if(ele.second==true)
                cout << ele.first << ", ";
        }
        cout << endl;
    }
    // method to update items found
    void setGearsofArms(string _gear)
    {
        cout << "Hero has discovered a new Gear of Arm: " << _gear << endl;
        gearsOfArms[_gear] = true;
    }
    // method to update special ability unlocked
    void setSA(string _ability)
    {
        cout << "Hero has unlocked a new Special Abiliity: " << _ability << endl;
        specialAbilities[_ability] = true;
    }

    void setCurrentLevel(int _level)
    {
        currentLevel = _level;
    }
    int getCurrentLevel ()
    {
        return currentLevel;
    }

    // method to return how much damage to do
    int attackMelee() override
    {
        int damageToDo = meleeDamange; //base damage
        if(specialAbilities["CriticalHit"] == true && !(bool)(rand()%5)) // check if we can do critical hit (you need the ability + random luck)
        {
            damageToDo += meleeDamange*5;
            cout << "\nCRITICAL HIT!!!!!!!!\n";
        }
        else if(specialAbilities["LifeSteal"] == true && !(bool)(rand()%5)) // check if we can do life steal (you need the ability + random luck)
        {
            cout << "!!!Special Ability Life-Steal Activated!!!! Hero gains some health.";
            health+=3*currentLevel;

        }
        cout << "Your hero slams his weapon across the enemy's face with " << damageToDo << " damage.\n";
        return damageToDo;
    }
    int attackRanged()
    {

        if (specialAbilities["RangedAttack"]==true && !(bool)(rand()%5)) // check if we can do ranged attack special ability (you need the ability + random luck)
        {
            cout << "!!! Ranged Hit Special Ability Activated !!!\n";
            cout << "Your hero is invinsible for the next turn!\n";
            isInvincible = true;

        }
        cout << "Your hero sneaks a ranged projectile towards the enemy doing " << rangedDamage << "!\n";
        return rangedDamage;
    }
    int Heal() override //hero heals himself
    {
        cout << "Behold! The hero summons the spirits and heals himself!\n";
        health += (currentLevel * 20);
        return 0;
    }
    virtual void TakeDamage(int _damage) override //hero takes damage, but he can avoid it if he has blocker ability and some luck
    {
        if(specialAbilities["Blocker"]==true && !(bool)(rand()%5))
        {
            cout << "!!!Special Ability Blocked Activated!!!! Hero takes no damage.\n";
            _damage = 0;
        }
        // did the hero use Ranged Attack special ability last turn?
        if(isInvincible)
        {
            cout << "You are in invincible mode, hero takes no damage >:)\n";
            _damage = 0;
        }
        lastDamageTaken = _damage;
        health -= _damage;
    }
    // this method can change the chance of special abillity, we use it on boss fight to double the chance
    void setSpecialAbilityChance(int _chance)
    {
        specialAbilityChance = _chance;
    }
    ~Hero()
    {
        cout << "Your hero has been killed by the evil monsters\n";
    }


};
class Game
{

    unique_ptr<Hero> player;
public:
    void Start()
    {
        Monologue();
        Rules();
        SpawnPlayer();
    }
public:
    void Update()
    {
        if(!player)
        {
            cout << "Player is has not been spawned correctly!\n";
            return;
        }
        for(int i = 1 ; i < 6 ; i++)
        {
            player->DisplayPlayerStats();
            LoadLevel(i);
            AwardPlayer(i);
        }
        player->DisplayPlayerStats();
        FinalLevel();

    }
private:
    void Monologue() // print back story
    {
        cout << "\"Ancient legends speak of fiver gears of arms, one for each element of the earth, earth (map), fire (sword), shield(water), armour(gold) and bow(air)\"\n\nToegther they have the power of annihilate the most powerful of the evil...\n";
        cout << "Our hero Malhar, first of his name, bearer of the House Outscal, begins his journey in quest of all the four gear of arms.\nHe must find 'em all to rescue his village.\n";

    }

    void Rules() // print game rules
    {
        cout << "\nRules:\n";
        cout << "1. You hero has the ability to perform melee as well as ranged attack.\n";
        cout << "2. You can also perform a special attack once every level.\n";
        cout << "3. Kill enemies, collect all four gear of arms and survie till the end to fight Murlocs.\n";
        cout << "4. If your hero dies, the game is over.\n\n";
    }

    void SpawnPlayer() // instantiate the player
    {
        player = make_unique<Hero>();
    }

    void LoadLevel(int _currentPlayerLevel) // basic mechanism of first 5 levels
    {
        int numOfEnemies = _currentPlayerLevel;
        cout <<"You have stepped in to level " << _currentPlayerLevel <<endl;
        cout <<"Tread lighty, danger awaits at every corner!\n";
        shared_ptr<Enemy> e1 = make_shared<Enemy>(_currentPlayerLevel);
        numOfEnemies--;
        while(player->getHealth() > 0 && e1->getHealth() > 0) // while the player is alive and enemy is alive
        {
            cout <<"Quick Press H (Heal) or M (Melee Attack) or R (Ranged Attack)\n";
            char ch;
            do
            {
                cin >> ch;
            }
            while(ch!='H' && ch!='M' && ch!='R'); // player enters his action
            int damageToEnemy = PlayerChoice(ch);
            e1->TakeDamage(damageToEnemy); // damage to enemy
            int damageToPlayer = EnemyChoice(e1->RandomChoice(), e1); //random enemy action
            player->TakeDamage(damageToPlayer); // damage to player
            cout << "Player Health is: " << player->getHealth() << endl;
            cout << "Enemy Health is: " << e1->getHealth() << endl;
            if(numOfEnemies && e1->getHealth() <= 0) //more enemies for high levels, spawn another enemy when one enemy dead
            {
                e1.reset();
                e1 = make_shared<Enemy>(_currentPlayerLevel);
                numOfEnemies--;
            }

        }
        if(player->getHealth()<1) // if player is dead
        {
            cout << "Your hero dies of wounds of the war.\n The Murlocs and his army is victorious.\n";
        }



    }

    int PlayerChoice(char _ch) // player action decider based on the input
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

    int EnemyChoice(char _ch, shared_ptr<Enemy> actor) //enemy action decider based on random generated input
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
private:
    void AwardPlayer(int _currentPlayerLevel) //when player completes a level, unlock things for player depending on the level
    {
        switch(_currentPlayerLevel)
        {
        case 1:
            player->setGearsofArms("Map");
            player->setSA("CriticalHit");
            break;
        case 2:
            player->setGearsofArms("Sword");
            player->setSA("Blocker");
            break;
        case 3:
            player->setGearsofArms("Shield");
            player->setSA("LifeSteal");
            break;
        case 4:
            player->setGearsofArms("Armour");
            player->setSA("RangedAttack");
            break;
        case 5:
            player->setGearsofArms("Bow");
            break;
        }
    }
private:
    void FinalLevel() //logic for boss level
    {

        cout <<"You have stepped in to level " << 6 <<endl;
        cout <<"THIS IS THE FINAL LEVEL!!! MURLOCS ARRIVES!!\n";
        shared_ptr<BossEnemy> e1 = make_shared<BossEnemy>(); //spawn boss
        player->setSpecialAbilityChance(5); //increase player chance for special ability, 5 = 20%
        while(player->getHealth() > 0 && e1->getHealth() > 0)
        {
            cout <<"Quick Press H (Heal) or M (Melee Attack) or R (Ranged Attack)\n";
            char ch;
            do
            {
                cin >> ch;
            }
            while(ch!='H' && ch!='M' && ch!='R');
            int damageToEnemy = PlayerChoice(ch);
            e1->TakeDamage(damageToEnemy);
            int damageToPlayer = EnemyChoice(e1->RandomChoice(), e1);
            player->TakeDamage(damageToPlayer);
            cout << "Player Health is: " << player->getHealth() << endl;
            cout << "Enemy Health is: " << e1->getHealth() << endl;

        }
        if(player->getHealth()<1)
        {
            cout << "Your hero dies of wounds of the war.\n The Murlocs and his army is victorious.\n";
        }
    }

};

int main()
{
    srand(time(0)); // seed for randomness
    Game game;
    game.Start();
    game.Update();



    return 0;
}
