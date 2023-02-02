/**
 * Implementation of the Segment member functions.
 */
#include "Segment.h"
#include "Point.h"
#include"Line.h"
#include <math.h>

 /**
  * No-arg constructor.
  */
Segment::Segment() {

    Segment(Point(0, 0), Point(1, 1));
}

/**
 * Constructor with 2 parameters.
 */
Segment::Segment(Point startPoint, Point endPoint) {
    setPoint1(startPoint);
    setPoint2(endPoint);
    segmentLine = new Line(point1, point2);
}

/**
 * Copy constructor. Calls private method clone.
 */
Segment::Segment(Segment &segment) {
    clone(segment);
}

/**
 * Overloaded operator= that creates a deep copy of the segment after
 * the parameter in this segment object.
 */
void Segment::operator=(Segment& segment)
{
    clone(segment);
}

/**
 * Overloaded operator== that tests if two segments are equal.
 */
bool Segment::operator==(Segment& segment)
{
    if (point1 == segment.point1 && point2 == segment.point2) {
        return true;
    }
    return false;
}


bool Segment::onSegmentInclusive(Point &point) {

    double distanceStartEnd,    //distance from 2 extremities
           distancePointStart,  //distance from point to first extremity
           distancePointEnd;    //distance from point to other extremity

    distanceStartEnd = getLength();

    double dspX = point.getX() - point1.getX();
    double dspY = point.getY() - point1.getY();
    double dsp = ( dspX * dspX ) + ( dspY * dspY );

    distancePointStart = sqrt(dsp); 

    double depX = point.getX() - point2.getX();
    double depY = point.getY() - point2.getY();
    double dep = ( depX * depX ) + ( depY * depY );

    distancePointEnd = sqrt(dep); 

    //check if distance for both extremities to the point is equal to the length of the segment
    return distancePointStart + distancePointEnd == distanceStartEnd; 
}

bool Segment::onSegmentExclusive(Point &point) {

    double distanceStartEnd,    //distance from 2 extremities
            distancePointStart, //distance from point to first extremity
            distancePointEnd;   //distance from point to other extremity


    distanceStartEnd = getLength();

    double dspX = point.getX() - point1.getX();
    double dspY = point.getY() - point1.getY();
    double dsp = ( dspX * dspX ) + ( dspY * dspY );

    distancePointStart = sqrt(dsp);

    double depX = point.getX() - point2.getX();
    double depY = point.getY() - point2.getY();
    double dep = ( depX * depX ) + ( depY * depY );

    distancePointEnd = sqrt(dep);

    if(distancePointStart == 0 || distancePointEnd == 0){
        return false;
    } //check that extremities are excluded

    //check if distance for both extremities to the point is equal to the length of the segment
    return distancePointStart + distancePointEnd == distanceStartEnd;
}


bool Segment::intersectsInclusive(Line &line) {

    if(line.intersects(*segmentLine)){ //check if both line intersect

       Point* intersectionPoint = line.pointOfIntersection(*segmentLine); //get intersection

       if(onSegmentInclusive(*intersectionPoint)){ //check if point of intersection belongs to the segment
           return true;
       }else{
           return false;
       }

    }else{
        return false;
    }
}


bool Segment::intersectsExclusive(Line &line) {

    if(line.intersects(*segmentLine)){ //check if both line intersect

        Point* intersectionPoint = line.pointOfIntersection(*segmentLine); //get intersection

        if(onSegmentExclusive(*intersectionPoint)){ //check if point of intersection belongs to the segment
            return true;
        }else{
            return false;
        }

    }else{
        return false;
    }

}

bool Segment::intersectsInclusive(Segment &segment) {
    if (segment.getSegmentLine()->intersects(*segmentLine)) { //check if both line intersect
        Point *intersectionPoint = segment.pointOfIntersection(*segmentLine); //get intersection

        if (intersectionPoint != NULL) {
            if (onSegmentInclusive(*intersectionPoint)) { //check if point of intersection belongs to the segment
                return true;
            } else {
                return false;
            }

        }else {
            return false;
        }

    }else{
        return false;
    }
}

bool Segment::intersectsExclusive(Segment &segment) {
    if(segment.getSegmentLine()->intersects(*segmentLine)){ //check if both line intersect

        Point* intersectionPoint = segment.pointOfIntersection(*segmentLine); //get intersection

        if(intersectionPoint != NULL){
             
            if(onSegmentExclusive(*intersectionPoint)){ //check if point of intersection belongs to the segment
                return true;
            }else{
                return false;
            }

        }else{
            return false;
        }

    }else{
        return false;
    }
}


Point *Segment::pointOfIntersection(Segment &segment) {

    if(segment.getSegmentLine()->intersects(*segmentLine)){ //check if both line intersect
        Point* pointOfIntersection =  segmentLine->pointOfIntersection(*segment.getSegmentLine()); //get intersection

        if(pointOfIntersection == NULL) { 
            return NULL; 
        }

        if(onSegmentInclusive(*pointOfIntersection) && segment.onSegmentInclusive(*pointOfIntersection)){ //check if point of intersection belongs to the segment
            return  pointOfIntersection;
        }else{
            return NULL;
        }

    }else{
        return NULL;
    }
}

Point *Segment::pointOfIntersection(Line &line) {

    if(line.intersects(*segmentLine)){ //check if both line intersect
        Point* pointOfIntersection = line.pointOfIntersection(*segmentLine);  //get intersection

        if(pointOfIntersection == NULL){
            return NULL;
        }

        if(onSegmentInclusive(*pointOfIntersection) ){ //check if point of intersection belongs to the segment
            return  pointOfIntersection;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}

double Segment::getLength(){
    double dseX = point2.getX() - point1.getX();
    double dseY = point2.getY() - point1.getY();
    double dse = ( dseX * dseX ) + ( dseY * dseY ); //distance between two points using pythagor theorem

    return sqrt(dse);
}


bool Segment::sharePoint(Segment &segment) {

    if(point1 == segment.point1 || point1 == segment.point2 ||
       point2 == segment.point1 || point2 == segment.point2 ){
        return true; //check if two segments have a similar extremity
    }else{
        return false;
    }
}

bool Segment::shareSegment(Point &p1, Point &p2) {
    if(point1 == p1 && point2 == p2 ||
       point1 == p2 && point2 == p1 ){
        return true; //check if two point are the borders of a segment
    }else{
        return false;
    }
}

void Segment::clone(Segment &segment) {
    setPoint1(segment.point1);
    setPoint2(segment.point2);
    segmentLine = segment.getSegmentLine();
}

const Point &Segment::getPoint1() const {
    return point1;
}

void Segment::setPoint1(const Point &point1) {
    Segment::point1 = point1;
}

const Point &Segment::getPoint2() const {
    return point2;
}

void Segment::setPoint2(const Point &point2) {
    Segment::point2 = point2;
}

Line* Segment::getSegmentLine() {
    return segmentLine;
}

ostream& operator<<(ostream& ostream, Segment& segment){

    cout << "Segment start point: " << segment.getPoint1() << "Segment Point 2: " << segment.getPoint2() <<
    "Segment length: " << segment.getLength() << endl;
    return ostream;
}