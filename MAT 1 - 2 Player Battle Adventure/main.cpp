#include <iostream>
#include <memory>
#include<cstdlib>
using namespace std;

/* enum to store the types of available heros in the game */
enum struct HeroTypes
{
    Warlord,
    Marksman,
    Healer
};

/* Base class Hero, this class has the base attributes common to all the heroes, virtual functions which are defined in derived classes
and some functions which are defined in the base class itself. */
class Hero {

    protected:
    int health; // health of the hero
    int baseDamage; // base damage
    int minHeal; // minimum amount of health healed by a hero
    int maxHeal; // maximum amount of health a hero can heal himself
    int minAdditionalDamage; // minimum amount of damage in addition to base damage
    int maxAdditionalDamage; // maximum amount of damage in addition to base damage
    HeroTypes type; // type of the hero
    public:
    /* default constructor of the base class */
    Hero() {
        health = 0;
        baseDamage = 0;
        minHeal = 0;
        maxHeal = 0;
        minAdditionalDamage = 0;
        maxAdditionalDamage = 0;
    }
    /* getters */
    int getHeroHealth() {
        return health;
    }
    int getHeroDamage() {
        return baseDamage;
    }
    HeroTypes getHeroType() {
        return type;
    }
    /* virtual methods, implemented in the respective derived classes */
    virtual int Attack() = 0; // method to calculate and return how much total (base+additional) damage to inflict on other player
    virtual void IncreaseHealth() = 0; // method to calculate and return how much total (heal-range) health to increase for self
    virtual void DecreaseHealth(int) = 0; // method to take given damage and decrease health by that much

    /* non virtual methods, this logic is common to all the heros */

    //calculate and return a random number between minHeal and maxHeal
     int CalculateHealing() {
        srand((unsigned) time(NULL));
        int random = minHeal + (rand() % (maxHeal-minHeal));
        return random;
    }
    //calculate and return a random number between minAdditionalDamage and maxAdditionalDamage
    int CalculateAdditionalDamage() {
        srand((unsigned) time(NULL));
        int random = minAdditionalDamage + (rand() % (maxAdditionalDamage-minAdditionalDamage));
        return random;
    }

    /* default keyword means "It means that you want to use the compiler-generated version of that function, so you don't need to specify a body." */
    /* this is because I do not have any additional code to put in the destructor */
    virtual ~Hero() = default;

};
class Warlord: public Hero {

    public:
    Warlord() {
        health = 200;
        baseDamage = 20;
        minHeal  = 10;
        maxHeal = 15;
        minAdditionalDamage = 5;
        maxAdditionalDamage = 10;
        type = HeroTypes::Warlord;

    }

    int Attack() override
    {

        int doDamanage = baseDamage + CalculateAdditionalDamage();
        cout << "Warlord slashes his sword across his enemy inflicting " << doDamanage << " damage!\n";
        return doDamanage;
    }
    void IncreaseHealth() override
    {
        cout << "Warlords decides to drink his healing potion...\n";
        int _heal = CalculateHealing();
        cout << "Health Increased by "<< _heal << "\n";
        health += _heal;
    }
    void DecreaseHealth(int _dmRcvd) override
    {
        cout << "Warlord is attacked with " << _dmRcvd << " damage.\n";
        health-=_dmRcvd;
    }


};
class Marksman: public Hero {

    public:
    Marksman() {
        health = 150;
        baseDamage = 25;
        minHeal  = 5;
        maxHeal = 10;
        minAdditionalDamage = 10;
        maxAdditionalDamage = 15;
        type = HeroTypes::Marksman;
    }
    void IncreaseHealth() override
    {
        cout << "Marksman decides to pop some pills...\n";
        int _heal = CalculateHealing();
        cout << "Health Increased by "<< _heal << "\n";
        health += _heal;
    }
    void DecreaseHealth(int _dmRcvd) override
    {
    cout << "Decreasing health by " << _dmRcvd << "\n";
        health-=_dmRcvd;
    }
    int Attack() override
    {
        int doDamanage = baseDamage + CalculateAdditionalDamage();
         cout << "Marksman takes his shot and pierces the enemy's body doing " << doDamanage << " damage!\n";
        return doDamanage;
    }
};
class Healer: public Hero {


    public:
    Healer() {
        health = 120;
        baseDamage = 15;
        minHeal  = 15;
        maxHeal = 20;
        minAdditionalDamage = 10;
        maxAdditionalDamage = 15;
        type = HeroTypes::Healer;

    }

    void IncreaseHealth() override
    {
         cout << "Healer decides to summon the energy of the dead...\n";
        int _heal = CalculateHealing();
        cout << "Health Increased by"<< _heal << "\n";
        health += _heal;
    }
    void DecreaseHealth(int _dmRcvd) override
    {
        cout << "Decreasing health by " << _dmRcvd << "\n";
        health-=_dmRcvd;
    }
    int Attack() override
    {
        int doDamanage = baseDamage + CalculateAdditionalDamage();
        cout << "Healer slams his bonesaw to the enemy's head, whoosh its  " << doDamanage << " damage!\n";
        return doDamanage;
    }


};
class Game {

    int p1_choice = 0, p2_choice = 0;
    unique_ptr<Hero> hero1;
    unique_ptr<Hero> hero2;

    public: void Start()
    {
        WelcomeMessage();
        GameRules();
        HeroSelection();
        HeroAssign();
        DeclareHeros();
    }
    private: void DeclareHeros() {
        cout << "Player 1's Hero is " << (int)hero1->getHeroType() << endl;
        cout << "Player 2's Hero is " << (int)hero2->getHeroType() << endl;
        cout << "\nDungeon Dwellers begin to battle...!\n";
    }
    public: void HeroAssign()
    {
        switch(p1_choice) {
        case 0: hero1 = make_unique<Warlord>(); break;
        case 1: hero1 = make_unique<Marksman>(); break;
        case 2: hero1 = make_unique<Healer>(); break;
        }

        switch(p2_choice) {
        case 0: hero2 = make_unique<Warlord>(); break;
        case 1: hero2 = make_unique<Marksman>(); break;
        case 2: hero2 = make_unique<Healer>(); break;
        }
    }
    private: void HeroSelection()
    {
        do {
            cout << "\n\nPlayer 1 select your hero\n\n";
            cout << "Press 0 for Warlord\n";
            cout << "Press 1 for Marksman\n";
            cout << "Press 2 for Healer\n";
            cin >> p1_choice ;}
        while(p1_choice > 2 || p1_choice < 0);

        do {
            cout << "\n\nPlayer 2 select your hero\n\n";
            cout << "Press 0 for Warlord\n";
            cout << "Press 1 for Marksman\n";
            cout << "Press 2 for Healer\n";
            cin >> p2_choice; }
        while(p2_choice > 2 || p2_choice < 0);

    }
    private: void WelcomeMessage()
    {
        cout <<"Welcome to Dungeon Dwellers!\n";
        cout << "You've stepped in the abyss of death and darkness...\n";
        cout << "You will be trapped in this Dungoes for eternity.\nThe only way to escape the dungeon is by tormenting the souls of other prisoners...\n";
        cout << "Sharpen your swords, \nprepare your magic,\nand get ready to die again and again...!";
    }
    private: void GameRules()
    {
        cout << "\n\nThe Dungoen demands your obedience..\n";
        cout << "1. This is a two player battle. Each player begins by selecting their Hero.\n";
        cout << "2. There are three available Heros:\n a) Warlord (High Health, High Damange, Low Healing)\n b) Marksman (Medium Health, Medium Damange, Medium Healing)\n";
        cout << " c) Healer (Medium Health, Low Damage, High Healing).\n";
        cout << "3. This is a turn based battle.\n4. Each player can perform one action during his turn: Heal (press H) or Damange (press D)\n";
        cout << "5. Anytime during the battle you or your opponent have a chance to perform critical heal/damage.\n";
        cout << "6. Last hero surviving wins!";

    }
    public: void Update()
    {
        while(true)
        {
            cout << "The Battle Begins..!\n";
            GetPlayerHealths();
            ActiveGame();
            char ch;
            do {
                cout << "The Battle Ends..!\nDo you want to play again? (Y/N)";
                cin >> ch;

            }while(ch!='Y' && ch!='N');
            if(ch=='N')
                return;
            HeroSelection();
            HeroAssign();
            DeclareHeros();
        }

    }
    private: void ActiveGame()
    {
    while(hero1->getHeroHealth() > 0 && hero2->getHeroHealth()>0)
        {

            cout << "Player 1: Play your turn.\nPress (H) to Heal or Press (D) to Damage\n";
            char player1choice; char player2choice;
            do {
                cin >> player1choice;
            }while(player1choice!='H' && player1choice!='D');
            if(player1choice=='H') {
                hero1->IncreaseHealth();
                GetPlayerHealths();
            }
            if(player1choice=='D')
            {
                int damage = hero1->Attack();
                hero2->DecreaseHealth(damage);
                GetPlayerHealths();
                if(hero2->getHeroHealth()<=0)
                {
                    DisplayLoseText(2);
                    break;
                }

            }
            cout << "Player 2: Play your turn.\nPress (H) to Heal or Press (D) to Damage\n";
            do {

                cin >> player2choice;
            }while(player2choice!='H' && player2choice!='D');
             if(player2choice=='H')
             {

                hero2->IncreaseHealth();
                GetPlayerHealths();
             }

            if(player2choice=='D')
            {
                int damage = hero2->Attack();
                hero1->DecreaseHealth(damage);
                GetPlayerHealths();
                if(hero1->getHeroHealth()<=0)
                {
                    DisplayLoseText(1);
                    break;
                }

            }
        }
    }
    private: void GetPlayerHealths()
    {
        cout << "Player 1 Health: " << hero1->getHeroHealth() << endl;
        cout << "Player 2 Health: " << hero2->getHeroHealth() << endl;
    }
    private: void DisplayLoseText(int _playerNumber)
    {
        cout << "Player " << _playerNumber << " has fallen !!\n. They will haunt the dungeon forever...\n";
    }
};

int main()
{
    Game game;
    game.Start();
    game.Update();
    //Warlord wr; Healer hr; Marksman mr;

    return 0;
}
