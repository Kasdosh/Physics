#include <iostream>
#include "Line.h"
#include <chrono> 

using namespace std::chrono;
using namespace std;

void createRectangle(Point& originVortex, double edgeLength, double angle = 0)
{
	double incline = 0;
	bool isVertical = false;
	std::cout << originVortex.toString() << std::endl;
	if (int(angle) % 180 == 90 || angle == 0)
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

void testRectangle()
{
	try
	{
		Point a = Point(0, 0);
		Point b = Point(4, 4);
		auto start = high_resolution_clock::now();
		createRectangle(a, 10);
		createRectangle(b, 10);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << duration.count() << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
}

void testRectangle2()
{
	try
	{
		auto start = high_resolution_clock::now();
		Point b = Point(4, 4);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "testRectangle2: " << duration.count() << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
}

void testRectangle3()
{
	try
	{
		auto start = high_resolution_clock::now();
		Point* b = new Point(4, 4);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "testRectangle3: " << duration.count() << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
}

void testRectangle4()
{
	try
	{
		auto start = high_resolution_clock::now();
		Point a = Point(4, 4);
		Point* b = new Point(4, 4);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "testRectangle4: " << duration.count() << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
}

int main()
{
	testRectangle2();
	testRectangle2();
	testRectangle3();
	testRectangle4();
	return 0;
}