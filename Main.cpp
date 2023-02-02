/**
 * This project allows the user to create a polygon and display information about it
 * and get it's area size.
 *
 *  Project classes:
 *
 *          Point:                  Creates a point object.
 *
 *          Line:                   Creates a line object using Point class.
 *
 *          Segment:                Creates a segment object, uses the line and point classes.
 *
 *          Polygon:                Creates a polygon using the above classes.
 *
 *
 *  Project name: csis217FinalProject.
 *  Project authors: Karim, Nael, Rafi, Wadih.
 *  Project date: 5 / 4 / 2022.
 */
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Segment.h"
#include "Polygon.h"
using namespace std;

int main()
{
	Point p[] = {Point(1,1), Point(2,0), Point(4,0),Point(5,1),Point(4,4) };
	Polygon poly(p, 5);
    cout << poly;
}
