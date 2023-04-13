#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "Trainer.h"
#include "Building.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <iostream>
#include "Point2D.h"
#include <math.h>
#include <string.h>

class WildPokemon:public GameObject{
    enum WildStates{
        IN_ENVIRONMENT=0,
        DEAD=1,
        IN_TRAINER=2
    };
protected:
    double attack;
    double health;
    bool variant;
    bool in_combat;
    Trainer* current_trainer;
    string name;



public:
    WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);
    void follow(Trainer* t);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    int deadcount;
    int followingcount;
    int countAlive;
    bool ShouldBeVisible();
    Trainer *get_Trainer();
    void WildPokemonUpdateHealth();
    
};
#endif
