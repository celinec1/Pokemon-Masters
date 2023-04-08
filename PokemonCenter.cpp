#include "PokemonCenter.h"
#include <iostream>
#include <math.h>

using namespace std;

//CONSTRUCTORS

//default constructor
PokemonCenter::PokemonCenter(){
    display_code='C';
    potion_capacity=100;
    nums_potions_remaining=potion_capacity;
    pokedollar_cost_per_potion=5;
    state=POTIONS_AVALIABLE;
    cout << "PokemonCenter default constructed"<<endl;
}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc){
    id_num=in_id;
    location=in_loc;
    pokedollar_cost_per_potion=potion_cost;
    potion_capacity=potion_cap;
    nums_potions_remaining=potion_capacity;
    display_code='C';
    state=POTIONS_AVALIABLE;
    cout << "PokemonCenter constructed"<<endl;
}
 
//PUBLIC MEMBER FUNCTIONS
bool PokemonCenter::HasPotions(){
    if (nums_potions_remaining>=1){
        return true;
    }else{
        return false;
    }
}

unsigned int PokemonCenter::GetNumPotionRemaining(){
    return nums_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget){
    double cost=potion*pokedollar_cost_per_potion;
    if ((budget-cost)>=0){
        return true;
    }
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion){
    double result;
    result=potion*pokedollar_cost_per_potion;
    return result;
}
//this checks if the amount of potions remaining is greater than the number requested
//it will also subtract the potions bought from the potion remaining
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed){
    if (nums_potions_remaining>=potion_needed){
        nums_potions_remaining=nums_potions_remaining-potion_needed;
        return potion_needed;
    }else{
        potion_needed=0;
        return nums_potions_remaining;
    }
}
//if there is no more potions left, it will print and return false
bool PokemonCenter::Update(){
    if (nums_potions_remaining==0){
        state=NO_POTIONS_AVAILABLE;
        display_code='c';
        cout << "PokemonCenter (" << id_num << ") has ran out of potions."<<endl;
        return true;
    }else{
        return false;
    }
}
//this will call building:showstatus, as well as prints the amounts of potions and cost from the center
void PokemonCenter::ShowStatus(){
    cout << "PokemonCenter Status: ";
    Building::ShowStatus();
    cout << "PokeDollars per potion: "<<pokedollar_cost_per_potion<<endl;
    cout << "has "<<nums_potions_remaining<<" potion(s) remaining"<<endl;
}
//destructor
PokemonCenter::~PokemonCenter(){
    cout<<"PokemonCenter destructed"<<endl;
};
