#include "Rabbit.h"
#include <iostream>
using namespace std;
Rabbit::Rabbit():Animal()
{
	max_age = 12;
}
bool Rabbit::IsDead()
{
	if (age >= max_age) return 1;
	return 0;
}

unsigned short Rabbit::GetMaxAge()
{
	return max_age;
}

void Rabbit::SetMaxAge(unsigned short age)
{
	max_age = age;
}


