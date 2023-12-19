#pragma once

#include "Point.h"

class Line
{
public:
	Line();
	Line(const Point& a, const Point& b);
	Line(const double m, const double b, const bool isVertical = false);
	Line(const double b);
	Line(const Point& a, const double m);
	Line(const Line& line);
	double getM() const;
	double getB() const;
	bool getIsVertical() const;
	void setM(double m);
	void setB(double b);
	double distance(const Point& p) const;
	const Point getPointByX(const double x) const;
	const Point getPointByY(const double y) const;
	const double isIntersacting(const Point& p) const;
	const bool isIntersacting(const Line& line) const;
	const double intersaction(const Line& line) const;
	Point findPoint(const Point& p, const double distance, const bool first = true) const;
	std::string toString() const;
private:
	double m;
	double b;
	bool isVertical;
};