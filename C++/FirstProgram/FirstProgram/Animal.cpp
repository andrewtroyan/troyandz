#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

Animal::Animal(string name_) //����������� � ����������
{
	name = name_; //������������ ��������� ������������ ���� name
	cout << "New animal " << name << " is created." << endl; //������� ��������� ��� ������������ ������������
}


Animal::~Animal()
{
	cout << "Animal " << name << " is dead." << endl; //������� ��������� ��� ������������ �����������
}

void Animal::voice() {

}