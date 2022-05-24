#include <ctime>
#include <iostream>
#include <unistd.h>

#define MAX_STRING_LENGTH 10
std::string gen_random(const int len) {

    // static: The value can change, but the variable will persist throughout the execution of the program even if the variable is declared in a function.
    // const: A const is a promise that you will not try to modify the value once set.
    static const char alphanum[] = "BR";
    std::string tmp_s;
    //Informs a std::basic_string object of a planned change in size, so that it can manage the storage allocation appropriately.
    tmp_s.reserve(len);


    // for n times, randomly pick element from alphanum array and append to temp_s
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main() {

    // fire up the engine for random number generator, the seed is the time elapsed since 1970 multiplied by the processor id of the processor running the program
    srand((unsigned)time(NULL) * getpid());
    //call our user defined function which takes in the legnth of the random string
    int length = rand() % MAX_STRING_LENGTH;

    std::cout << "Length of string is " << length << std::endl;
    std::string myString = gen_random(length);
    std::cout << "The randomly generated string is " << myString <<std::endl;
    if(length<1)
    {
        std::cout << "Magic box, did not find you worthy of a string!\nTry again!\n"; return 0;
    }
    int score = 0;
    int multiplier = 1;
    score = ((int)myString[0]=='R') ? 10 : 20;
    for(int i = 1 ; i < length ; i++)
    {   int add = 0;
        //std::cout << "At Character: " << myString[i] << std::endl;
        if(myString[i]==myString[i-1])
            multiplier++;
        else
            multiplier=1;
        //multiplier = (myString[i]==myString[i-1]) ? multiplier++ : 1;
        //std::cout << "Current Multiplier: " << multiplier << std::endl;
        score+= ((int)myString[i]=='R') ? 10*multiplier : 20*multiplier;
        //std::cout << "Adding now " << add << std::endl;
        //std::cout << std::endl;
    }
    std::cout << score ;
    return 0;
}
