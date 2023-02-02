/**
 * Implementation of the Polygon member functions.
 */

#include <iostream>
#include <cmath>
#include "Polygon.h"
using namespace std;



Polygon::Polygon() {

}

/* With arg constructor for the Polygon */
Polygon::Polygon(Point* points, int size) {

    numberOfPoints = size;
    this->sides = new Segment[size];
    this->points = new Point[size];

    numberOfPolygons = size - 2;
    this->polygons = new Polygon[numberOfPolygons];

    for(int i = 0; i < size; i++){
        this->points[i] = points[i];
    }
    sidesConstruct();

}
/* Copy constructor */
Polygon::Polygon(Polygon& orig) {
    copy(orig);
}

/* Copy function */
void Polygon::copy(Polygon& polygon) {
    this->points = polygon.points;
    this->numberOfPoints = polygon.numberOfPoints;
    this->polygons = polygon.polygons;
    this->numberOfPolygons= polygon.numberOfPolygons;
    this->sides = polygon.sides;
}

/* Data member getter */
Point* Polygon::getPoints() {
    return points;
}

/* Data member getter */
int Polygon::getSize() {
    return numberOfPoints;
}

/* Construct the side of the Polygon using points */
Segment* Polygon::sidesConstruct() {
    Segment* segment;

    for (int i = 0; i < numberOfPoints; i++) {
        if ( i == ( numberOfPoints - 1 )) {
            segment = new Segment(points[i], points[0]);
            sides[i] = *segment;

        } else {
             segment = new Segment(points[i], points[i + 1]);
            sides[i] = *segment;
        }
    }
    return sides;
}

/* Divide Polygon into triangles */
Polygon* Polygon::Triangulate() {
    Point initial = points[0];
    Point* trianglePoints =  new Point[3];

    for (int i = 0; i < numberOfPoints - 1; i++) {

        trianglePoints[0] = initial;
        trianglePoints[1] = points[i];
        trianglePoints[2] = points[i + 1];

        Polygon* triangle = new Polygon(trianglePoints, 3);
        polygons[i] = *triangle;
        delete triangle;
    }

    return polygons;
}

/* Get Area of a Triangle */
double Polygon::AreaOfTriangle(Polygon triangle) {
    double a, b, c, s;
    a = triangle.sides[0].getLength();
    b = triangle.sides[1].getLength();
    c = triangle.sides[2].getLength();
    s = (a + b + c) / 2;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

/* Get Area of a Polygon */
double Polygon::getArea() {
    Triangulate();

    double area = 0;
    for (int i = 0; i <= numberOfPolygons; i++) {
        area += AreaOfTriangle(polygons[i]);
    }
    return area;
}

/* Display Polygon */
void Polygon::displayPolygon(ostream& out)  {
    cout << "Number of points in the polygon is " << numberOfPoints << endl;
    cout << "These points are " << endl;
    for (int i = 0; i < numberOfPoints; i++) {
        cout << points[i];
    }
    cout << "These points form the following sides " << endl;
    for (int i = 0; i < numberOfPoints; i++) {
        cout << sides[i];
    }

  cout << "The polygon's area is " << getArea() << endl;
}

ostream& operator<<(ostream& out, Polygon& p)
{
    p.displayPolygon(out);
    return out;
}

