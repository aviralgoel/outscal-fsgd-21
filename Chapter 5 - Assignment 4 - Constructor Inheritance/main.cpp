#include <iostream>

using namespace std;

class Player {

    public:
    Player() {
        cout << "Creating an object of Player\n";
    }
    ~Player() {
    cout << "Destroying an object of the Player\n";
    }
};

class StrongPlayer: public Player {

    public:
    StrongPlayer() {
        cout << "Creating an object of class StrongPlayer \n";
    }
    ~StrongPlayer() {
        cout << "Destroying an object of class StrongPlayer\n";
    }


};
int main()
{
    Player p;
    StrongPlayer s;
    return 0;
}
