#include "Point2D.h"

#include <math.h>

    //Constructors
    //Default
    Point2D :: Point2D(){
        x=0.0;
        y=0.0;
    }
    Point2D:: Point2D(double in_x, double in_y){
        x=in_x;
        y=in_y;
    }
//Non-member functions
 
    double GetDistanceBetween(Point2D p1, Point2D p2){
        double newx= pow((p2.x - p1.x),2);
        double newy= pow((p2.y-p1.y),2);
        double result= sqrt(newx+newy);
        return result;
    }
//Addition operator: p1+v1
    Point2D operator + (Point2D p1, Vector2D v1){
        Point2D result;
        result.x= p1.x+v1.x;
        result.y= p1.y+v1.y;
        return result;
    }
//Subtraction operator: p1-p2
   Vector2D operator - (Point2D p1, Point2D p2){
        Vector2D result;
        result.x= p1.x-p2.x;
        result.y= p1.y-p2.y;
        return result;
    }
//Ostream operator
    ostream& operator << (ostream& left, const Point2D& right){
        left <<"("<<right.x << "," << right.y<<")";
        return left;
    }





