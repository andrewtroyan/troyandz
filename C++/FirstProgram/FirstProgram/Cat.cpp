#include <iostream>
#include "Cat.h"

using namespace std;

//������ ������������� �� �������� ����������� Animal
Cat::Cat(string name_) : Animal(name_) { 

}

//����� ������ Cat
void Cat::voice() { 
	cout << "Cat " << name << " says meow." << endl;
}