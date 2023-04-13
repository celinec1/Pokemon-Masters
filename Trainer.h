#ifndef TRAINER_H
#define TRAINER_H
#include "Building.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <iostream>
#include "Point2D.h"
#include <math.h>
#include <string.h>
#include "PokemonGym.h"
#include "PokemonCenter.h"
class Trainer: public GameObject{
    enum TrainerStates{
        STOPPED = 0,
        MOVING = 1,
        FAINTED = 2,
        AT_CENTER = 3,
        IN_GYM = 4,
        MOVING_TO_CENTER= 5,
        MOVING_TO_GYM= 6,
        BATTLING_IN_GYM = 7,
        RECOVERING_HEALTH = 8
    };
public:
    Trainer();
    Trainer(char in_code);
    Trainer(string in_name, int in_id, char in_code, double in_speed, Point2D in_loc);

    //functions
    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym *gym);
    void StartMovingToCenter(PokemonCenter *center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    //made a GetName() in order to print the name of trainer in the GameCommand class
    string GetName();
    //static double GetRandomAmountOfPokeDollars();
    virtual ~Trainer();

    // gets the number of wild pokemon following the trainer
    unsigned int getnumwildpokemons();
    unsigned int NumberPokemon;
    bool isfollowed();
    int followedhealth(bool following);
    void wildNum(bool wild);

    
protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);

private:
    double speed;
    bool is_at_center;
    bool is_IN_GYM;
    int health=20;
    unsigned int experience;
    double PokeDollars;
    unsigned int battles_to_buy=0;
    unsigned int potions_to_buy=0;
    string name;
    PokemonCenter * current_center=NULL;
    PokemonGym * current_gym=NULL;
    Point2D destination;
    Vector2D delta;

};
static double GetRandomAmountOfPokeDollars();

#endif
