#pragma once //����� ��������� ������ ���� ���

#include "Animal.h"
#include <string>

using namespace std;

class Cat : public Animal { //������������ �� Animal
public: //���� � ������, ��������� ��� ����
	Cat(string name_); //����������� � ����������
	virtual void voice();
};