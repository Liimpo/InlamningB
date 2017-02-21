#include "Cone.h"

Cone::Cone(double height, double radius)
	:Shape(height)
{
	this->radius = radius;
}

Cone::~Cone()
{

}

double Cone::volumeCalc()const
{
	return (PI*radius*radius*Shape::getHeight());
}

double Cone::getRadius()const
{
	return this->radius;
}

void Cone::setRadius(double radius)
{
	this->radius = radius;
}

string Cone::toStringSpec()const
{
	string text = "";
	text += "Shape: Cone\n";
	text += "Radius: ";
	text += to_string(this->radius);
	return text;
}
