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
	Environment(int foxsize, int rabbitsize, int grasss) {
		fox_size = foxsize;
		if (fox_size > 5)fox_size = 5;
		rabbit_size = rabbitsize;
		foxptr = new Fox[fox_size];
		rabbitptr = new Rabbit[rabbit_size];
		grass = grasss;
	}
	~Environment();
	void DelRabbit(int index);
	void DelRabbitTo(int summ_of_rabbits_remain);
	void DelFoxesTo(int summ_of_foxes_remain);
	void DelFox(int index);
	void Scene();

	
};

