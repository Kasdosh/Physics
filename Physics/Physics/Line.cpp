#include "Line.h"

Line::Line()
	:Line(0,0)
{
}

Line::Line(const Point& a, const Point& b)
{
	this->setM(a.incline(b));
	if (a.getX() == 0)
	{
		this->setB(a.getY());
	}
	else if (b.getX() == 0)
	{
		this->setB(b.getY());
	}
	else
	{
		this->setB(a.getY() - (a.incline(b) * a.getX()));
	}
		
}

Line::Line(const double m, const double b, const bool isVertical)
{
	this->setB(b);
	this->setM(m);
	this->isVertical = isVertical;
}

Line::Line(const double b)
	:Line(0,b,true)
{
}

Line::Line(const Point& a, const double m)
{
	this->setM(m);
	this->setB(a.getY()-m*a.getX());
}

Line::Line(const Line& line)
	:Line(line.getM(), line.getB(), line.getIsVertical())
{}

double Line::getM() const
{
	return this->m;
}

double Line::getB() const
{
	return this->b;
}

bool Line::getIsVertical() const
{
	return this->isVertical;
}

void Line::setM(double m)
{
	this->m = m;
}

void Line::setB(double b)
{
	this->b = b;
}

double Line::distance(const Point& p) const
{
	double dst = 0;
	if (!this->getIsVertical())
	{
		dst = this->getM() * p.getX() - p.getY() + this->getB();
		dst = abs(dst);
		dst /= sqrt(pow(this->getM(), 2) + 1);
	}
	else
	{
		dst = p.getX() - this->getB();
		dst = abs(dst);
	}
	return dst;
}

const Point Line::getPointByX(const double x) const
{
	if (this->getIsVertical())
	{
		throw("Line is vertical");
	}
	return Point(x, this->getM()*x+this->getB());
}

const Point Line::getPointByY(const double y) const
{
	if (this->getIsVertical())
	{
		return Point(this->getB(), y);
	}
	return Point((y-this->getB())/this->getM(),y);
}

const double Line::isIntersacting(const Point& p) const
{
	double y = 0;

	if (this->getIsVertical())
	{
		return p.getX() - this->getB();
	}

	y = p.getX() * this->getM() + this->getB();
	return p.getY() - y;
}

const bool Line::isIntersacting(const Line& line) const
{
	double incline = 0;
	double b = 0;

	incline = this->getM() - line.getM();
	b = line.getB() - this->getB();

	if (this->getIsVertical() && line.getIsVertical())
	{
		return b ? false : true;
	}
	
	return incline ? true : b ? false : true;
}

const double Line::intersaction(const Line& line) const
{
	double incline = 0;
	double freeNumber = 0;
	if (line.getB() == this->getB() && line.getM() == this->getM() &&  line.getIsVertical() == this->getIsVertical())
	{
		throw("Same Line");
	}
	else if (isIntersacting(line))
	{
		incline = this->getM() - line.getM();
		freeNumber = line.getB() - this->getB();
		return freeNumber / incline;
	}
	else
	{
		throw("Lines do not intersect");
	}
}

Point Line::findPoint(const Point& p, const double distance, const bool first) const
{
	double freeNumbers = pow(p.getX(),2) + pow(p.getY(),2) - 2*p.getY()*this->getB() + pow(this->getB(), 2) - pow(distance, 2);
	double firsDegree = -2 * p.getX() - 2 * p.getY() * this->getM() + 2*this->getM()*this->getB();
	double secondDegree = 1 + pow(this->getM(), 2);

	double discriminant = pow(firsDegree,2) - 4 * secondDegree * freeNumbers;
	double x = (-1 * firsDegree);
	discriminant = sqrt(discriminant);
	if (first)
	{
		x += discriminant;
	}
	else
	{
		x -= discriminant;
	}
	x /= 2 * secondDegree;
	
	return this->getPointByX(x);
}

std::string Line::toString() const
{
	return this->getIsVertical()?"X=":"Y=" + (this->getM()==1? "" : std::to_string(this->getM())) + "X" + (this->getB() > 0 ? "+" : "") + (this->getB() ? std::to_string(this->getB()) : "");
}
