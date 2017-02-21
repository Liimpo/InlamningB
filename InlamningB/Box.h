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
	//Dekonstruktor
	virtual ~Box();

	//Medlemsfunktioner
	string toStringSpec()const;
	double volumeCalc()const;
	void setLength(double length);
	void setWidth(double width);
	double getLength()const;
	double getWidth()const;

};
#endif
