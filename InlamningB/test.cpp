#include "Box.h"
#include "Cone.h"
#include "Shape.h"
#include "ShapeRegister.h"
#include <iostream>

using namespace std;

int main()
{

	ShapeRegister r1("Test");
	r1.addBox(33, 25, 44);
	r1.addBox(33, 33, 77);
	r1.addCone(23, 15);
	r1.addCone(33, 5);
	r1.addCone(44, 10);
	r1.addCone(11, 5);
	r1.addBox(5, 5.3, 5.8);
	r1.addBox(7, 5.3, 5.8);
	ShapeRegister r2("Hue");
	r2.addBox(11,7,6);
	r1 = r2;
	int a, b, c;
	string arr[4];
	string arr2[4];

	a = r1.nrOfBoxes();
	b = r1.nrOfCones();
	c = r1.nrOfShapes();

	cout << "Test." << endl << a << endl << b << endl << c << endl;
	if (r1.getAllBoxesAsStrings(arr, 4))
	{
		cout << "\nIts ok" << endl;
	}
	else
		cout << "\nIts not ok" << endl;
	for (int i = 0; i < a; i++)
	{
		cout << "\n\nHello:\n" << arr[i];
		cin.get();
	}
	string arr3[4];
	r1.getAllConesAsStrings(arr3, 4);
	for (int i = 0; i < b; i++)
	{
		cout << "\nHello:\n" << arr3[i];
		cin.get();
	}
	cout << "yo" << endl;
	r1.editACone(5,5);
	cout << "yo" << endl;
	r1.getAllBoxesAsStrings(arr2, 4);
	a = r1.nrOfBoxes();

	for (int i = 0; i < a; i++)
	{
		cout << "\nTest:\n" << arr2[i];
		cin.get();
	}
	string arr4[10];
	cout << endl << endl << endl << "WIHO" << endl << "-------" << endl;
	r2.getAllShapesAsStrings(arr4, 10);
	for (int i = 0; i < c; i++)
	{
		cout << arr4[i] << endl;
	}

	return 0;
}
