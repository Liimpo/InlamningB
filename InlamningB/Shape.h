#ifndef SHAPE_H
#define SHAPE_H

#include <string>
const double PI = 3.141592653;
using namespace std;


class Shape
{
private:
	double height;
	//double volume;
public:
	//Konstruktor med defaultv�rden.
	Shape(double height = 0);
	//Dekonstruktor
	virtual ~Shape();
	double getVolume()const;
	virtual double volumeCalc()const = 0;
	double getHeight()const;
	void setHeight(double height);

	//To-string
	string toString()const;
	virtual string toStringSpec()const = 0;
};

#endif
