#include "Vector2D.h"
#include <math.h>

    Vector2D:: Vector2D(){
        x=0;
        y=0;
}
    Vector2D:: Vector2D(double in_x, double in_y){
        x=in_x;
        y=in_y;
}

//Non-member functions
//Multiplication operator (v1*d)
    Vector2D operator* (Vector2D v1, double d){
        Vector2D result;
        result.x=v1.x*d;
        result.y=v1.y*d;
        return result;
 }

 //Division operator (v1/d)
    Vector2D operator/ (Vector2D v1, double d){
        Vector2D result; 
        result.x=v1.x/d;
        result.y=v1.y/d;
        return result; 
    }

//Stream output
    ostream& operator << (ostream& left, const Vector2D& right){
        left << "<" << right.x << "," << right.y << ">"<<endl;
        return left;
    }
