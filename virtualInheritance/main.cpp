#include <iostream>

class Enemy {

public:
    int enemyHealth = 100;
};

class Fly:public Enemy {  };

class Ground:public Enemy {  };

class Hybrid: public Ground, public Fly {  };

int main()
{
    Hybrid hybrid;
    std::cout << ++hybrid.Ground::enemyHealth << std::endl; // access base class via Ground (Hybrid -> Ground -> Base)
    std::cout << --hybrid.Fly::enemyHealth << std::endl;  // access base class via Fly (Hybrid -> Ground -> Base)

}
