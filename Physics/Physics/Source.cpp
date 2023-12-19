#include <iostream>
#include "Line.h"

#define PI 3.14159

using namespace std;

class Shape
{
private:
	
};

class body
{
private:
	
};

void createRectangle(Point& originVortex, double edgeLength, double angle = 0)
{
	Line ab = Line(originVortex, 0);

	Point b = Point();
}

int main()
{
	Point a = Point(4, 3);
	Point b = Point(6, 2);
	Line ab = Line(a, b);
	Line bc = Line(2, -10);
	Line ad = Line(-0.5, +5);
	Point c = bc.findPoint(b,b.distance(a));
	Point d = bc.findPoint(b,b.distance(a), false);
	std::cout << ad.getPointByX(ad.intersaction(bc)).toString() << std::endl;
	return 0;
}