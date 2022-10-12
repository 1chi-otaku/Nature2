#include <iostream>
#include <windows.h>
#include "Animal.h"
#include "Rabbit.h"
#include "Fox.h"
#include "Environment.h"
using namespace std;



int main() {
	srand(time(NULL));
	int fox_size = 5, rabbit_size = 5;

	Environment env (fox_size, rabbit_size,0);

	

	env.Print();

	
	env.Scene();
	

	env.Print();



	return 0;
}