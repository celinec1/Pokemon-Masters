#ifndef POINT2D_H
#define POINT2D_H
#include "Vector2D.h"

#include <iostream>

using namespace std;

class Point2D{
public:
    double x;
    double y;
    Point2D();
    Point2D(double in_x, double in_y);


};

//Non-member functions 
double GetDistanceBetween(Point2D p1, Point2D p2);

//Overloaded operators 
ostream& operator << (ostream& left, const Point2D& right);
Point2D operator + (Point2D p1, Vector2D v1);
Vector2D operator- (Point2D p1, Point2D p2);
#endif
