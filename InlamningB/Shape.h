#ifndef SHAPE_H
#define SHAPE_H

#include <string>
const double PI = 3.141592653;
using namespace std;


class Shape
{
private:
	double volume;
	double height;
public:
	//Konstruktor med defaultvärden.
	Shape(double height = 0);
	//Copy Konstruktor
	Shape(const Shape &origObj);
	//Dekonstruktor
	virtual ~Shape();
	void setVolume();
	double getVolume()const;
	virtual double volumeCalc()const = 0;
	double getHeight()const;
	void setHeight(double height);

	//To-string
	string toString()const;
	virtual string toStringSpec()const = 0;

	//Operatorer
	Shape& operator=(const Shape &origObj);
	bool operator==(const Shape &origObj);
};

#endif