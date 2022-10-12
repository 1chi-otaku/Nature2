#include "Fox.h"

#include <iostream>
using namespace std;
Fox::Fox():Animal()
{
	max_age = 10;
}
bool Fox::IsDead()
{
	if (age >= max_age) return 1;
	return 0;
}

unsigned short Fox::GetMaxAge()
{
	return max_age;
}

void Fox::SetMaxAge(unsigned short age)
{
	max_age = age;
}

