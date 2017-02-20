#include "ShapeRegister.h"
#include <iostream>

ShapeRegister::ShapeRegister(string title)
{
	this->title = title;
	this->capacity = 3;
	this->shapesInReg = 0;
	this->shapes = new Shape*[this->capacity];
	this->initiate(0);
}

ShapeRegister::~ShapeRegister()
{
	this->freeMemory();
}

void ShapeRegister::expand()
{
	this->capacity *= 2;
	Shape* *temp = new Shape*[this->capacity];

	for (int i = 0; i < this->shapesInReg; i++)
	{
		temp[i] = this->shapes[i];
	}

	delete[] this->shapes;
	this->shapes = temp;

	this->initiate(this->shapesInReg);
}

void ShapeRegister::freeMemory()
{
	for (int i = 0; i < this->shapesInReg; i++)
	{
		delete this->shapes[i];
	}
	delete[] this->shapes;
}

void ShapeRegister::initiate(int from)
{
	for (int i = from; i < this->capacity; i++)
	{
		this->shapes[i] = nullptr;
	}
}

int ShapeRegister::shapeSearch(double height)const
{
	int index = -1;
	bool found = false;

	for (int i = 0; i < this->shapesInReg; i++)
	{
		if (this->shapes[i]->getHeight() == height && !found)
		{
			index = i;
			found = true;
		}
	}
	return index;
}

bool ShapeRegister::shapeExists(double height)const
{
	bool found = false;
	if (this->shapeSearch(height) > -1)
	{
		found = true;
	}
	return found;
}

bool ShapeRegister::addBox(double height, double length, double width)
{
	bool shapeIsFound = false;
	shapeIsFound = this->shapeExists(height);
	if (!shapeIsFound)
	{
		if (this->shapesInReg >= this->capacity)
		{
			this->expand();
			this->shapes[this->shapesInReg++] = new Box(height, length, width);
		//	this->shapes[this->shapesInReg++]->setVolume();
		}
		else
		{
			this->shapes[this->shapesInReg++] = new Box(height, length, width);
			//this->shapes[this->shapesInReg++]->setVolume();
		}

	}
	return shapeIsFound;
}

bool ShapeRegister::addCone(double height, double radius)
{
	bool shapeIsFound = false;
	shapeIsFound = this->shapeExists(height);
	if (!shapeIsFound)
	{
		if (this->shapesInReg >= this->capacity)
		{
			this->expand();
			this->shapes[this->shapesInReg++] = new Cone(height, radius);
		}
		else
		{
			this->shapes[this->shapesInReg++] = new Cone(height, radius);
		}
	}
	return shapeIsFound;
}

bool ShapeRegister::editACone(double height, double radius)
{
	bool coneIsEdited = false;
	int conePos = this->shapeSearch(height);

	Cone* conePtr = nullptr;
	conePtr = dynamic_cast<Cone*>(this->shapes[conePos]);

	if (conePtr != nullptr && conePtr->getRadius() == radius)
	{
		cout << "yo" << endl;
	}
	
	cout << conePos << endl;
	return coneIsEdited;
}

int ShapeRegister::nrOfShapes()const
{
	return this->shapesInReg;
}

bool ShapeRegister::getAllShapesAsStrings(string arr[], int capOfArr)const
{
	bool shapesExists = false;
	int cnt = 0;
	while (cnt < this->shapesInReg && cnt < capOfArr)
	{
		arr[cnt] = this->shapes[cnt]->toString();
		cnt++;
		shapesExists = true;
	}

	return shapesExists;
}

bool ShapeRegister::getAllConesAsStrings(string arr[], int capOfArr)const
{
	bool conesExists = false;
	int cnt = 0;
	Cone* conePtr;
	for (int i = 0; i < this->shapesInReg && capOfArr >= this->nrOfCones() && cnt < this->nrOfCones(); i++)
	{
		conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(this->shapes[i]);
		if (conePtr != nullptr)
		{
			arr[cnt] = this->shapes[i]->toString();
			cnt++;
			conesExists = true;
		}
	}

	return conesExists;
}

bool ShapeRegister::getAllBoxesAsStrings(string arr[], int capOfArr)const
{
	bool boxesExists = false;
	int cnt = 0;
	Box* boxPtr;
	for (int i = 0; i < this->shapesInReg && capOfArr >= this->nrOfBoxes(); i++)
	{
		boxPtr = nullptr;
		boxPtr = dynamic_cast<Box*>(this->shapes[i]);
		if (boxPtr != nullptr)
		{
			arr[cnt] = this->shapes[i]->toString();
			cnt++;
			boxesExists = true;
		}
	}
	return boxesExists;
}

int ShapeRegister::nrOfBoxes()const
{
	int boxesCnt = 0;
	//Sätter en box pointer
	Box* boxPtr;

	for (int i = 0; i < this->shapesInReg; i++)
	{
		boxPtr = nullptr;
		boxPtr = dynamic_cast<Box*>(this->shapes[i]);
		if (boxPtr != nullptr)
		{
			boxesCnt++;
		}
	}
	return boxesCnt;
}

int ShapeRegister::nrOfCones()const
{
	int conesCnt = 0;

	Cone* conePtr;

	for (int i = 0; i < this->shapesInReg; i++)
	{
		conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(this->shapes[i]);
		if (conePtr != nullptr)
		{
			conesCnt++;
		}
	}
	return conesCnt;
}
