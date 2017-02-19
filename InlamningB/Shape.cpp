#include "Shape.h"

//Konstruktor

Shape::Shape(double height)
{
	this->volume = 0;
	this->height = height;
}

//Copy Konstruktor

Shape::Shape(const Shape &origObj)
{
	this->volume = origObj.volume;
	this->height = origObj.height;
}

Shape::~Shape()
{

}

void Shape::setVolume()
{
	this->volume = this->volumeCalc();
}

double Shape::getVolume()const
{
	return this->volume;
}

void Shape::setHeight(double height)
{
	this->height = height;
}

double Shape::getHeight()const
{
	return this->height;
}

string Shape::toString()const
{
	string text = "";
	text += this->toStringSpec();
	text += "\nHeight: ";
	text += to_string(this->height);
	text += "\nVolume: ";
	text += to_string(this->volume);
	text += "\n";
	return text;
}

Shape& Shape::operator=(const Shape &origObj)
{
	this->volume = origObj.volume;
	this->height = origObj.height;
	return *this;
}

bool Shape::operator==(const Shape &origObj)
{
	bool equals = false;

	if (this->height == origObj.height)
		equals = true;
	return equals;
}