#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <string>
#include <iostream>
//#include <sstream>

using namespace std;

class Animal{
    public:
        string nameofanimal;
        string region;
        int seed;
        Animal(string nameofanimal, string region, int seed);
        Animal();
        string getRegion();
        void printfunc();
        int wincount =0;
        string getname();
        int getseed();
        //Animal whowins(Animal obj1, Animal obj2);

        
};

#endif
