#pragma once

#include <string>

using namespace std;

class Animal
{
protected: //�������� ��� �������������� ������ � ��� �����������
	string name;
public:
	Animal(string name_); //����������� � �����������
	~Animal(); //����������
	virtual void voice(); //����������� �����, ������� ������ ��������� ���������� ������ (����� ������ �� �������� �� ����� ����������)
};

