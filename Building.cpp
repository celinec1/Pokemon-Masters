#include "Building.h"

//default constructor
Building::Building(): GameObject('B'){
    display_code='B';
    id_num=0;
    cout << "Building default constructed"<< endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc): GameObject(in_loc, in_Id,in_code){
    //in_Id=id_num;
    //location= in_loc;
    //display_code=in_code;
    state=0;
    cout<<"Building constructed"<< endl;
}
//adds a trainer
void Building::AddOneTrainer(){
    trainer_count+=1;
}
//removes a trainer
void Building::RemoveOneTrainer(){
    trainer_count-=1;
}
//prints out the information about number of trainers in the building
void Building::ShowStatus(){
    cout << display_code<< id_num<<" located at "<< location<<endl;
    if(trainer_count==1){
       cout<<trainer_count<<" trainer is in this building"<<endl;
    }else
        cout<<trainer_count<<" trainers is in this building"<<endl;
    }
bool Building::ShouldBeVisible(){
    return true;
}








