#include <iostream>

using namespace std;


//template <typename T, typename Y>
//T AddScore(T op1, Y op2) {
//
//    op1 = op1 + op2;
//    return op1;
//}

template <typename T>
T AddScore(T op1, T op2) {
    return op1+op2;
}
int main()
{
    int op1, op2;
    cout << "Enter you current score (int format) and bonus score to add (int format)\n";
    cin >> op1 >> op2;
    cout << "Updated score is:" << AddScore(op1, op2) << endl;
    cout << "Enter you current score (float format) and bonus score to add (float format)\n";
    float o1, o2;
    cin >> o1 >> o2;
    cout << "Updated score is: " << AddScore(o1, o2);
    // not passing <int, int> because the compiler can determine the appropriate instantiation.
    // ref: https://m.cplusplus.com/doc/oldtutorial/templates/

    //cout << AddScore(5,6) << endl;
    //cout << AddScore(5.5, 6.7) << endl;
    //cout << AddScore(5, 'a') << endl;
    //cout << AddScore('a', 5) << endl;
    return 0;
}
