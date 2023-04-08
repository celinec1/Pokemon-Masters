#include "Model.h"



using namespace std;

Model::Model(){
    time=0;
    //creating the object types, with its id number, initial location, and subscript
    //creating 6 point2d for the 6 objects
    Point2D p1= Point2D(1,20);
    Point2D p2= Point2D(10,20);
    Point2D p3= Point2D(5,1);
    Point2D p4= Point2D(10,1);
    Point2D p5= Point2D(0,0);
    Point2D p6= Point2D(5,5);
    Point2D p7= Point2D(10,12);
    Point2D p8= Point2D(15,5);
    
    //intializing all objects pointers
    WildPokemon*W1= new WildPokemon("WildPokemon1",5.0,2.0,false,1,p7 );
    WildPokemon*W2= new WildPokemon("WildPokemon2", 5.0, 2.0,false, 2, p8);
    PokemonCenter* C1= new PokemonCenter(1,1,100,p1);
    PokemonCenter *C2= new PokemonCenter(2,2,200,p2);
    PokemonGym *G1=new PokemonGym(10,1,2,3,1, p5);
    PokemonGym *G2= new PokemonGym(20,5,7.5,4,2,p6);
    Trainer *T1= new Trainer("Ash",1,'T',1,p3);
    Trainer *T2= new Trainer("Misty",2,'T',2,p4);

    object_ptrs.push_front(T1);
    object_ptrs.push_back(T2);
    object_ptrs.push_back(C1);
    object_ptrs.push_back(C2);
    object_ptrs.push_back(G1);
    object_ptrs.push_back(G2);
    object_ptrs.push_back(W1);
    object_ptrs.push_back(W2);
    
    active_ptrs.push_front(T1);
    active_ptrs.push_back(T2);
    active_ptrs.push_back(C1);
    active_ptrs.push_back(C2);
    active_ptrs.push_back(G1);
    active_ptrs.push_back(G2);
    active_ptrs.push_back(W1);
    active_ptrs.push_back(W2);

    trainer_ptrs.push_front(T1);
    trainer_ptrs.push_back(T2);

    center_ptrs.push_back(C1);
    center_ptrs.push_back (C2);

    gym_ptrs.push_back(G1);
    gym_ptrs.push_back(G2);

    wildpokemon_ptrs.push_back(W1);
    wildpokemon_ptrs.push_back(W2);

    object_count=8;
    trainers_count=2;
    center_count=2;
    gym_count=2;
    wildpokemon_count=2;

    cout<<"Model default constructed"<<endl;
}
//destructor 
Model::~Model(){
	for (list <GameObject*> ::iterator i=object_ptrs.begin();i != this -> object_ptrs.end(); i++)
    {
		delete *i; 
    }
    cout<<"Model destructed."<<endl;
};

//lookup amd validation service to the main program. Each returns a pointer.
Trainer* Model::GetTrainerPtr(int id){
    for (list <Trainer*>::iterator i=trainer_ptrs.begin(); i !=this->trainer_ptrs.end(); i++){
        if( (*i) -> GetId() == id)
		{
			return *i;
            break;
		}
    }
    return 0;
}

PokemonCenter * Model::GetPokemonCenterPtr(int id){
    for (list <PokemonCenter*>::iterator i= center_ptrs.begin();i!=this->center_ptrs.end();i++)
            if( (*i) -> GetId() == id)
		{
			return *i;
            break;
		}
    
    return NULL;
}
                        
PokemonGym * Model::GetPokemonGymPtr(int id){
        for (list <PokemonGym*>::iterator i=gym_ptrs.begin();i!=this->gym_ptrs.end();i++)
            if( (*i) -> GetId() == id)
		{
			return *i;
            break;
		}
    return NULL;
}

bool Model::Update(){
    time++;//increments time always
    Proximity();
    int Gympassed=0;
    int fainted=0;
    bool var;
    bool change=false;

    
    for (list<GameObject*>::iterator i = active_ptrs.begin(); i!= active_ptrs.end(); i++) {
        //if the current active_ptr is dead it will remove from the list
        if (!(*i)->ShouldBeVisible()){
            active_ptrs.erase(i);
            cout<<(*i)->GetDisplayCode()<<(*i)->GetId()<<" has been removed because it's dead"<<endl;
        }
        var= (*i)->Update();
        if(var==true){
            change=true;
        }
    }

    //when battles are done, and user wins. gym should equal the number of gyms which means they win
    for (list<PokemonGym*>::iterator i= gym_ptrs.begin(); i!= gym_ptrs.end();i++){
        if ((*i)->passed()){
            Gympassed++;
        }
    }
    //from pa3
      if (Gympassed==gym_count){
        cout<<"GAME OVER: You win! All battles are done!"<<endl;
        exit(0);
      }

      //if all pokemon faints, user loses. this checks if all has fainted or not
      for (list<Trainer*>::iterator i= trainer_ptrs.begin(); i !=trainer_ptrs.end();i++){
        if ((*i)->HasFainted()){
            fainted++;
        }
      }
      if (fainted==trainers_count){
         cout<<"Game Over: You lose! All of you Trainer's pokemon have fainted"<<endl;
         exit(0);
      }
      return change;
}




void Model::Display(View &view){
    view.Clear();

    for (list<GameObject*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); i++) {
		view.Plot(*i);
   }
   view.Draw();
}

void Model::ShowStatus(){
    cout<<"Time: "<<time<<endl;

    for (list<GameObject*>::iterator i = object_ptrs.begin(); i != object_ptrs.end(); i++) {
		(*i)->ShowStatus();
   }
}

int Model:: NumTrainers(){
    return trainers_count;
}

int Model:: NumCenters(){
    return center_count;
}

int Model:: NumGyms(){
    return gym_count;
}

void Model::Proximity(){
	for (list<Trainer*>::iterator i = trainer_ptrs.begin(); i != trainer_ptrs.end(); i++){
		for (list<WildPokemon*>::iterator j = wildpokemon_ptrs.begin(); j != wildpokemon_ptrs.end(); j++){
			if(GetDistanceBetween((*i)->GetLocation(),(*j)->GetLocation()) <= 1.0){
				//sees whether the wild pokemon is following trainer
				if(!((*j)->get_Trainer() == *i)){

					//if not, this will set teh wild pokemon to follow the trainer
					(*j)->follow(*i);

					//increases the number of wild pokemon following that specific trainer
					(*i)->wildNum(true);
				}	

			}
		}
    }
}

void Model::NewCommand(){
    char type;
    int id;
    double x_location;
    double y_location;

    cin>>type;
    if(cin.fail()){
        throw Invalid_Input("Enter a valid command!");
    }
    //checking if the inputed character is valid 
    switch(type){
        case 'c':
            break;
        case 'g':
            break;
        case 't':
            break;
        case 'w':
            break;
        default:
            throw Invalid_Input("Please enter a valid command!");
    }
    cin>>id;
    if (cin.fail()){
        throw Invalid_Input("Please enter a valid id number!");
    }
    //goes through each type to see if the id is already used
    //checking through pokemoncenter
    if (type=='c'){
        for(list<PokemonCenter*>::iterator i = center_ptrs.begin(); i!= center_ptrs.end(); i++){
			if((*i)->GetId() == id){
				throw Invalid_Input("That ID number is already in use!");
			}
		}
    //checking through pokemongym
	}else if(type=='g'){
        for(list<PokemonGym*>::iterator i = gym_ptrs.begin(); i!= gym_ptrs.end(); i++){
			if((*i)->GetId() == id){
				throw Invalid_Input("That ID number is already in use!");
			}
		}
    //checking through trainer
    }else if(type=='t'){
        for(list<Trainer*>::iterator i = trainer_ptrs.begin(); i!= trainer_ptrs.end(); i++){
			if((*i)->GetId() == id){
				throw Invalid_Input("That ID number is already in use!");
			}
		}
    //checking through wildpokemon
	}else if(type=='w'){
        for(list<WildPokemon*>::iterator i = wildpokemon_ptrs.begin(); i!= wildpokemon_ptrs.end(); i++){
			if((*i)->GetId() == id){
				throw Invalid_Input("That ID number is already in use!");
			}
		}
	}
    
    //checking if id is in between 1-9, if not it is an invalid ID
    if (id<1 || id>9){
        throw Invalid_Input("That is an invalid number for an ID!");
    }

    //get location of the new object using point2d
    x_location= input_double();
    y_location= input_double();
    Point2D new_location(x_location,y_location);

    switch (type){
        case 'c':{
            PokemonCenter*C= new PokemonCenter(id, 5.2, 100, new_location);
            center_ptrs.push_back(C);
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            center_count++;
            object_count++;
            break;
        }
        case 'g':{
            PokemonGym* G= new PokemonGym(10,1,2.0,3,id,new_location);
            gym_ptrs.push_back(G);
            object_ptrs.push_back(G);
            active_ptrs.push_back(G);
                 gym_count++;
                 object_count++;
            break;
            }
        case 't':{
            Trainer *T= new Trainer("TrainerExtra", id, 'T', 1.0, new_location);
            trainer_ptrs.push_back(T);
            object_ptrs.push_back(T);
            active_ptrs.push_back(T);
                 trainers_count++;
                 object_count++;
            break;
        }
        case 'w':{
            WildPokemon *W= new WildPokemon("WildPokemonExtra", 5.0, 2.0, false, id, new_location);
            wildpokemon_ptrs.push_back(W);
            object_ptrs.push_back(W);
            active_ptrs.push_back(W);
                object_count++;
                wildpokemon_count++;
            break;
        }
        default:
            throw Invalid_Input("Something went wrong!");
        }
    }

    
    
    //making sure the user inputs a double in order to get location 
    double input_double(){
        double num;
        if (!(cin>>num)){
            throw Invalid_Input("Error, needs to be a double!");
    }
    //based on board size since it is 20 by 20
        if (num<0){
        throw Invalid_Input("Error, needs to be a positive double!");
    }
        if (num>20){
        throw Invalid_Input("Error, coordinate is off the board!");
    }
        return num;
    }


    int input_int(){
        int num;
        if (!(cin>>num)){
            throw Invalid_Input("Error, need an integer!");
        }
        if (num<1){
            throw Invalid_Input("Error, needs to be a positive integer!");
        }
        return num;
    }

