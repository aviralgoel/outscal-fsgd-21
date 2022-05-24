#include <iostream>

using namespace std;

class Player {

    public:
    Player (){
    cout << " I am a player (the name is as per your liking). I just got spawned in the game world because my developer created the player's object. \n" <<
        "\nAgggh! boring life begins, fight, die, respawn. Huh I am gonna kill that bastard if I get out of this game\n";
    }
    ~Player()
    {
        cout <<"\nSee?? that C++ destroyed my object(figure out how) and now I died.  that **** language you know >_<\n";
    }


};


int main()
{
    Player p;

    return 0;
}
