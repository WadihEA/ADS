/*
Title : ADS Fina Project 
Course : CSIS217 Spring 21-22
Version Information : Apache NetBeans 12.0
Date :  April 21 2022
Author: Group of: Karim, Nael, Rafi, Wadih

--- Point.h -------------------------------------------------------------
  This header file defines a header for a Point data type.
  Basic operations:
    constructors:     Constructs an Point object
    getX:             Get the abscissa of a point 
    getY:             Get the ordinate of a point 
    setX:             Set the abscissa of a point 
    setY:             Set the ordinate of a point 
    =:                Overloaded assignment operator
    == :              Overloaded Equal to operator
    inRangeInclusive: Check if a point is situated between two other inluding borders
    inRangeExclusive: Check if a point is situated between two other excluding borders
    displayPoint:	  Displays a point
--------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#ifndef POINT_H
#define POINT_H

class Point {
public:
    /***** Function Members *****/
    /***** Constructors *****/
    Point();
    /*------------------------------------------------------------------------
    Construct a Point object.

     Precondition:  None.
     Postcondition: A Point object has been constructed with default 0, 0 
     coordinates.
     -----------------------------------------------------------------------*/

    Point(double, double);
    /*------------------------------------------------------------------------
    Construct a Point object.

     Precondition:  None.
     Postcondition: A Point object has been constructed with given coordinates
     values.
    ---------------------------------------------------------------------*/

    double getX() const;
    /*------------------------------------------------------------------------
    Get the abscissa of a point .

     Precondition:  None.
     Postcondition: Return a double representing the abscissa of the point.
    ---------------------------------------------------------------------*/

    double getY() const;
    /*------------------------------------------------------------------------
    Get the ordinate of a point .

     Precondition:  None.
     Postcondition: Return a double representing the ordinate of the point.
    ---------------------------------------------------------------------*/

    void setX(double);
    /*------------------------------------------------------------------------
    Set the abscissa of a point .

     Precondition:  receive the value to set as abscissa.
     Postcondition: Set the abscissa of the point to the given value.
    ---------------------------------------------------------------------*/

    void setY(double);
    /*------------------------------------------------------------------------
    Set the ordinate of a point .

     Precondition:  receive the value to set as ordinate.
     Postcondition: Set the ordinate of the point to the given value.
    ---------------------------------------------------------------------*/

    void operator=(const Point&);
    /*------------------------------------------------------------------------
     Overloaded Equal operator to make one point equal to another.

     Precondition:  receive the point object that is on the right hand side of
     the operator.
     Postcondition: Set the ordinate and abscissa of the point to that of the 
     given point.
    ---------------------------------------------------------------------*/

    bool operator== (Point&) const;
    /*------------------------------------------------------------------------
     Overloaded assignment to operator to check if two ponits are equal.

     Precondition:  receive the point object that is on the right hand side of 
     the operator.
     Postcondition: check if the ordinate and abscissa of the point are equal 
     to that of the given point.
    ---------------------------------------------------------------------*/

    bool inRangeInclusive(Point&, Point&) const;
    /*------------------------------------------------------------------------
     Check if a point is situated between two other including borders

     Precondition:  receive the two point objects that will serve as opposite
     vertices in a rectangle. 
     Postcondition: check if the point is situated inside or on the borders 
     of said rectangle.
    ---------------------------------------------------------------------*/

    bool inRangeExclusive(Point&, Point&) const;
    /*------------------------------------------------------------------------
     Check if a point is situated between two other excluding borders

     Precondition:  receive the two point objects that will serve as opposite 
     vertices in a rectangle.
     Postcondition: check if the point is situated strictly inside of said 
     rectangle.
    ---------------------------------------------------------------------*/

    void displayPoint(ostream& out) const;
    /*----------------------------------------------------------------------
     Display a point.

     Precondition:  The ostream out is open.
     Postcondition: The point is displayed.
   -----------------------------------------------------------------------*/

private:
    double x; //double representing the abscissa of a point
    double y; //double representing the ordinate of a point
}; 

#endif /* POINT_H */
/** operator<< as a non-friend, non-member function**/
ostream& operator<< (ostream& out, const Point&);
