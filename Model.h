#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"
#include "Trainer.h"
#include "View.h"
#include "WildPokemon.h"
#include <list>
#include "Input_Handling.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Model{
private:
    int time;

    // linked list for GameObject
    list <GameObject*> object_ptrs;
    list <GameObject*> active_ptrs;
    int object_count;
    
    //linked list for Trainer
    list <Trainer*> trainer_ptrs;
    int trainers_count;

    //linked list for WildPokemon
    list <WildPokemon*> wildpokemon_ptrs;
    int wildpokemon_count;

    //linked list for PokemonGym
    list <PokemonGym*> gym_ptrs;
    int gym_count;

    //linked list for PokemonCenter
    list <PokemonCenter*> center_ptrs;
    int center_count;
    
public:
    Model();
    //destructor for model
    virtual ~Model();
    Trainer *GetTrainerPtr(int id);
    PokemonCenter *GetPokemonCenterPtr(int id);
    PokemonGym *GetPokemonGymPtr(int id);
    bool Update();
    void Display(View &view);
    void ShowStatus();
    int NumTrainers();
    int NumGyms();
    int NumCenters();
    void Proximity();
    //to input new commands
    void NewCommand();
    
};

//in order to get location of new gameobject, need to make sure the user inputs a double accordingly to get location
double input_double();
//in order to get the id of a new object, need to make sure user inputs an integer accordingly
int input_int();

#endif

