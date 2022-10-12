#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() // random age of animal
{
	age = rand() % (1 - 15) + 1;
}

Animal::Animal(unsigned short age)
{
	this->age = age;
}

unsigned short Animal::GetAge()
{
	return age;
}

void Animal::SetAge(unsigned short age)
{
	this->age = age;
}

Animal::~Animal()
{
}


