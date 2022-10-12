#include <iostream>
#include <windows.h>
#include "Animal.h"
#include "Rabbit.h"
#include "Fox.h"
#include "Environment.h"
using namespace std;



int main() {

	srand(time(NULL)); 
	int fox_size, rabbit_size, grass;
	cout << "Enter foxes (5 max): " << endl;
	cin >> fox_size;
	cout << "Enter rabbits: " << endl;
	cin >> rabbit_size;
	cout << "Enter grass:" << endl;
	cin >> grass;
	Environment env (fox_size, rabbit_size,grass);

	env.Scene();


	return 0;
}