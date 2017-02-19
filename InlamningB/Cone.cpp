#include "Cone.h"

Cone::Cone(double height, double radius)
	:Shape(height)
{
	this->radius = radius;
}

Cone::Cone(const Cone &origObj):Shape(origObj)
{
	this->radius = origObj.radius;
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

Cone& Cone::operator=(const Cone &origObj)
{
	Shape::operator=(origObj);
	this->radius = origObj.radius;
	return *this;
}

bool Cone::operator==(const Cone &origObj)
{
	bool equals = false;;

	if (this->radius == origObj.radius)
		equals = true;

	return equals;
}