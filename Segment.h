/*
 Title : ADS Fina Project 
Course : CSIS217 Spring 21-22
Version Information : Apache NetBeans 12.0
Date :  April 21 2022
Author: Group of: Karim, Nael, Rafi, Wadih

--- Segment.h -------------------------------------------------------------

    This header file defines a header for a Segment data type.
    Basic operations:
 
    Constructors:
 
      Segment():                                  Constructs a line with default values.
      Segment(Point, Point):                      Constructs a segment based on the two given points that represent the two extremities.
      Segment(&Segment):                          Copy constructor.

 *   Methods:
 
      operator=                                   Overloaded assignment operator
      operator==                                  Overloaded equalTo operator                                                 
      onSegmentInclusive                          Checks if a point is on a segment including its extremities
      onSegmentExclusive                          Checks if a point is on a segment excluding its extremities
      intersectsInclusive:                        Checks if a segment and a line or two segments intersect or not including intersection on extremities.
      intersectsExclusive:                        Checks if a segment and a line or two segments intersect or not excluding intersection on extremities.
      pointOfIntersection:                        return the point of intersection between a line and a segment or two segment inclusively
      sharePoint:                                 checks if two segment are connected from one side 
      shareSegment:                               checks if two points are the border of a segment
      getLength:                                  returns the length of a segment
      displaySegment:                             Displays segment start point, end point and length.
      clone:                                      Copies a segment passed as parameter to this segment.
 
 *   Getters & Setters:

      getPoint1, setPoint1:                       Get and set the first point of the segment
      getPoint2, setPoint2:                       Get and set the second point of the segment
      getSegmentLine:                             Get the line to which the segment belong to
 
 *   Class Variables
 
      point1:                                      point representing one extremity of the segment
      point2:                                      point representing the other extremity of a segment
      segmentLine:                                 the line which the segment is part of
 */
#ifndef ADSSFNP_SEGMENT_H
#define ADSSFNP_SEGMENT_H
#include "Line.h"

class Segment {

public:
    /***** Function Members *****/
    /***** Constructors *****/

    Segment();
    /*------------------------------------------------------------------------
      Construct a segment object with default values.
     
      Pre-Condition: None.
      Post-Condition: Creates a segment object with default point 0,0 and 1,1.
     -----------------------------------------------------------------------*/

    Segment(Point startPoint, Point endPoint);
    /*------------------------------------------------------------------------
      Construct a segment object with two given points.
     
      Pre-Condition: recieve two extremities as point object.
      Post-Condition: Creates a segment object with given point as extremities.
     -----------------------------------------------------------------------*/

    Segment(Segment &segment);
    /*------------------------------------------------------------------------
      Copy constructor
     
      Pre-Condition: receive segment to create a copy of.
      Post-Condition: Creates a copy of received segment.
     -----------------------------------------------------------------------*/




    void operator=(Segment& segment);
    /*------------------------------------------------------------------------
        Overloaded Assignment operator to make one segment equal to another.
     
      Pre-Condition: receive the segment object that is on the right hand side of
                     the operator.
      Post-Condition: set the extrimities of the segment to that of the given one.
     -----------------------------------------------------------------------*/

    bool operator==(Segment& segment);
    /*------------------------------------------------------------------------
       Overloaded equalTo operator to check if two segments are equal.
     
      Pre-Condition: receive the segment object that is on the right hand side of
                     the operator.
      Post-Condition: returns true if both segments have the same extremities esle false.
     -----------------------------------------------------------------------*/

    bool onSegmentInclusive(Point &point);
    /*------------------------------------------------------------------------
       Checks if a point is on a segment including its extremities
     
      Pre-Condition: receive the point object.
      Post-Condition: returns true if the point belongs to the segment including its 
                      extremities false otherwise.
     -----------------------------------------------------------------------*/

    bool onSegmentExclusive(Point &point);
    /*------------------------------------------------------------------------
       Checks if a point is on a segment excluding its extremities
     
      Pre-Condition: receive the point object.
      Post-Condition: returns true if the point belongs to the segment excluding its
                      extremities false otherwise.
     -----------------------------------------------------------------------*/

    bool intersectsInclusive(Line &line);
    /*------------------------------------------------------------------------
       Checks if a segment and a line intersect or not including intersection on extremities.
     
      Pre-Condition: receive the line object.
      Post-Condition: returns true if the line and segment intersect including extremities
                      false otherwise.
     -----------------------------------------------------------------------*/

    bool intersectsExclusive(Line &line);
    /*------------------------------------------------------------------------
       Checks if a segment and a line intersect or not excluding intersection on extremities.
     
      Pre-Condition: receive the line object.
      Post-Condition: returns true if the line and segment intersect excluding extremities
                      false otherwise.
     -----------------------------------------------------------------------*/

    bool intersectsInclusive(Segment &segment);
    /*------------------------------------------------------------------------
       Checks if a two segments intersect or not including intersection on extremities.
     
      Pre-Condition: receive the segment object.
      Post-Condition: returns true if the two segments intersect including extremities
                      false otherwise.
     -----------------------------------------------------------------------*/

    bool intersectsExclusive(Segment &segment);
    /*------------------------------------------------------------------------
       Checks if a two segments intersect or not excluding intersection on extremities.
     
      Pre-Condition: receive the segment object.
      Post-Condition: returns true if the two segments intersect excluding extremities
                      false otherwise.
     -----------------------------------------------------------------------*/

    Point* pointOfIntersection(Line &line);
    /*------------------------------------------------------------------------
       Return the point of intersection between a line and a segment.
     
      Pre-Condition: receive the line object.
      Post-Condition: returns a pointer to the point object representing the intersection if exsiting
                      Null otherwise.
     -----------------------------------------------------------------------*/
    Point* pointOfIntersection(Segment &segment);
    /*------------------------------------------------------------------------
       Return the point of intersection between two segments.
     
      Pre-Condition: receive the segment object.
      Post-Condition: returns a pointer to the point object representing the intersection if exsiting
                      Null otherwise.
     -----------------------------------------------------------------------*/

    bool sharePoint(Segment &segment);
    /*------------------------------------------------------------------------
       Checks if two segment are connected from one side 
     
      Pre-Condition: receive the segment object.
      Post-Condition: returns true if the two segments are connected
                      false otherwise.
     -----------------------------------------------------------------------*/

    bool shareSegment(Point& p1, Point& p2);
    /*------------------------------------------------------------------------
       Checks if two points are the border of a segment
     
      Pre-Condition: receive the two point objects.
      Post-Condition: returns true if the two points are the border of a segment.
                      false otherwise.
     -----------------------------------------------------------------------*/


    void displaySegment();
    /*------------------------------------------------------------------------
      Displays segment start point, end point and length.
     
      Pre-Condition: None.
      Post-Condition: Displays the segment values.
     -----------------------------------------------------------------------*/


    double getLength();
    /*------------------------------------------------------------------------
       Returns the length of a segment.
     
      Pre-Condition: none.
      Post-Condition: returns a double representing the length of a segment
     -----------------------------------------------------------------------*/


    const Point &getPoint1() const;
    /*------------------------------------------------------------------------
      Gets the first point of a segment.
     
      Pre-Condition: None.
      Post-Condition: Returns first point of a segment.
     -----------------------------------------------------------------------*/

    void setPoint1(const Point &point1);
    /*------------------------------------------------------------------------
      Sets the first point of a segment.
     
      Pre-Condition: receive a point object.
      Post-Condition: Sets first point of a segment.
     -----------------------------------------------------------------------*/

    const Point &getPoint2() const;
    /*------------------------------------------------------------------------
      Gets the second point of a segment.
     
      Pre-Condition: None.
      Post-Condition: Returns second point of a segment.
     -----------------------------------------------------------------------*/

    void setPoint2(const Point &point2) ;
    /*------------------------------------------------------------------------
    * Sets the second point of a segment.
     
      Pre-Condition: receive a point object.
      Post-Condition: Sets second point of a segment.
     -----------------------------------------------------------------------*/

     Line* getSegmentLine() ;
     /*------------------------------------------------------------------------
      Get the line to which the segment belong to.
     
      Pre-Condition: none.
      Post-Condition: return a line object representing the line to which the segment belongs to.
     -----------------------------------------------------------------------*/

private:
    Point point1, point2; //two extremities of a segment
    Line* segmentLine; //line to which the segment belongs to

    void clone(Segment &segment);
    /*------------------------------------------------------------------------
     Private method that copies the parameter of segment to this.
   
     Pre-Condition: receive segment.
     Post-Condition: Creates a deep copy of the parameter object segment to this segment object.
     -----------------------------------------------------------------------*/

};

ostream& operator<<(ostream &stream, Segment &segment);
#endif //ADSSFNP_SEGMENT_H
