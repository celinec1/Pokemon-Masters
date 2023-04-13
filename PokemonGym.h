#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include "Building.h"
#include "Point2D.h"

class PokemonGym: public Building{
    enum PokemonGymStates{
        NOT_DEFEATED = 0,
        DEFEATED = 1
    };

private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;
    
public:
// CONSTRUCTORS
//default
    PokemonGym();
    PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
    
public:
    double GetPokeDollarCost(unsigned int battle_qty);
    unsigned int GetHealthCost(unsigned int battle_qty);
    unsigned int GetNumBattlesRemaining();
    bool isAbleToBattle(unsigned int battle_qty, double budget, unsigned int health);
    unsigned int TrainPokemon(unsigned int battle_units);
    unsigned int GetExperiencePerBattle();
    bool Update();
    bool passed();
    void ShowStatus();
    //destructor
    virtual ~PokemonGym();
};

#endif
