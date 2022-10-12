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
		rabbit_size = rabbitsize;
		foxptr = new Fox[fox_size];
		rabbitptr = new Rabbit[rabbit_size];
		grass = grasss;
	}
	~Environment();
	void DelRabbit(int index);
	void DelFox(int index);
	void Scene();

	
};

