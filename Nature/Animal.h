#pragma once
class Animal
{
protected:
	unsigned short age;
public:
	Animal();
	Animal(unsigned short age);
	unsigned short GetAge();
	void SetAge(unsigned short age);
	virtual ~Animal() = 0;
};

