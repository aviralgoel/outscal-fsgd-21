#include <iostream>

using namespace std;

int main()
{
    int playerHealth;
    cout << "Enter player health:\n";
    cin >> playerHealth;
    int* p;
    p = &playerHealth;

    cout << "Value of pointer p: " << p << endl;
    cout << "Value of player health (by dereferencing): " << *p << endl;
    cout << "Value of player health (by accessing identifier): " <<  playerHealth << endl;
    if(playerHealth==*p)
        cout << "Yup, the values are same.\n";
    cout << "Enter new value of playerHealth\n";
    cin >> *p;
    cout << "Value of player health (by dereferencing): " << *p << endl;
    cout << "Value of player health (by accessing identifier): " <<  playerHealth << endl;
    if(playerHealth==*p)
         cout << "Yup, the values are same.\n";

    return 0;
}
