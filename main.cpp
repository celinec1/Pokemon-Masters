#include <iostream>
#include "Trainer.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "GameCommand.h"
#include "Model.h"
#include "View.h"

using namespace std;
    int main(){
        srand(time(NULL));

        bool var= true;
        Model m1;
        View v1;
        int id1;
        int id2;
        unsigned int amt;
        double x_location;
        double y_location;
        Point2D point;
        m1.ShowStatus();
        v1.Clear();
        m1.Display(v1);
        char commands;


        while(var){
            bool content=true;
        do{
            try{
            cout << "Enter command: ";
            cin >> commands;
            if (cin.fail()){
                throw Invalid_Input("Invalid command");
            }

            switch (commands){
                case 'm':
                    id1=input_int();
                    x_location=input_double();
                    y_location=input_double();
                    point.x= x_location;
                    point.y= y_location;
                    DoMoveCommand(m1, id1, point);
                    //m1.ShowStatus();
                    // m1.Display(v1);
                    break;
                case 'c':
                    id1= input_int();
                    id2= input_int();
                    DoMoveToCenterCommand(m1, id1, id2);
                    //m1.ShowStatus();
                    // m1.Display(v1);
                    break;
                case 'g':
                    id1=input_int();
                    id2=input_int();
                    DoMoveToGymCommand(m1, id1, id2);
                    //m1.ShowStatus();
                    // m1.Display(v1);
                    break;
                case 's':
                    id1=input_int();
                    DoStopCommand(m1, id1);
                    //m1.ShowStatus();
                    //m1.Display(v1);
                    break;
                case 'p':
                    id1=input_int();
                    amt=input_int();
                    DoRecoverInCenterCommand(m1, id1, amt);
                    m1.ShowStatus();
                    m1.Display(v1);
                    break;
                case 'b':
                    id1=input_int();
                    amt=id1=input_int();
                    DoBattleCommand(m1, id1, amt);
                    //m1.ShowStatus();
                    //m1.Display(v1);
                    break;
                case 'q':
                    content=false;
                    var=false;
                case 'a':
                    var=false;
                    DoAdvanceCommand(m1, v1);
                    //m1.ShowStatus();
                    //m1.Display(v1);
                    break;
                case 'r':
                    var= false;
                    DoRunCommand(m1, v1);
                    //m1.ShowStatus();
                    //m1.Display(v1);
                    break;
                case 'n':
                    m1.NewCommand();
                    //m1.ShowStatus();
                    m1.Display(v1);
                    break;
                default:
                    cout << "Invalid input. Try again..." << endl;
                    throw("Please re-enter a valid code");
                }
            }
            catch(Invalid_Input & except){
                cout << "Invalid Input: "<< except.msg_ptr<<endl;
                cin.clear();
            }
        }
    while(content);
    }
return 0;
} 
  


