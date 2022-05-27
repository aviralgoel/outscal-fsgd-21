#include <iostream>
class Game {
public:
 virtual void game_type () {
 std::cout << "1 ";
 }
};
class OutscalGame : public Game {
public:
 void game_type () {
 std::cout << "2 ";
 }
};
int main() {
 Game *game = new OutscalGame;
 game->Game::game_type();
 game->game_type();
 return 0;
}
