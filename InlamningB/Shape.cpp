#include "Shape.h"

//Konstruktor

Shape::Shape(double height)
{
	this->height = height;
}

Shape::~Shape()
{

}


double Shape::getVolume()const
{
	return this->volumeCalc();
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
	text += to_string(this->volumeCalc());
	text += "\n";
	return text;
}
