#include "ShapeRegister.h"
#include <iostream>

ShapeRegister::ShapeRegister(string title)
{
	this->title = title;
	this->capacity = 3;
	this->nrOfShapes = 0;
	this->nrOfCones = 0;
	this->nrOfBoxes = 0;
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

	for (int i = 0; i < this->nrOfShapes; i++)
	{
		temp[i] = this->shapes[i];
	}

	delete[] this->shapes;
	this->shapes = temp;

	this->initiate(this->nrOfShapes);
}

void ShapeRegister::freeMemory()
{
	for (int i = 0; i < this->nrOfShapes; i++)
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
	
	for (int i = 0; i < this->nrOfShapes; i++)
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
		if (this->nrOfShapes >= this->capacity)
		{
			this->expand();
			this->shapes[this->nrOfShapes] = new Box(height, length, width);
			this->shapes[this->nrOfShapes++]->setVolume();
			this->nrOfBoxes++;
		}
		else
		{
			this->shapes[this->nrOfShapes] = new Box(height, length, width);
			this->shapes[this->nrOfShapes++]->setVolume();
			this->nrOfBoxes++;
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
		if (this->nrOfShapes >= this->capacity)
		{
			this->expand();
			this->shapes[this->nrOfShapes] = new Cone(height, radius);
			this->shapes[this->nrOfShapes++]->setVolume();
			this->nrOfCones++;
		}
		else
		{
			this->shapes[this->nrOfShapes] = new Cone(height, radius);
			this->shapes[this->nrOfShapes++]->setVolume();
			this->nrOfCones++;
		}
	}
	return shapeIsFound;
}

int ShapeRegister::getNrOfShapes()const
{
	return this->nrOfShapes;
}

int ShapeRegister::getNrOfCones()const
{
	return this->nrOfCones;
}

int ShapeRegister::getNrOfBoxes()const
{
	return this->nrOfBoxes;
}

bool ShapeRegister::getAllShapesAsStrings(string arr[], int capOfArr)const
{
	bool shapesExists = false;
	int cnt = 0;
	while (cnt < this->nrOfShapes && cnt < capOfArr)
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
	for (int i = 0; i < this->nrOfShapes && cnt < capOfArr; i++)
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
	for (int i = 0; i < this->nrOfShapes && capOfArr >= this->nrOfBoxes; i++)
	{
		cout << cnt << endl;
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