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
	r1.getAllConesAsStrings(arr2, 4);
	for (int i = 0; i < b; i++)
	{
		cout << "\nTest:\n" << arr2[i];
		cin.get();
	}
	r1.editACone(44, 10);

	return 0;
}
