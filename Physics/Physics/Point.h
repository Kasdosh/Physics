#pragma once
#include <math.h>
#include <string>

class Point {
public:
	Point();
	Point(double x, double y);
	Point(const Point& p);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double distance(const Point& other) const;
	double incline(const Point& other) const;
	Point findMid(const Point& other) const;
	std::string toString() const;
private:
	double x;
	double y;
};