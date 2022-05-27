#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Ogre {

    public:
    int age;
    int weight;
    int damage;

    Ogre (int _age, int _weight, int _damage) {
        age = _age;
        weight = _weight;
        damage = _damage;
    }
};

template <typename T>
struct FindBySomething {
    T val;
    FindBySomething(T t) : val(t) {}

    bool operator() (Ogre const& ogre)
        { return (ogre.weight == val); }
};

int main()
{   // Ogre(age, weight, damage)
    vector<Ogre> ogres = {Ogre(10, 65, 20), Ogre(20, 10, 16), Ogre(8, 171, 3)};
    auto result = find_if(ogres.begin(), ogres.end(), FindBySomething<int>(65));

    cout << "Age of Ogre whose weight is 65 kg is " << result->age << endl << endl;
    return 0;
}
