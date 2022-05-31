#include <iostream>
#include <memory>
#include<cstdlib>

#define MAX_HEALTH 300
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
    bool specialAbilityUsed; // has the hero used his special ability?
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
        specialAbilityUsed = false;
    }
    /* getters */
    HeroTypes getHeroType() {
        return type;
    }
    int getHeroHealth() {
        return health;
    }
    int getHeroDamage() {
        return baseDamage;
    }
    /* virtual methods, implemented in the respective derived classes */
    virtual int Attack() = 0; // method to calculate and return how much total (base+additional) damage to inflict on other player
    virtual void IncreaseHealth() = 0; // method to calculate and return how much total (heal-range) health to increase for self
    virtual void DecreaseHealth(int) = 0; // method to take given damage and decrease health by that much
    virtual void SpecialAbility () = 0; // perform the special ability of the hero

    /* non virtual methods, this logic is common to all the heros */

    /*calculate and return a random number between minHeal and maxHeal*/
     int CalculateHealing() {
        srand((unsigned) time(NULL));
        int random = minHeal + (rand() % (maxHeal-minHeal));
        return random;
    }

    /*calculate and return a random number between minAdditionalDamage and maxAdditionalDamage*/
    int CalculateAdditionalDamage() {
        srand((unsigned) time(NULL));
        int random = minAdditionalDamage + (rand() % (maxAdditionalDamage-minAdditionalDamage));
        return random;
    }

    /* default keyword means "It means that you want to use the compiler-generated version of that function, so you don't need to specify a body." */
    /* this is because I do not have any additional code to put in the destructor */
    virtual ~Hero() = default;

};
// Derived class for Hero Type Warlord which inherits from the Hero class.
class Warlord: public Hero {

    private:
    int lastDamageTaken; // amount of damage taken from the last attack, used later for special ability
    public:
    Warlord() {
        health = 200;
        baseDamage = 20;
        minHeal  = 10;
        maxHeal = 15;
        minAdditionalDamage = 5;
        maxAdditionalDamage = 10;
        lastDamageTaken = 0;
        type = HeroTypes::Warlord;
    }

    int Attack() override
    {
        int doDamanage = baseDamage + CalculateAdditionalDamage(); // total damage is base damage + random amount of damage (from a given range)
        cout << "Warlord slashes his sword across his enemy inflicting " << doDamanage << " damage!\n";
        return doDamanage;
    }
    void IncreaseHealth() override
    {
        cout << "Warlords decides to drink his healing potion...\n";
        int _heal = CalculateHealing(); //random heal amount (from a given range)
        cout << "Health Increased by "<< _heal << "\n";
        health += _heal;
    }
    void DecreaseHealth(int _dmRcvd) override
    {
        lastDamageTaken = _dmRcvd;
        cout << "Warlord is attacked with " << _dmRcvd << " damage.\n";
        health-=_dmRcvd;
    }
    // WARLORD special ability is: damage taken last turn will be cancelled.
    void SpecialAbility() {
        // if specialability already used, display error
        if(specialAbilityUsed)
        {
            cout << "You've already used your special hero's special ability!\n";
        }
        // else, increase health by damageTakenLastTurn
        else
        {
            cout << "Warlord enters into RAGE mode. Damange of previus turn is reversed!\n";
            health+=lastDamageTaken;
            cout << "Health restored by " << lastDamageTaken << endl;
            specialAbilityUsed = true; // special ability is used, can't be used again.
        }

    }


};
class Marksman: public Hero {
    /* Marksman special ability is, he will mark the enemy in one turn and then the next turn enemy will take 2x damage*/
    bool enemyMarked; // has the marksman marked the enemy for his special ability?
    public:
    Marksman() {
        health = 150;
        baseDamage = 25;
        minHeal  = 5;
        maxHeal = 10;
        minAdditionalDamage = 10;
        maxAdditionalDamage = 15;
        enemyMarked = false;
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
        //if the enemy was marked last turn, he will take double damage
        if(enemyMarked)
        {
            enemyMarked = false;
            cout << "TWICE DAMAGE!!\n";
            doDamanage *=2;
        }
        cout << "Marksman takes his shot and pierces the enemy's body doing " << doDamanage << " damage!\n";
        return doDamanage;
    }
    void SpecialAbility()
    {
        // has the special ability used already?
        if(specialAbilityUsed)
        {
            cout << "You've already used your special hero's special ability!\n";
        }
        else
        {
            cout << "Marksman has marked his enemy!, damage done next round will be 2x!!!!!\n";
            enemyMarked = true; // mark the enemy this turn
            specialAbilityUsed = true; // special ability can't be used every again
        }
    }
};
class Healer: public Hero {

    /* Healer's special ability is he can skip one turn and heal twice the next turn*/
    private:
    bool healDoubled;

    public:

    Healer() {
        health = 120;
        baseDamage = 15;
        minHeal  = 15;
        maxHeal = 20;
        minAdditionalDamage = 10;
        maxAdditionalDamage = 15;
        type = HeroTypes::Healer;

        healDoubled = false; // should the heal be twice because of special ability?
    }

    void IncreaseHealth() override
    {
        int _heal = CalculateHealing();
        // healDoubled will be true if specialability was used last turn
        if(healDoubled)
        {
              _heal *=2;
              healDoubled = false;
        }

        cout << "Healer decides to summon the energy of the dead...\n";
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
    void SpecialAbility()
    {
        // if special ability already used, display error
        if(specialAbilityUsed)
        {
            cout << "You've already used your special hero's special ability!\n";
        }
        else
        {
            cout << "The healer has entered the world of purgatory...\nLNext heal will be doubled\n";
            specialAbilityUsed = true; // special ability can not be used hereafter
            healDoubled = true; //next turn heal will be doubled
        }
    }

};
class Game {

    char p1_choice; // hero selection choice of player 1
    char p2_choice; // hero selection choice of player 2
    unique_ptr<Hero> hero1; // pointer to Hero of player 1
    unique_ptr<Hero> hero2; // pointer to Hero of player 2

    // only called once during the game
    public: void Start()
    {
        DisplayWelcomeMessage();
        DisplayGameRules();
        DisplayHeroSelection();
        HeroObjectCreation();
        DeclareHeros();
    }

    // Display List of Heros and Take user input
    private: void DisplayHeroSelection()
    {
        do {
            cout << "\n\nPlayer 1 select your hero\n\n";
            cout << "Press 0 for Warlord\n";
            cout << "Press 1 for Marksman\n";
            cout << "Press 2 for Healer\n";
            cin >> p1_choice ;}
        while(p1_choice !='0' && p1_choice !='1' && p1_choice!='2');

        do {
            cout << "\n\nPlayer 2 select your hero\n\n";
            cout << "Press 0 for Warlord\n";
            cout << "Press 1 for Marksman\n";
            cout << "Press 2 for Healer\n";
            cin >> p2_choice; }
        while(p2_choice !='0' && p2_choice !='1' && p2_choice!='2');

    }
    // Depending on player input, create and assign the hero to players
    private: void HeroObjectCreation()
    {
        switch(p1_choice) {
        case '0': hero1 = make_unique<Warlord>(); break;
        case '1': hero1 = make_unique<Marksman>(); break;
        case '2': hero1 = make_unique<Healer>(); break;
        }

        switch(p2_choice) {
        case '0': hero2 = make_unique<Warlord>(); break;
        case '1': hero2 = make_unique<Marksman>(); break;
        case '2': hero2 = make_unique<Healer>(); break;
        }
    }
    // Displays the heros chosen by Players
    private: void DeclareHeros() {
        cout << "Player 1's Hero is " << (int)hero1->getHeroType() << endl;
        cout << "Player 2's Hero is " << (int)hero2->getHeroType() << endl;
        cout << "\nDungeon Dwellers begin to battle...!\n";
    }

    private: void DisplayWelcomeMessage()
    {
        cout <<"Welcome to Dungeon Dwellers!\n";
        cout << "You've stepped in the abyss of death and darkness...\n";
        cout << "You will be trapped in this Dungoes for eternity.\nThe only way to escape the dungeon is by tormenting the souls of other prisoners...\n";
        cout << "Sharpen your swords, \nprepare your magic,\nand get ready to die again and again...!";
    }
    private: void DisplayGameRules()
    {
        cout << "\n\nThe Dungoen demands your obedience..\n";
        cout << "1. This is a two player battle. Each player begins by selecting their Hero.\n";
        cout << "2. There are three available Heros:\n a) Warlord (High Health, High Damange, Low Healing)\n b) Marksman (Medium Health, Medium Damange, Medium Healing)\n";
        cout << " c) Healer (Medium Health, Low Damage, High Healing).\n";
        cout << "3. This is a turn based battle.\n4. Each player can perform one action during his turn: Heal (press H) or Damange (press D)\n";
        cout << "5. Anytime during the battle you or your opponent have a chance to perform a special ability ONLY once!\n";
        cout << "6. Special Abilities of heroes:\n";
        cout << " a) Warlord (He can undo the damage taken last turn!)\n b) Marksman (He can MARK the enemy this turn and deal double damage next turn to the marked enemy!)\n";
        cout << " c) Healer (Nothing happens this turn, next turn heal is doubled!).\n";
        cout << "6. Last hero surviving wins!\n\n";
        cout << "The Battle Begins..!\n";

    }
    /* This is basically the game loop, it is only exited when Player finishes one game and declines to play again*/
    public: void Update()
    {
        while(true)
        {
            GetPlayerHealths(); // display initial health of players
            ActiveGame();   // game logic begins
            NewGamePrompt(); // DO YOU WANT TO PLAY AGAIN? IF USER SAYS NO, GAME IS EXITED, ELSE CONTINUES
            DisplayHeroSelection(); // if the user agrees to play another game, prompt hero selection menu
            HeroObjectCreation();   // assign heros
            DeclareHeros(); // announce the heros
        }

    }
    /* This method has the core logic of the game*/
    private: void ActiveGame()
    {
    // while both heros are alive
    while(hero1->getHeroHealth() > 0 && hero2->getHeroHealth()>0)
        {
            //Player 1 turn
            cout << "Player 1: Play your turn.\nPress (H) to Heal or Press (D) to Damage or Press (S) for Special Ability\n";
            char player1choice; char player2choice;
            do
            {
                cin >> player1choice;
            } while(player1choice!='H' && player1choice!='D' && player1choice!='S'); // no input other than HDS is accepted
            if(player1choice=='H') {
                if(hero1->getHeroHealth()<MAX_HEALTH)
                {
                    hero1->IncreaseHealth();
                    GetPlayerHealths();
                }
                else
                    cout << "Hero has reached maximum health. Healing action is wasted!\n";
            }
            else if(player1choice=='D') {
                int damage = hero1->Attack();
                hero2->DecreaseHealth(damage);
                GetPlayerHealths();
                if(hero2->getHeroHealth()<=0)
                {
                    DisplayLoseText(2);
                    break;
                }

            }
            else if(player1choice=='S') {
                hero1->SpecialAbility();
                if(hero1->getHeroHealth()<=0)
                {
                    DisplayLoseText(1);
                    break;
                }
            }

            cout << "Player 2: Play your turn.\nPress (H) to Heal or Press (D) to Damage or Press (S) for Special Ability\n";
            do {

                cin >> player2choice;
            }while(player2choice!='H' && player2choice!='D' && player2choice!='S'); // no input other than HDS is accepted
             if(player2choice=='H') {
                if(hero2->getHeroHealth()<MAX_HEALTH)
                {
                    hero2->IncreaseHealth();
                    GetPlayerHealths();
                }
                else
                    cout << "Hero has reached maximum health. Healing action is wasted!\n";
             }
            if(player2choice=='D') {
                int damage = hero2->Attack();
                hero1->DecreaseHealth(damage);
                GetPlayerHealths();
                if(hero1->getHeroHealth()<=0)
                {
                    DisplayLoseText(1);
                    break;
                }

            }
            else if(player1choice=='S') {
                hero2->SpecialAbility();
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
        cout << "Player " << _playerNumber << " has fallen !!\nThey will haunt the dungeon forever...\n";
    }
    // once an active game ends, asks the user if they wish to continue
    private: void NewGamePrompt()
    {
        char ch;
            do {
                cout << "The Battle Ends..!\nDo you want to play again? (Y/N)";
                cin >> ch;

            }while(ch!='Y' && ch!='N');
            if(ch=='N')
                exit(0);
    }
};


int main()
{
    Game game;
    game.Start(); //initialized the welcome message, rules, and player selection menu for the first time
    game.Update(); // begins the game, runs the game logic, declares the winner and prompts play again menu.

    return 0;
}
