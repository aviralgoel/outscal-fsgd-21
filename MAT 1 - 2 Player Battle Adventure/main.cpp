#include <iostream>
#include <memory>
using namespace std;

//Game Class : It is responsible for displaying welcome text, rules and game over text. It is alwo responsible to assign heros to the player at the start of the gane.
// The update method of the Game class will run as long as both players are alive and wait for each to play their turn.
enum struct HeroTypes
{
    Warlord,
    Marksman,
    Healer
};

class Hero {

    protected:
    int health;
    int damage;
    int healing;
    int criticalHitDamage;
    HeroTypes type;
    public:
    Hero() {
        health = 0;
        damage = 0;
        healing  = 0;
        criticalHitDamage = 0;
    }
    int getHeroHealth() {
        return health;
    }
    int getHeroDamage() {
        return damage;
    }
    HeroTypes getHeroType() {
        return type;
    }
    virtual ~Hero() {
    }
    virtual int BaseAttack() = 0;
    //virtual int SpecialAbility() = 0;
    virtual void IncreaseHealth() = 0;
    virtual void decreaseHealth(int) =0;

};
class Warlord: public Hero {

    public:
    Warlord() {
        health = 200;
        damage = 25;
        healing  = 10;
        type = HeroTypes::Warlord;

    }

    ~Warlord() {
    }
    int BaseAttack() {
        int doDamanage = damage + criticalHitDamage;
        return doDamanage;
    }
    //virtual int SpecialAbility() = 0;
    virtual void IncreaseHealth()
    {
        cout << "Increasing health by " << healing << "\n";
        health += healing;
    }
    virtual void decreaseHealth(int _dmRcvd)
    {
    cout << "Decreasing health by " << _dmRcvd << "\n";
        health-=_dmRcvd;
    }



};
class Marksman: public Hero {

    public:
    Marksman() {
        health = 100;
        damage = 45;
        healing  = 15;
        type = HeroTypes::Marksman;
    }
    ~Marksman() {

    }
    virtual void IncreaseHealth()
    {
        cout << "Increasing health by " << healing << "\n";
        health += healing;
    }
    virtual void decreaseHealth(int _dmRcvd)
    {
    cout << "Decreasing health by " << _dmRcvd << "\n";
        health-=_dmRcvd;
    }
    int BaseAttack() {
        int doDamanage = damage + criticalHitDamage;
        return doDamanage;
    }


};
class Healer: public Hero {

    public:
    Healer() {
        health = 150;
        damage = 15;
        healing  = 20;
        type = HeroTypes::Healer;

    }
    ~Healer() {
    }
    virtual void IncreaseHealth()
    {
        cout << "Increasing health by " << healing << "\n";
        health += healing;
    }
    virtual void decreaseHealth(int _dmRcvd)
    {
    cout << "Decreasing health by " << _dmRcvd << "\n";
        health-=_dmRcvd;
    }
    int BaseAttack() {
        int doDamanage = damage + criticalHitDamage;
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
        while(hero1->getHeroHealth() > 0 && hero2->getHeroHealth()>0)
        {
            int player1Health = hero1->getHeroHealth();
            int player2Health = hero2->getHeroHealth();
            cout << "Player 1 Health: " << player1Health << endl;
            cout << "Player 2 Health: " << player2Health << endl;
            cout << "Player 1: Play your turn.\nPress (H) to Heal or Press (D) to Damage\n";
            char player1choice; char player2choice;
            do {

                cin >> player1choice;
            }while(player1choice!='H' && player1choice!='D');
            if(player1choice=='H')
                hero1->IncreaseHealth();
            if(player1choice=='D')
            {
                int damage = hero1->BaseAttack();
                hero2->decreaseHealth(damage);
            }
            cout << "Player 2: Play your turn.\nPress (H) to Heal or Press (D) to Damage\n";
            do {

                cin >> player2choice;
            }while(player2choice!='H' && player2choice!='D');
             if(player2choice=='H')
                hero2->IncreaseHealth();
            if(player2choice=='D')
            {
                int damage = hero2->BaseAttack();
                hero1->decreaseHealth(damage);
            }
        }
    }
};

int main()
{
    Game game;
    game.Start();
    game.Update();

    return 0;
}
