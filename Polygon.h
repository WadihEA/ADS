/*
 Title : ADS Final Project 
Course : CSIS217 Spring 21-22
Version Information : Apache NetBeans 12.0
Date :  April 21 2022
Author: Group of: Karim, Nael, Rafi, Wadih

--- Polygon.h -------------------------------------------------------------

    This header file defines a header for a Polygon data type.
    Basic operations:
    
    Constructors:
 
      Polygon(Point, int):      Constructs a Polygon with Point array and size.
      Segment(&Polygon):        Copy constructor.
  

 * Methods:
        
        copy                    Copy Polygon
        getPoints               return Point array
        getSize                 return size
        sidesConstruct          Construct polygon sides using Point array
        Triangulate             Segmentation inside the Polygon
        AreaOfTriangle          Get area of a triangle in Polygon array
        getArea                 Get area of the full polygon
        displayPolygon          Display the points of the polygon
        operator<<
  
 * Class Variables
  
        points                  array of type Point
        sides                   array of type Segment
        polygons                array of type Polygon; triangles the polygon can be divided to
        numberOfPoints          int for number of points
        nbofPolygons            int for number of triangles the polygon can be divided to
            
 */
#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Segment.h"
#include "Line.h"
#include <iostream>
using namespace std;

class Polygon {
    
public:

    Polygon();
    /*------------------------------------------------------------------------
      Construct a polygon object with 0 values.

      Pre-Condition: None.
      Post-Condition: Creates a polygon object with no points.
     -----------------------------------------------------------------------*/


    Polygon(Point *points, int size);
    /*------------------------------------------------------------------------
      Construct a polygon object and sets parameters given, also calls
      sideConstruct method.
     
      Pre-Condition: Point array, int size.
      Post-Condition: Creates a polygon object given points.
     -----------------------------------------------------------------------*/

    Polygon(Polygon& orig);
    /*------------------------------------------------------------------------
      Copy constructor
     
      Pre-Condition: receive polygon to create a copy of.
      Post-Condition: Creates a copy of received polygon.
     -----------------------------------------------------------------------*/

    void copy(Polygon& Polygon);
    /*------------------------------------------------------------------------
     Private method that copies the parameter of polygon to this.
   
     Pre-Condition: receive polygon.
     Post-Condition: Creates a deep copy of the parameter object polygon to this segment object.
     -----------------------------------------------------------------------*/

    Point* getPoints();
    /*------------------------------------------------------------------------
       Returns the points array.
     
      Pre-Condition: none.
      Post-Condition: returns array of points
     -----------------------------------------------------------------------*/

    int getSize();
    /*------------------------------------------------------------------------
       Returns the size of the array.
     
      Pre-Condition: none.
      Post-Condition: returns size of the array
     -----------------------------------------------------------------------*/

    Segment* sidesConstruct();
    /*------------------------------------------------------------------------
       Construct the sides of the Polygon using points 
     
      Pre-Condition: receive array of points.
      Post-Condition: returns the the sides of the polygon in the sides array
     -----------------------------------------------------------------------*/

    Polygon *Triangulate();
    /*------------------------------------------------------------------------
       Divide the polygon into triangles 
     
      Pre-Condition: receive the array of segments.
      Post-Condition: returns the segments as an array of polygons.
     -----------------------------------------------------------------------*/

    double AreaOfTriangle(Polygon triangle); //calculate area of a segment/triangle
    /*------------------------------------------------------------------------
       Calculate the area of a selected triangle in the array 
     
      Pre-Condition: receives the polygons array.
      Post-Condition: returns the area of the triangle.
     -----------------------------------------------------------------------*/

    double getArea();
    /*------------------------------------------------------------------------
       Calculate the area of the polygon
     
      Pre-Condition: receives the polygons array.
      Post-Condition: returns the area of the polygon.
     -----------------------------------------------------------------------*/

    void displayPolygon(ostream& out);  //display polygon
    /*------------------------------------------------------------------------
      Displays polygon
     
      Pre-Condition: out stream.
      Post-Condition: Displays the polygon.
     -----------------------------------------------------------------------*/

   // ~Polygon();
    /*------------------------------------------------------------------------
      Destructor for the class polygon

      Pre-Condition: None.
      Post-Condition: Deletes all dynamically allocated memory variables.
     -----------------------------------------------------------------------*/

private:
    Point *points; //pointer to the dynamic array of Points representing the vertices of the polygon.
    Segment *sides; //pointer to the dynamic array of Segments representing the sides of the polygon.
    Polygon *polygons; //pointer to the dynamic array of Polygons
    int numberOfPoints; //integer representing the number of points of the polygon
    int numberOfPolygons; //number of polygons in array

};

#endif /* POLYGON_H */

/** operator<< as a non-friend, non-member function**/
ostream& operator<< (ostream& out, Polygon&);
