#include <iostream>

using namespace std;

int main()
{
    int enemyHealth;
    cout << "Enter enemy health\n";
    cin >> enemyHealth;
    int *p, *q;
    p = q = &enemyHealth;
    cout << "Values stored inside p and q are given below:\n";
    cout << p << "\t" << q << endl;
    cout << "Values pointed by p and q are given below\n";
    cout << *p << "\t" << *q << endl;
    cout << "Value stored inside enemyHealth is: \n";
    cout << enemyHealth << endl;
    cout << "Enter new values of enemyHealth\n";
    cin >> enemyHealth;
    cout << "Values pointed by p and q are given below\n";
    cout << *p << "\t" << *q << endl;
    cout << "Value stored inside enemyHealth is: \n";
    cout << enemyHealth << endl;
    return 0;
}
