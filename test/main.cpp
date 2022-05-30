#include <iostream>
class Outscal {
public:
 Outscal () {
 std::cout << "1 ";
 }
};
class OutscalGame : public Outscal {
public:
 OutscalGame() {
 std::cout << "2 ";
 }
};
class OutscalDev : public OutscalGame {
public:
 OutscalDev() {
 std::cout << "3\n";
 }
};
void test () {
 OutscalGame clan;
 std::cout << "\n";
}
int main() {
 OutscalDev clan1;
 test();
 return 0;
}
