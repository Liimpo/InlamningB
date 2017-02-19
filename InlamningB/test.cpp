#include "Box.h"
#include "Cone.h"
#include "Shape.h"
#include "ShapeRegister.h"
#include <iostream>
#include <crtdbg.h>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
	string arr[2];
	a = r1.getNrOfBoxes();
	b = r1.getNrOfCones();
	c = r1.getNrOfShapes();

	cout << "Test." << endl << a << endl << b << endl << c << endl;
	if (r1.getAllBoxesAsStrings(arr, 2))
	{
		cout << "\nIts ok" << endl;
	}
	else
		cout << "\nIts not ok" << endl;
	/*for (int i = 0; i < a; i++)
	{
		cout << "\n\nHello:\n" << arr[i];
		cin.get();
	}
	*/
	system("pause");
	return 0;
}