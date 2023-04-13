#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"
#include "Point2D.h"

class PokemonCenter: public Building{
enum PokemonCenterStates{
    POTIONS_AVALIABLE=0,
    NO_POTIONS_AVAILABLE=1
};

private:
    unsigned int potion_capacity;
    unsigned int nums_potions_remaining;
    double pokedollar_cost_per_potion;
    
    
public:
//default constructor
   PokemonCenter();
//constructor
    PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);

public:
    bool HasPotions();
    unsigned int GetNumPotionRemaining();
    bool CanAffordPotion(unsigned int potion, double budget);
    double GetPokeDollarCost(unsigned int potion);
    unsigned int DistributePotion(unsigned int potion_needed);
    bool Update();
    void ShowStatus();
    //destructor
    virtual ~PokemonCenter();
};

#endif
