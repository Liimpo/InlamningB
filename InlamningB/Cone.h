#ifndef CONE_H
#define CONE_H
#include "Shape.h"

class Cone: public Shape
{
private:
	double radius;
public:
	//Konstruktor
	Cone(double height = 0, double radius = 0);
	//Dekonstruktor
	virtual ~Cone();
	//Funktioner
	double volumeCalc()const;
	double getRadius()const;
	void setRadius(double radius);

	//To-string
	string toStringSpec()const;
};

#endif
