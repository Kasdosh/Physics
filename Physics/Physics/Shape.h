#pragma once

#include <vector>
#include "Line.h"

using namespace std;

class Shape
{
public:
	Shape();
		

private:
	vector<Point> vertices;
	Point centerOfMass;
	double rotationAngle;

};

