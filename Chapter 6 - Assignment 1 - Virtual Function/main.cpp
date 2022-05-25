#include <iostream>

using namespace std;

class Weapon {

    private:
    int magazineSize = 200;
    float fireRate = 20;
    float reloadTime = 30;
    string manufacturerName = "Jakobs";

    public:
    virtual void attack()
    {
        cout << "Weapon performed attack\n";
    }
    void info()
    {
        cout << "\nLoading weapon info..\n";
        cout << "Manufacturer Name:\t" << manufacturerName << ".\n";
        cout << "Fire Rate:\t" << fireRate << " bullets/second.\n";
        cout << "Magazine Size:\t" << magazineSize << " bullets.\n";
    }
};

class RangedWeapon: public Weapon {

    float weaponRange = 500;
    int scopeMagnitude = 5;

    public:
    void attack()
    {
        cout << "Weapon performed ranged attack!\n";
    }
    void info()
    {
        cout << "\nLoading weapon info..\n";
        cout << "Bullet Range:\t" << weaponRange << " meters.\n";
        cout << "Scope:\t" << scopeMagnitude << "x.\n";

    }

};

int main()
{
    //Weapon weapon;
    //weapon.info();

    //Weapon* weapon = new Weapon();
    //weapon->info();

    Weapon* ranged = new RangedWeapon();
    ranged->info();
    ranged->attack();
    //RangedWeapon ranged;
    //ranged.info();
    return 0;
}
