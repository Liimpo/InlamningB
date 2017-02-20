#ifndef BOX_H
#define BOX_H

#include "Shape.h"

class Box : public Shape
{
private:
	double length;
	double width;
public:
	//Konstruktor
	Box(double height = 0, double length = 0, double width = 0);
	//Copy-Konstruktor
	Box(const Box &origObj);
	//Dekonstruktor
	virtual ~Box();

	//Medlemsfunktioner
	string toStringSpec()const;
	double volumeCalc()const;
	void setLength(double length);
	void setWidth(double width);
	double getLength()const;
	double getWidth()const;

	//Operatorer
	Box& operator=(const Box &origObj);
	bool operator==(const Box &origObj);

};
#endif