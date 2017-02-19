#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H
#include "Box.h"
#include "Shape.h"
#include "Cone.h"

class ShapeRegister
{
private:
	//Titel, blir lite roligare om man vill använda sig utav flera register.
	string title;
	int capacity;
	int nrOfShapes;
	int nrOfCones;
	int nrOfBoxes;
	Shape* *shapes;

	void initiate(int from = 0);
	void freeMemory();
	void expand();
public:
	//Konstruktor
	ShapeRegister(string title = "-");
	//Dekonstruktor
	~ShapeRegister();
	//Add-Remove funktioner
	bool addCone(double height, double radius);
	bool addBox(double height, double length, double width);
	//Funktioner som kollar efter unik höjd
	int shapeSearch(double height)const;
	bool shapeExists(double height)const;
	//Get-funktioner
	int getNrOfShapes()const;
	int getNrOfCones()const;
	int getNrOfBoxes()const;
	//Print funktion
	bool getAllShapesAsStrings(string arr[], int capOfArr)const;
	bool getAllConesAsStrings(string arr[], int capOfArr)const;
	bool getAllBoxesAsStrings(string arr[], int capOfArr)const;
};
#endif