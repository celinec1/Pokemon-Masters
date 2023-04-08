#include "WildPokemon.h"


using namespace std;

WildPokemon :: WildPokemon (string in_name, double in_attack, double in_health, bool in_var, int in_id, Point2D in_loc) : GameObject(in_loc, in_id,'W'){
	name = in_name;
	attack = in_attack;
	health = in_health;
	variant = in_var;
	in_combat = false;
	state = IN_ENVIRONMENT;
	countAlive = 0;
    deadcount=0;
    followingcount=0;
	current_trainer=NULL;
	cout << "WildPokemon constructed" << endl;
}

void WildPokemon :: follow(Trainer* t){
	//change the state that it follows the trainer
	current_trainer = t;
	state = IN_TRAINER;
    followingcount++;
	in_combat = true;
    
}

bool WildPokemon :: get_variant(){
	return variant;
}

double WildPokemon :: get_attack(){
	return attack;
}

double WildPokemon :: get_health(){
	return health;
}	

bool WildPokemon :: get_in_combat(){
	return in_combat;
}

bool WildPokemon :: IsAlive(){
	if (health > 0){
		return true;
	}else{
		health = 0;
		return false;
	}
}

bool WildPokemon :: Update(){

    bool stats=IsAlive();
    if (!stats){
        state=DEAD;
        deadcount=deadcount+1;
        if (deadcount==1){
            return true;
        }
    }
    
	switch(state){
	case IN_TRAINER:{
            //starts to follow the trainers location. It's coordinates matches the trainers'
			double newx= location.x;
			double newy= location.y;
            location.x= current_trainer->GetLocation().x;
            location.y= current_trainer->GetLocation().y;

			if(newx!=location.x && newy!=location.y){
				WildPokemonUpdateHealth();
			}
            if (followingcount==1){
                followingcount++;
                return true;
            }else{
                return false;
            }
            break;
	}
	case IN_ENVIRONMENT:
		return false;
		break;
    case DEAD:
			health=0;
            return false;
            break;
    default:
            break;
	}
	return false;
}

void WildPokemon :: ShowStatus(){
	//to print to show what status the wildpokemon is in for the user
	cout << name << " status: " << endl;
	GameObject :: ShowStatus();

	//checking to see which state the wildpokemon is in
	switch(state){
	case IN_ENVIRONMENT:
		cout << "  is in the environment" << endl;
		break;
	case DEAD:
		in_combat=false;
		cout << "  is dead" << endl;
		break;
	case IN_TRAINER:
		cout << "  is following trainer " << current_trainer -> GetId() << endl;
		break;
	default:
		break;
	}

	//Prints basic information each time
	cout << "	Health: " << get_health() << endl;
	cout << "	Atack: " << get_attack() << endl;
	cout << "	Variant: " << get_variant() << endl;
	if (get_in_combat()){
		cout << "	in combat with trainer: " << current_trainer->GetName() << endl;
	}

}

bool WildPokemon::ShouldBeVisible(){
    if (state==DEAD){
        return false;
    }else{
        return true;
    }
}

void WildPokemon:: WildPokemonUpdateHealth(){
   //can change if it dies too slow
	bool stats=IsAlive();
	if (stats==true){
		health=health-1.0;
	}else{
		current_trainer-> wildNum(false);
		in_combat=false;
		current_trainer=NULL;
		state=DEAD;

	}
}

Trainer * WildPokemon:: get_Trainer(){
	return current_trainer;
}




