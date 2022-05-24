#include <iostream>
class Game
 {
 int x;
 Game() { x = 5; }
};
int main()
 {
 Game *game = new Game;
 std::cout << game->x;
 return 0;
}
