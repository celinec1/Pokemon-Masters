#include "GameCommand.h"
#include <iostream>

using namespace std;
 
//in main when command is 'm' it will go through this function
void DoMoveCommand(Model &model, int trainer_id, Point2D p1){
    if (model.GetTrainerPtr(trainer_id)==0){
        cout<<"Error: Please enter a valid command!"<<endl;
        return;
    }else{
        //it will move the trainer
        model.GetTrainerPtr(trainer_id)->StartMoving(p1);
        cout<<"Moving "<< model.GetTrainerPtr(trainer_id)->GetName()<<" to "<<p1<<endl;
    }
}
//in main when command is 'c' it will go through this function
void DoMoveToCenterCommand(Model &model, int trainer_id, int center_id){
    if (model.GetPokemonCenterPtr(center_id)==0 || model.GetTrainerPtr(trainer_id)==0){
        cout<<"Error: Please enter a valid command!"<<endl;
        return;
    }else{
        //it will start to move the trainer to the requested center
        model.GetTrainerPtr(trainer_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout<<"Moving "<<model.GetTrainerPtr(trainer_id)->GetName()<<" to center "<< model.GetPokemonCenterPtr(center_id)->GetId()<<endl;
    }
}
//in main when command is 'g' it will go through this function
void DoMoveToGymCommand(Model &model, int trainer_id, int gym_id){
    if (model.GetPokemonGymPtr(gym_id)==0 || model.GetTrainerPtr(trainer_id)==0){
        cout<<"Error: Please enter a valid command!"<<endl;
        return;
    }else{
        //it will start to move the trainer to the requested gym
        model.GetTrainerPtr(trainer_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
        cout<<"Moving "<<model.GetTrainerPtr(trainer_id)->GetName()<<" to gym "<< model.GetPokemonGymPtr(gym_id)->GetId()<<endl;
    }
}
//in main when command is 's' it will go through this function
void DoStopCommand(Model &model, int trainer_id){
    if (model.GetTrainerPtr(trainer_id)==0){
        cout<< "Error: Please enter a valid command!"<<endl;
        return;
    }else{
        //the trainer will stop
        model.GetTrainerPtr(trainer_id)->Stop();
        cout<<"Stopping "<< model.GetTrainerPtr(trainer_id)->GetName()<<endl;
    }
}
//in main when command is 'b' it will go through this function
void DoBattleCommand(Model &model, int trainer_id, unsigned int battles){
    if (model.GetTrainerPtr(trainer_id)==0){
        cout<<"Error: Please enter a valid command!"<<endl;
        return;
    }
    //the trainer will be able to battle--only if it is in the gym, this will be checked in the trainer class
    model.GetTrainerPtr(trainer_id)->StartBattling(battles);
    cout<<model.GetTrainerPtr(trainer_id)->GetName()<<" is battling "<<endl;
}
//in main when command is 'p' it will go through this function
void DoRecoverInCenterCommand(Model &model, int trainer_id, unsigned int potions_needed){
    
    if (model.GetTrainerPtr(trainer_id)==0){
        cout<< "Error! Please enter a valid command"<<endl;
        return;
    }else{
        //the trainer will be able to buy potions--only if it is in the center, this will be checked in the trainer class
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);
        cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetName() << "'s Pokemon's health"<< endl;
    }
}
//in main when command is 'a' it will go through this function
//this will advance one-time step and update the objects
void DoAdvanceCommand(Model &model, View &view){
    bool advance=model.Update();
    model.ShowStatus();
    //view.Clear();
    model.Display(view);
    //view.Draw();
    cout << "Advancing one tick." << endl;

}
//in main when command is 'a' it will go through this function
//this will advance until the update function returns true for one of the objects
void DoRunCommand(Model &model, View &view){
    bool advance=false;
    cout << "Advancing to next event." << endl;
    while (!advance){
        advance=model.Update();
        model.ShowStatus();
        //view.Clear();
        model.Display(view);
        //view.Draw();
    
}
}
