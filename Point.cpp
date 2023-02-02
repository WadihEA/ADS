
/*-- Point.cpp-----------------------------------------------------------

   This file implements point member functions.
-------------------------------------------------------------------------*/
#include "Point.h"
#include <iostream>
using namespace std;

//--- Definition of class no-arg constructor
Point::Point()
{
	Point(0, 0);
}

//--- Definition of class constructor
Point::Point(double x, double y)
{
	setX(x);
	setY(y);
}

//--- Definition of getX
double Point::getX() const
{
	return x;
}

//--- Definition of getY
double Point::getY() const
{
	return y;
}

//--- Definition of setX
void Point::setX(double x)
{
	this->x = x;
}

//--- Definition of setY
void Point::setY(double y)
{
	this->y = y;
}

//--- Definition of assignment operator
void Point::operator=(const Point& p)
{
	setX(p.x);
	setY(p.y);
}

//--- Definition of Equal to operator
bool Point::operator==(Point& p) const
{
	return (this->x == p.x && this->y == p.y); 
}
//--- Definition of inRangeInclusive
bool Point::inRangeInclusive(Point& p1, Point& p2) const
{
	double greatestX,
		   lowestX, 
		   greatestY, 
		   lowestY;
	if (p1.x > p2.x) {
		greatestX = p1.x;
		lowestX = p2.x;
	}
	else {
		greatestX = p2.x;
		lowestX = p1.x;
	}
	if (p1.y > p2.y) {
		greatestY = p1.y;
		lowestY = p2.y;
	}
	else {
		greatestY = p2.y;
		lowestY = p1.y;
	} //get the value of the broders of the rectangles

	if (this->x >= lowestX && this->x <= greatestX && this->x >= lowestY && this->x <= greatestY) //check if point is inside or on the borders
		return true;
	return false;
}
//--- Definition of inRangeExclusive
bool Point::inRangeExclusive(Point& p1, Point& p2) const
{
	double greatestX,
		lowestX,
		greatestY,
		lowestY;
	if (p1.x > p2.x) {
		greatestX = p1.x;
		lowestX = p2.x;
	}
	else {
		greatestX = p2.x;
		lowestX = p1.x;
	}
	if (p1.y > p2.y) {
		greatestY = p1.y;
		lowestY = p2.y;
	}
	else {
		greatestY = p2.y;
		lowestY = p1.y;
	}
	//get the the values of the borders of the rectangle
	if (this->x > lowestX && this->x < greatestX && this->x > lowestY && this->x < greatestY) //check if point is strictly inside the borders
		return true;
	return false;
}


//--- Definition of displayPoint
void Point::displayPoint(ostream& out) const
{
	out << "x is: " << x << " y is: " << y <<endl;
}

//--- Definition of output operator
ostream& operator<<(ostream& out, const Point& p)
{
	p.displayPoint(out);
	return out;
}
