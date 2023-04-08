#include "View.h"
#include <iostream>

using namespace std;

//default constructor
View::View(){
    size=11;
    scale=2;
    origin=Point2D();
}

void View::Clear(){
    for (int i=0; i<size;i++){
        for (int j=0;j<size;j++){
            grid[i][j][0]='.';
            grid[i][j][1]=' ';
        }
    }
}

//it plots the objects on the graph using getsubscript and drawself
void View::Plot(GameObject *ptr){
    int i;
    int j;
    if (!GetSubscripts(i,j,ptr->GetLocation())){
        return;
    }else if (grid[i][j][0]=='.'){
        if(ptr->ShouldBeVisible()){
            ptr->DrawSelf(grid[i][j]);
        }
    }else{
        grid[i][j][0]='*';
        grid[i][j][1]=' ';
    }
}
//this outputs the grid array and is the visuals for the game
void View::Draw()
{
    for (int i = size-1; i >= -1; i--){
        for (int j = -1; j <= size-1; j++){
//grid axis
            if (j == -1 && i%2 == 0){
                cout << i*2;
                if (i/5 == 0){
                    cout << " ";
            }
            }else if (j == -1 && i%2 != 0){
                cout << " ";
            }else if (i == -1 && j%2 == 0){
                cout << j*2;
                    if (j/5 == 0){
                        cout << " ";
                    }
                cout << " ";
             }
//draw objects
            if (j >= 0 && i >=0){
                cout << grid[j][i][0] << grid[j][i][1];
            }
        }
        cout << endl;
    }
}
//this will scale the grid and display if the objects are out of bound
bool View::GetSubscripts(int &out_x, int &out_y,Point2D location){
    out_x=int((location.x-origin.x)/scale);
    out_y=int((location.y-origin.y)/scale);
    if (out_y <= size || out_y<=size){
        return true;
    }else{
        cout<<"An object is outside the display"<<endl;
        return false;
    }
}
