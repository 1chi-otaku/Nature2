#pragma once
#include "Animal.h"
class Fox : public Animal
{
	unsigned int max_age;

public:
	Fox();
	bool IsDead();
	unsigned short GetMaxAge();
	void SetMaxAge(unsigned short age);
};


