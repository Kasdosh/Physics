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

Line::Line(const Point& a)
	:Line(0,a.getX(),true)
{
}

Line::Line(const double m, const double b, const bool isVertical)
{
	this->setB(b);
	this->setM(m);
	this->isVertical = isVertical;
}

Line::Line(const Point& a, const double m)
	:Line(m, a.getY() - m * a.getX())
{
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

const Line Line::getPerpendicular() const
{
	return this->getPerpendicular(Point(0,0));
}

const Line Line::getPerpendicular(const Point& p) const
{
	double incline = 0;
	double b = 0;
	if (this->getIsVertical())
	{
		return Line(0, p.getY());
	}
	else if (this->getM() == 0)
	{
		return Line(p);
	}
	else
	{
		incline = -1 / this->getM();
		b = p.getY() - incline * p.getX();
		return Line(incline, b);
	}
}

Point Line::findPoint(const Point& p, const double distance, const bool first) const
{
	double freeNumbers = 0;
	double firsDegree = 0;
	double secondDegree = 0;

	double discriminant = 0;
	double x = 0;
	double y = 0;

	if (this->isIntersacting(p))
	{
		throw("Point is not on the line");
	}

	if (!this->getIsVertical())
	{
		freeNumbers = pow(p.getX(), 2) + pow(p.getY(), 2) - 2 * p.getY() * this->getB() + pow(this->getB(), 2) - pow(distance, 2);
		firsDegree = -2 * p.getX() - 2 * p.getY() * this->getM() + 2 * this->getM() * this->getB();
		secondDegree = 1 + pow(this->getM(), 2);

		discriminant = pow(firsDegree, 2) - 4 * secondDegree * freeNumbers;
		discriminant = sqrt(discriminant);

		x = (-1 * firsDegree);

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
	else
	{
		y = p.getY();

		if (first)
		{
			y += distance;
		}
		else
		{
			y -= distance;
		}

		return this->getPointByY(y);
	}
}

std::string Line::toString() const
{
	return this->getIsVertical() ? "X=" + std::to_string(this->getB()) : "Y=" + (this->getM()==1 || this->getM() == 0? "" : std::to_string(this->getM())) + (this->getM() == 0?"":"X") + (this->getB() > 0 ? (this->getM()?"+":"") : "") + (this->getB() ? std::to_string(this->getB()) : (this->getM() == 0 ? "0" : ""));
}
