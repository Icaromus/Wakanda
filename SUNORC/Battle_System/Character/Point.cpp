#include <iostream>
#include <math.h>

using namespace std;

// Class to represent points.
class Point {
private:
	double xval, yval;
public:
	// Constructor uses default arguments to allow calling with zero, one,
	// or two values.
	Point(double x = 0.0, double y = 0.0) {
		xval = x;
		yval = y;
	}

	void operator = (int * coordList) // Overloading the assignment operator so that we can easily alter the Point's x and y values
	{
	    xval = coordList[0];  yval = coordList[1];
	}

	bool operator == (Point p)
	{
	    return (p.xval == xval && p.yval == yval);
	}

	// Extractors.
	double x() { return xval; }
	double y() { return yval; }

	// Distance to another point.  Pythagorean thm.
	double dist(Point other) {
		double xd = xval - other.xval;
		double yd = yval - other.yval;
		return sqrt(xd*xd + yd*yd);
	}

	// Add or subtract two points.
	Point add(Point b)
	{
		return Point(xval + b.xval, yval + b.yval);
	}
	Point sub(Point b)
	{
		return Point(xval - b.xval, yval - b.yval);
	}

	// Move the existing point.
	void move(double a, double b)
	{
		xval += a;
		yval += b;
	}

	// Print the point
	void print()
	{
		cout << "(" << xval << "," << yval << ")";
	}
};
