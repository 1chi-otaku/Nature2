#pragma once
#include "Animal.h"
#include "Fox.h"
#include "Rabbit.h"
#include <iostream>
using namespace std;

class Environment
{
	Fox* foxptr;
	int fox_size;
	Rabbit* rabbitptr;
	int rabbit_size;

	int grass;
public:
	void Print();
	Environment(int foxsize, int rabbitsize, int grasss);
	~Environment();
	void DelRabbit(int index);
	void DelRabbitTo(int summ_of_rabbits_remain);
	void DelFoxesTo(int summ_of_foxes_remain);
	void DelFox(int index);
	void Scene();

	
};

