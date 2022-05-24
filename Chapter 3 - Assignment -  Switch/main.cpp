#include <iostream>

using namespace std;


enum struct PlayerTypes
{
    Scout,
    Heavy,
    Soldier,
    Medic
};

int main()
{
    PlayerTypes s = PlayerTypes::Soldier;
    PlayerTypes h = PlayerTypes::Heavy;

    switch(s)
    {
        case PlayerTypes::Scout:
            cout << "You are Scout!\nThat's what I'm talking about!\n"; break;
        case PlayerTypes::Medic:
            cout << "You are Medic!\nBack from zhe dead!\n"; break;
        case PlayerTypes::Soldier:
            cout << "You are Soldier!\nKa-boom!\n"; break;
        case PlayerTypes::Heavy:
            cout << "You are Heavy!\nWeeeeeeeeh! Waaaaaaaahh!\n"; break;
    }
}
