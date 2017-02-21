#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H
#include "Box.h"
#include "Shape.h"
#include "Cone.h"

class ShapeRegister
{
private:
	//Titel, blir lite roligare om man vill anv�nda sig utav flera register.
	string title;
	int capacity;
	int shapesInReg;
	Shape* *shapes;

	void initiate(int from = 0);
	void freeMemory();
	void expand();
	void copySetup(const ShapeRegister &origObj);
public:
	//Konstruktor
	ShapeRegister(string title = "-");
	//Dekonstruktor
	virtual ~ShapeRegister();
	//Copy Konstruktor
	ShapeRegister(const ShapeRegister &origObj);
	//Tildelningsoperator
	ShapeRegister operator=(const ShapeRegister &origObj);
	//Add-Remove funktioner
	bool addCone(double height, double radius);
	bool addBox(double height, double length, double width);
	bool editACone(double height, double radius);
	bool editABox(double height, double length, double width);
	bool removeShape(double height);
	//Funktioner som kollar efter unik h�jd
	int shapeSearch(double height)const;
	bool shapeExists(double height)const;
	//Get-funktioner
	int nrOfShapes()const;
	int nrOfCones()const;
	int nrOfBoxes()const;
	string getTitle()const;
	//Print funktion
	bool getAllShapesAsStrings(string arr[], int capOfArr)const;
	bool getAllConesAsStrings(string arr[], int capOfArr)const;
	bool getAllBoxesAsStrings(string arr[], int capOfArr)const;
};
#endif
