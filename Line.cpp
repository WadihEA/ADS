/**
 * Implementation of the Line member functions.
 */
#include "Line.h"
#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;
 /**
  * No-arg constructor.
  */
Line::Line() {
    Line(Point(), Point(0, 1)); //creates y_axis line*/
}

/**
 * Constructor with 2 parameters.
 */
Line::Line(Point firstPoint, Point secondPoint) {

    setPoint1(firstPoint);      //set start and points
    setPoint2(secondPoint);
    setSlope(calculateSlope());     //calculate the slope and set the slope variable to it

    lineEquation = generateLineFormula();   //get line equation under the format y = slope x + b;

    if (slope == 0) {         //if the slope is 0 then the line is vertical
        Line(true, slope, 0);
    }
    else {
        Line(false, slope, b);
    }
}
/**
 * 3 parameter constructor.
 */
Line::Line(bool vertical, double slope, double intercept) {
    setVertical(vertical);
    setSlope(slope);
    setIntercept(intercept);
    if (vertical) {
        setXValue(point1.getX());
    }
    else {
        setXValue(0);
    }
    lineEquation = generateLineFormula();
}

/**
 * Copy constructor. Calls private method clone.
 */
Line::Line(Line& line) {
    clone(line);
}

/**
 * Generate line equation.
 */
string Line::generateLineFormula() {
    b = point1.getY() - (slope * point1.getX());            //y = mx +b;
                                                                    // b = y - mx;  (m being the slope).
    string eq = "To String error";// +to_string(slope) + " x + " + to_string(b);    //create equation as a string.
    
    return eq;
}


/**
 * Calculates slope value of line.
 */
double Line::calculateSlope() {

    double rise = (point2.getY() - point1.getY());    // rise is the difference between the y coordinates of the two end points of the line.
    double run = (point2.getX() - point1.getX());     // run is the difference between the x coordinates of the two end points of the line.

    if (run == 0) {
        return 0;   //line is vertical if the difference between the x coordinates of the two end points is 0.
    }

    double slope = rise / run;  // the slope is the rise divided by the run
    return slope;
}

/**
 * Checks if point is on the line.
 */
bool Line::onLine(Point& point) {

    //if point's coordinates satisfy the line equation of y = mx + b with a 0.000001 error margin
    if (point.getY() == (slope * point.getX() + b) ||
        point.getY() == (slope * point.getX() + b - 0.000001) ||
        point.getY() == (slope * point.getX() + b + 0.000001)) {
        return true;
    }
    else {
        return false;
    }

}
/**
 * Checks if this line intersects with another.
 */
bool Line::intersects(Line& line) {
    if (this->vertical && line.vertical || this->slope == line.slope) { // if both lines are vertical or if their slopes are equal
        if (this->operator==(line)) {
            return true;
        }
        return false;
    }
    else {
        return true;
    }
}

/**
 * Gets the point of intersection between two lines if it exists.
 *
 * The two line equations are under the format y = mx + b;
 * we set the two equations to be equal ( substitute the value of first
 * y in place of y in the second equation ), by doing doing that we get the
 * x coordinate of the intersection point. We then substitute the x value
 * in the first line's equation ( y  = slope * x + b) to get the y coordinate of
 * the intersection point.
 */
Point* Line::pointOfIntersection(Line& line) {

    if (intersects(line)) {
        double x = (line.b + (this->b * -1)) / (this->getSlope() + (line.getSlope() * -1));
        double y = this->getSlope() * x + b;

        intersectionPoint = new Point(x, y);

        return intersectionPoint;

    }
    else {
        return NULL;
    }
}

/**
 * Copies a line.
 */
void Line::clone(Line& line) {
    this->setPoint1(line.getPoint1());
    this->setPoint2(line.getPoint2());
    this->setIntercept(line.getIntercept());
    this->setVertical(line.isVertical());
    this->setSlope(line.getSlope());
    this->setXValue(line.getXValue());
}

/**
 * Display line.
 */
void Line::displayLine() const {

    cout << "Line equation is " << lineEquation << "\n, Start point : " << point1 << ", end point : " << point2;

    if (vertical) {
        cout << "\nLine is Vertical, xValue = " << xValue;
    }
    else {
        cout << "\nLine isn't vertical, slope = " << slope << ", intercept = " << intercept;
    }
}

/**
 * Return slope of the line.
 */
double Line::getSlope() const {
    return slope;
}

/**
 * Set slope of the line.
 */
void Line::setSlope(double slope) {
    Line::slope = slope;
}

/**
 * Returns intercept of a line with the y axis.
 */
double Line::getIntercept() const {
    return intercept;
}

/**
 * Set intercept of a line with the y axis.
 */
void Line::setIntercept(double intercept) {
    Line::intercept = intercept;
}

/**
 * Returns the xValue of a vertical line.
 */
double Line::getXValue() const {
    return xValue;
}

/**
 * Sets the xValue of a vertical line.
 */
void Line::setXValue(double xValue) {
    Line::xValue = xValue;
}

/**
 * Returns a boolean indicating if the line is vertical or not.
 */
bool Line::isVertical() const {
    return vertical;
}
/**
 * Sets the boolean vertical.
 */
void Line::setVertical(bool vertical) {
    Line::vertical = vertical;
}

/**
 * Returns reference to the start point of the line.
 */
const Point& Line::getPoint1() const {
    return point1;
}

/**
 * Sets the start point of the line.
 */
void Line::setPoint1(const Point& startPoint) {
    Line::point1 = startPoint;
}

/**
 * Returns reference to the end point of the line.
 */
const Point& Line::getPoint2() const {
    return point2;
}

/**
 * Sets the end point of a line.
 */
void Line::setPoint2(const Point& endPoint) {
    Line::point2 = endPoint;
}

/**
 * Overloaded operator= that creates a deep copy of the line after
 * the parameter in this line object.
 */
void Line::operator=(Line& line) {
    clone(line);
}

/**
 * Overloaded operator== that tests if two lines are equal.
 */
bool Line::operator==(Line& line) {
    if (onLine(line.point1) && onLine(line.point2)) {
        return true;
    }
    else {
        return false;
    }
}
/**
 * Displays the line.
 */
ostream& operator<< (ostream& out, const Line& line) {
    line.displayLine();
    return out;
}