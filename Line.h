/*
Title : ADS Fina Project 
Course : CSIS217 Spring 21-22
Version Information : Apache NetBeans 12.0
Date :  April 21 2022
Author: Group of: Karim, Nael, Rafi, Wadih

--- Line.h -------------------------------------------------------------
    This header file defines a header for a Line data type.
    Basic operations:
 
 *   Constructors:
 
      Line():                                     Constructs a line with default values.
      Line(Point, Point):                         Constructs a line between 2 points and calculates the slope and intercept and whether the line is vertical.
      Line( bool, double, double):                Constructs a line with the intercept and slope given and whether the line is vertical or not.
      Line(&Line):                                Copy constructor.
 
 *   Methods:

      calculateSlope:                             Calculates the slope of a line based on the start and end points.
      generateLineFormula:                        Creates a Line formula using the start and end points coordinates and the line slope
                                                  to be as follows : y = mx + b.  (m is the slope).
      pointOfIntersection:                        Gets the intersection point between one line and another if it exists.
      onLine:                                     Checks if a point is on a line.
      intersects:                                 Checks if two lines can intersect or not. (If they're parallel or not).
      operator=:                                  Copies the line passed after the operator to this line.
      operator==:                                 Checks if two lines are equal.
      displayLine:                                Displays line equation and other information about the line.
      clone:                                      Copies a line passed as parameter to this line.

 *  Getters & Setters:
 
      getSlope, setSlope:                         Get and set the direction of the line.
      getIntercept, setIntercept:                 Get and set where the line intercepts with the Y axis.
      getXValue, setXValue:                       Get and set the xValue of a vertical line.
      isVertical, setVertical:                    Get and set if the line is vertical or not.
      getStartPoint, setStartPoint:               Get and set the start point of the line.
      getEndPoint, setEndPoint:                   Get and set the end point of a line.
 
 *   Class Variables:

      slope:                                      double equal to the difference between the y coordinates divided by that of the x 
                                                  coordinates of the line's points.
      intercept:                                  double that represents the intersection point between the line and the y - axis.
      xValue:                                     double that represents the intersection point between the line and the x - axis if line is vertical.
      vertical:                                   bool that tells if the line is vertical or not
      startPoint:                                 Point object, represents the start point of the line.
      endPoint:                                   Point object, represents the end point of the line.
      x:                                          double, used when getting the b value in a line formula.
      y:                                          double, used when getting the b value in a line formula.
      b:                                          double, represents the intercept between the line and the y - axis if it exists.
 */

#ifndef FINALADS_LINE_H
#define FINALADS_LINE_H

#include "Line.h"
#include "Point.h"
#include <iostream>
using namespace std;

class Line {

public:
    /***** Function Members *****/
    /***** Constructors *****/

    
    Line();
    /*------------------------------------------------------------------------
     Construct a line object with default values 0.
    
     Pre-Condition:  None.
     Post-Condition: Creates a line object with default values of 0
                     and start and end points at 0,0. Creates line equation.
     -----------------------------------------------------------------------*/
  
    Line(Point startPoint, Point endPoint);
    /*------------------------------------------------------------------------
     Constructs a Line object with the two start and end points,
     and calculates the line's slope, intercept, and whether the line is vertical.
    
     Pre-Condition:  receive two points.
     Post-Condition: Creates a line object with the start and end point parameters passed
                     and calculates all other values based on them and generates a line equation.
     -----------------------------------------------------------------------*/
    
    Line(bool vertical, double slope, double intercept);
    /*------------------------------------------------------------------------
     Constructs a line object with the parameters passed, no need to calculate anything
     as all value are given.
    
     Pre-Condition:  receive needed parameters.
     Post-Condition: Creates a line object using the parameters and generates a line equation.
     -----------------------------------------------------------------------*/
     
    Line(Line& Line);
    /*------------------------------------------------------------------------
     Copy constructor that creates a deep copy of the line object parameter in this object.
     Uses the method clone to do so.
    
     Pre-Condition:  receive line object to copy.
     Post-Condition: Creates a line object with the same values as the line object passed as parameter.
     -----------------------------------------------------------------------*/
     
    double calculateSlope();
    /*------------------------------------------------------------------------
     Method to calculate the slope of a line using the start and end points.
     
     Pre-Condition:  None.
     Post-Condition: Calculates the slope of a line and returns it.
     -----------------------------------------------------------------------*/
    
    string generateLineFormula();
    /*------------------------------------------------------------------------
     Creates the line's formula by using the line's slope and inserting start point's
     x and y in the y = mx + b equation to get b.

     Pre-Condition: None.
     Post-condition: Generates line equation : y = mx + b. m being the Line's slope and gets the
                     value of b.
     -----------------------------------------------------------------------*/
    
    Point* pointOfIntersection(Line& line);
    /*------------------------------------------------------------------------
      Returns the point of intersection between this line and the line passed
      as parameter if it exists.
    
     Pre-Condition:  receive Line object.
     Post-Condition: Returns a pointer to the point of intersection if it exists, otherwise
                     returns NULL.
     -----------------------------------------------------------------------*/
     
    bool operator==(Line& line);
    /*------------------------------------------------------------------------
      Tests if two lines are equal.
      Two lines are equal the starting and ending points of one line
      exist on the second one.

      Pre-Condition:  receive Line object.
      Post-Condition: Returns true if the two lines are equal (the same line), false otherwise.
     -----------------------------------------------------------------------*/
 
    void operator=(Line& line);
    /*------------------------------------------------------------------------
     Creates a deep copy the line after the operator to the one before it.

     Pre-Condition:  receive Line object.
     Post-Condition: Creates a deep copy of the line after the operator using the private clone method.
     -----------------------------------------------------------------------*/
    
    bool onLine(Point&);
    /*------------------------------------------------------------------------
     Checks if a point is on this line by using the line's equation and
     the point's x and y coordinates.

     Pre-Condition:  receive point object.
     Post-Condition: Returns true if the point is on the line, false otherwise.
     -----------------------------------------------------------------------*/
    
    bool intersects(Line& Line);
    /*------------------------------------------------------------------------
     Checks if two lines intersect.
     Two lines intersect if they both aren't vertical or if
     they aren't parallel (have different slopes).

     Pre-Condition: receive Line object.
     PostCondition: Returns true if the lines intersect, false otherwise.
     -----------------------------------------------------------------------*/
    
    void displayLine() const;
    /*------------------------------------------------------------------------
     Displays the line's start and end points, if the line is vertical
     is displays that it is and the xValue, if it isn't displays so and
     displays the line's slope and it's intercept.
     
     Pre-Condition: None.
     Post-Condition: Displays the Line's values.
     -----------------------------------------------------------------------*/


    /**** Getters and Setters ****/

    
    double getSlope() const;
    /*------------------------------------------------------------------------
     Gets the Slope of a Line.
     
     Pre-Condition: None.
     Post-Condition: Returns the Slope the line.
      -----------------------------------------------------------------------*/
    
    void setSlope(double slope);
    /*------------------------------------------------------------------------
     Sets the Slope of a Line.
     
     Pre-Condition: receive slope.
     Post-Condition: Sets the Slope the line.
      -----------------------------------------------------------------------*/
    
    double getIntercept() const;
    /*------------------------------------------------------------------------
     Gets the intercept of a Line with the y axis.   
     
     Pre-Condition: None.
     Post-Condition: returns a double value which is y in the point (0, y)
                     that is the interception if the line with the y - axis.
      -----------------------------------------------------------------------*/
    
    void setIntercept(double intercept);
    /*------------------------------------------------------------------------
     Sets the Intercept of a Line.
     
     Pre-Condition: Line isn't vertical, receive intercept.
     Post-Condition: Sets the intercept of a line.
     -----------------------------------------------------------------------*/
    
    double getXValue() const;
    /*------------------------------------------------------------------------
     Returns the xValue is the
     x coordinate of a vertical line.
     
     Pre-Condition: None.
     Post-Condition: Returns the x coordinate of a vertical line.
     -----------------------------------------------------------------------*/
    
    void setXValue(double xValue);
    /*------------------------------------------------------------------------
     Sets the xValue of a vertical line.

     Pre-Condition: Line is vertical (Vertical == true), receive xValue.
     Post-Condition: Sets the xValue of the line.
     -----------------------------------------------------------------------*/
    
    bool isVertical() const;
    /*------------------------------------------------------------------------
     Checks if the line is vertical.
    
     Pre-Condition: None.
     Post-Condition: Returns true if the line is vertical, false otherwise.
     -----------------------------------------------------------------------*/
    
    void setVertical(bool vertical);
    /*------------------------------------------------------------------------
     Sets if a line is vertical or not.
    
     Pre-Condition: receive vertical.
     Post-Condition: Sets the Vertical of the line.
     -----------------------------------------------------------------------*/
 
    const Point& getPoint1() const;
    /*------------------------------------------------------------------------
     Return reference to the start point of the line.
    
     Pre-Condition: None.
     Post-Condition: Returns a reference to the start point of the line.
     -----------------------------------------------------------------------*/
   
    void setPoint1(const Point& startPoint);
    /*------------------------------------------------------------------------
     Sets the start point of a line.
     
     Pre-Condition: receive point object.
     Post-Condition: Sets the start point of a line.
     -----------------------------------------------------------------------*/
   
    const Point& getPoint2() const;
    /*------------------------------------------------------------------------
     Return reference to the end point of the line.
     
     Pre-Condition: receive point object.
     Post-Condition: Returns a reference to the end point of the line.
     -----------------------------------------------------------------------*/

    void setPoint2(const Point& endPoint);
    /*------------------------------------------------------------------------
     Sets the end point of a line.

     Pre-Condition: None.
     Post-Condition: Sets the end point of a line.
     -----------------------------------------------------------------------*/

private:
    double slope,       //the direction of a line
        intercept,   //the intersection between a non-vertical line and the y-axis.
        xValue,      //the x coordinate of a vertical line.
        b;           //In a line equation y = mx + b. b is also the value of the intercept in a non-vertical line.

    string lineEquation; //line equation under the format y = slope * x + b.

    bool vertical;      //boolean value to check if the line is vertical or not

    Point point1,  
          point2;     //two points that belong the line
    Point* intersectionPoint;    //Pointer to a point that is the intersection point between this line and another

  /*------------------------------------------------------------------------
   Private method that copies the parameter line to this.
   
   Pre-Condition: None.
   Post-Condition: Creates a deep copy of the parameter object line to this line object.
   -----------------------------------------------------------------------*/
    void clone(Line& line);

};
/** operator<< as a non-friend, non-member function **/
ostream& operator<< (ostream& out, const Line&);

#endif //FINALADS_LINE_H
