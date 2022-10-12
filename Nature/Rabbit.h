#pragma once
#include "Animal.h"
class Rabbit : public Animal
{
	unsigned int max_age;

public:
	Rabbit();
	bool IsDead();
	unsigned short GetMaxAge();
	void SetMaxAge(unsigned short age);
};
