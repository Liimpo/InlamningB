#include "ShapeRegister.h"
#include <iostream>

void printMenu();
void addConeToRegister(ShapeRegister &currentRegister);
void addBoxToRegister(ShapeRegister &currentRegister);
void removeShapeFromRegister(ShapeRegister &currentRegister);
void printAllShapes(ShapeRegister currentRegister);
void printAllBoxes(ShapeRegister currentRegister);
void printAllCones(ShapeRegister currentRegister);
void editConeInRegister(ShapeRegister &currentRegister);
void editBoxInRegister(ShapeRegister &currentRegister);

int main()
{
  ShapeRegister r1("Test");
  return 0;
}

void printMenu()
{
  system("cls");
  cout << "====================================\n=            Welcome!              =\n=      To Timberhandler V1.0       =\n";
  cout << "=   Made by Linus Malmfelt @BTH    =\n====================================\n";
  cout << "1. Add a cone to your register" << endl;
  cout << "2. Add a box to your register" << endl;
  cout << "3. Edit a cone in your register" << endl;
  cout << "4. Edit a box in you register" << endl;
  cout << "5. Remove a shape from your register" << endl;
  cout << "6. View all of your boxes. How many and dimensions/volume" << endl;
  cout << "7. View all of your cones. How many and dimensions/volume" << endl;
  cout << "8. View all of your shapes. How many and dimensions/volume" << endl;
}
