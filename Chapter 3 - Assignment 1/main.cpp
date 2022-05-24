#include <iostream>

using namespace std;

int main()
{
    for(int i = 0 ; i < 4; i++) // 0 1 2 3
    {
        //spaces
        for(int j = 3-i ; j > 0 ; j--) //
        {
            cout << " ";
        }
        //stars
        for(int j = 0 ; j < (i*2)+1 ; j++) // 1 3 5 7
        {
            cout << "*";
        }

        cout << endl;
    }
}
