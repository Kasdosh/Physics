#include "Point.h"

Point::Point()
	:Point(0, 0)
{
}

Point::Point(double x, double y)
{
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point& p)
	:Point(p.getX(),p.getY())
{}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

double Point::distance(const Point& other) const
{
	double distance = 0;
	distance = pow(this->getY() - other.getY(), 2);
	distance += pow(this->getX() - other.getX(), 2);
	distance = sqrt(distance);
	return distance;
}

double Point::incline(const Point& other) const
{
	double incline = 0;
	incline = (this->getY() - other.getY());
	incline /= (this->getX() - other.getX());
	return incline;
}

Point Point::findMid(const Point& other) const
{
	double x = this->getX() + other.getX();
	double y = this->getY() + other.getY();
	return Point(x / 2, y / 2);
}

std::string Point::toString() const
{
	return "(" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")";
}