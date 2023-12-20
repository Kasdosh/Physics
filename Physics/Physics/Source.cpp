#include <iostream>
#include "Line.h"
#include <chrono> 
#define PI 3.14159

using namespace std::chrono;
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
	double incline = 0;
	bool isVertical = false;
	std::cout << originVortex.toString() << std::endl;
	if (int(angle) % 180 == 90)
	{
		isVertical = true;
	}
	else 
	{
		incline = std::tan(angle);
	}
	Line ab = Line();
	if (!isVertical)
	{
		ab = Line(originVortex, incline);
	}
	else
	{
		ab = Line(originVortex);
	}
	std::cout << ab.toString() << std::endl;

	Line ad = ab.getPerpendicular(originVortex);
	std::cout << ad.toString() << std::endl;

	Point b = ab.findPoint(originVortex, edgeLength);
	std::cout << b.toString() << std::endl;

	Point d = ad.findPoint(originVortex, edgeLength);
	std::cout << d.toString() << std::endl;

	Line ac = ad.getPerpendicular(d);
	std::cout << ac.toString() << std::endl;

	Line bc = ab.getPerpendicular(b);
	std::cout << bc.toString() << std::endl;

	Point c = bc.findPoint(b, edgeLength);
	std::cout << c.toString() << std::endl;

	double x = originVortex.getX() + b.getX() + c.getX() + d.getX();
	double y = originVortex.getY() + b.getY() + c.getY() + d.getY();
	Point mid = Point(x/4,y/4);
	std::cout << mid.toString() << std::endl;

	double dst = ab.distance(mid);
	std::cout << dst << std::endl;
	dst = bc.distance(mid);
	std::cout << dst << std::endl;
	dst = ac.distance(mid);
	std::cout << dst << std::endl;

	dst = mid.distance(originVortex);
	std::cout << dst << std::endl;
	dst = mid.distance(b);
	std::cout << dst << std::endl;
	dst = mid.distance(c);
	std::cout << dst << std::endl;
}

int main()
{
	try 
	{
		Point a = Point(1, 1);
		auto start = high_resolution_clock::now();
		createRectangle(a, 5,15);
		createRectangle(a, 5,30);
		createRectangle(a, 5,45);
		createRectangle(a, 5,60);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << duration.count() << endl;
	}
	catch (const char* ex )
	{
		std::cout << ex;
	}
	return 0;
}