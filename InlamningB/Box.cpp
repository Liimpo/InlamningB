#include "Box.h"

Box::Box(double height, double length, double width)
	:Shape(height)
{
	this->length = length;
	this->width = width;
}

Box::~Box()
{

}

Box::Box(const Box &origObj)
	:Shape(origObj)
{
	this->length = origObj.length;
	this->width = origObj.width;
}

double Box::volumeCalc()const
{
	return (this->length * this->width * Shape::getHeight());
}

string Box::toStringSpec()const
{
	string text = "";
	text += "Shape: Box\n";
	text += "Length: ";
	text += to_string(this->length);
	text += "\nWidth: ";
	text += to_string(this->width);
	return text;
}

void Box::setLength(double length)
{
	this->length = length;
}

void Box::setWidth(double width)
{
	this->width = width;
}

double Box::getLength()const
{
	return this->length;
}

double Box::getWidth()const
{
	return this->width;
}

Box& Box::operator=(const Box &origObj)
{
	Shape::operator=(origObj);
	this->length = origObj.length;
	this->width = origObj.width;
	return *this;
}

bool Box::operator==(const Box &origObj)
{
	bool equals = false;

	if (this->length == origObj.length && this->width == origObj.width)
		equals = true;

	return equals;
}
