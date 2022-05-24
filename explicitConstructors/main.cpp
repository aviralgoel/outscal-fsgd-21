#include <iostream>
using namespace std;

class Player {

    int m;
    public:
    Player() {
        m = 100;
    }

    int getM() {
        return m;
    }
};
void AssignPlayerID (Player _player) {
    int id = _player.getM();

}
int main()
{

    Player player();

    AssignPlayerID({});

    return 0;
}
