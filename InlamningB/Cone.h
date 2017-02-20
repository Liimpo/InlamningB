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
	//Copy Konstruktor
	Cone(const Cone &origObj);
	//Dekonstruktor
	virtual ~Cone();
	//Funktioner
	double volumeCalc()const;
	double getRadius()const;
	void setRadius(double radius);

	//To-string
	string toStringSpec()const;

	//Operatorer
	Cone& operator=(const Cone &origObj);
	bool operator==(const Cone &origObj);
};

#endif