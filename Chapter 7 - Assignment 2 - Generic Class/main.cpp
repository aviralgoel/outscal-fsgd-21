#include <iostream>

using namespace std;

template <typename T>
class SpecialAbility {

    private:
    T attackStrength;

    public:
    T performSpecialAbility() {
        return attackStrength;
    }
    void setAttackStrength(T _strength)
    {
        attackStrength = _strength;
    }
};

int main()
{
    SpecialAbility<int> intObj;
    SpecialAbility<float> floatObj;

    int i_str;
    float f_str;
    cout << "Enter your strength in int format\n";
    cin >> i_str;
    intObj.setAttackStrength(i_str);
    cout << "Enter your strength in float format\n";
    cin >> f_str;
    floatObj.setAttackStrength(f_str);
    cout << "Your int warrior can deal " << intObj.performSpecialAbility() << " in one hit."<< endl;
    cout << "Your float warrior can deal " << floatObj.performSpecialAbility() << " in one hit."<< endl;
    return 0;
}
