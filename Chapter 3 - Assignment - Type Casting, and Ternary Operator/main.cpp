#include <iostream>

using namespace std;

int main()
{
    cout << "==========Implicit TYPECASTING=================\n";
    // 1. Create a variable playerHealth *of* int data type and give it a value by taking it from user input.
    int playerHealth;
    cout << "Enter Player Health\n";
    cin >> playerHealth;

    // 2. Now, create another variable playerCode of short data type.
    short playerCode;
    // 3. Assign int value to short i.e., playerCode  = playerHealth ;
    playerCode = playerHealth;
    // 4. Use sizeof() operation on the first playerHealth **and then playerCode to determine and print the size of both int and short data types.
    cout << "Size of playerCode: " << sizeof(playerCode) << " bytes & Size of playerHealth: " << sizeof(playerHealth) << " bytes." <<endl;

    cout << "==========Explicit TYPECASTING=================\n";
    // 1. Create a variable playerHealth *of* int data type and give it a value by taking it from user input.

    cout << "Enter Player Health\n";
    cin >> playerHealth;

    float playerHealthFractional = (float)(playerHealth/2);
    cout << "Size of playerHealthFractional: " << sizeof(playerHealthFractional) << " bytes & Size of playerHealth: " << sizeof(playerHealth) << " bytes." <<endl;

    bool isPlayerHealthSameAsFractionalHealth = (playerHealthFractional==playerHealth) ? true : false;

    cout << boolalpha << isPlayerHealthSameAsFractionalHealth << endl;

    cout << playerHealthFractional;
}
