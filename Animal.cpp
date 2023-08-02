#include <iostream>
#include "Animal.h"
#include <string>
#include "Pars.h"
//#include <fstream>
using namespace std;


Animal ::Animal(string nameofanimal, string region, int seed){
    this->nameofanimal = nameofanimal;
    this->region= region;
	this->seed = seed;
}

Animal::Animal() {
    this->nameofanimal = "";
    this->region= "";
    this->seed = 0;
   
}

string Animal::getRegion(){
    return this->region;
}

string Animal::getname(){
    return this->nameofanimal;
}

int Animal::getseed(){
    return this->seed;
}

void Animal::printfunc(){
    cout<<nameofanimal<<endl;

}

/*
Animal Animal::whowins(Animal obj1, Animal obj2){
    cout<<"Helloworld"<<endl;
    return obj1;
    

}
*/



