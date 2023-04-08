#include "GameObject.h"
#include <iostream>
#include <math.h>

using namespace std;
//made a default construcot in order for the code to not have a linker issue when I compiled. Essentially it does nothing.
GameObject::GameObject(){
    //nothing
}

GameObject::GameObject(char in_code){
    display_code=in_code;
    id_num=1;
    state=0;
    cout<<"GameObject constructed"<<endl;
}
GameObject::GameObject(Point2D in_loc,int in_id,char in_code){
    id_num=in_id;
    display_code=in_code;
    location=in_loc;
    state=0;
    cout<<"GameObject constructed"<<endl;
    
}
Point2D GameObject :: GetLocation(){
    return location;
}
bool GameObject::Update(){
    return false;
}
int GameObject::GetId(){
    return id_num;
}
char GameObject::GetState(){
    return state;
}
void GameObject::ShowStatus(){
    cout<<display_code<<" "<<id_num<< " at "<<location<<endl;
}
//This function is used in model and view when making the grid of the game
void GameObject::DrawSelf(char* ptr){
    *ptr=display_code;
    *(ptr+1)=('0'+id_num);
}

char GameObject::GetDisplayCode(){
    return display_code;
}
//destructor
GameObject::~GameObject(){
        cout<<"GameObject destructed"<<endl;
};




