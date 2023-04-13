#ifndef BUILDING_H
#define BUILDING_H
#include "Point2D.h"
#include "GameObject.h"

#include <iostream>
using namespace std;

class Building: public GameObject{
private:
    unsigned int trainer_count=0;

public:
    Building();
    Building(char in_code, int in_Id, Point2D in_loc);
    void AddOneTrainer();
    void RemoveOneTrainer();
    void ShowStatus();
    bool ShouldBeVisible();


};

#endif
