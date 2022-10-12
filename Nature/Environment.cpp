#include "Environment.h"
#include <iostream>
using namespace std;


Environment::~Environment()
{
	if (foxptr != nullptr) delete[]foxptr;
	if (rabbitptr != nullptr) delete[] rabbitptr;
}

void Environment::Print() {

	if (fox_size == 0 && rabbit_size == 0)return;
	for (int i = 0; i < fox_size; i++)
	{
		cout << "F# " << i+1 << "; age - " << foxptr[i].GetAge() << endl;
	}
	cout << endl;
	for (int i = 0; i < rabbit_size; i++)
	{
		cout << "R# " << i+1 << "; age - " << rabbitptr[i].GetAge() << endl;
	}
	cout << endl << endl;
}


void Environment::Scene()
{
	cout << "There are " << fox_size << " foxes, " << rabbit_size << " rabbits and " << grass << " grass!" << endl;

	if (grass == 0) {
		cout << "You just noticed that there is no grass in this desert area.." << endl;
		cout << "Divine forces are trying to make it rain!.." << endl;
		if (rand() % 2 == true) {
			cout << "Success! Clouds appeared out of nowhere and poured rain!" << endl;
			short random = rand() % (1 - 10) + 1;
			cout << "Grass + " << random << "!" << endl;
			grass += random;
		}
		else
			cout << "But it didn't rain..." << endl;
	}

	int dead_foxes = 0, dead_rabbits = 0;

	for (int i = 0; i < fox_size; i++)
	{
		if (foxptr[i].IsDead()) {
			dead_foxes++;
			DelFox(i);
			i--;
		}

	}

	for (int i = 0; i < rabbit_size; i++)
	{
		if (rabbitptr[i].IsDead()) {
			dead_rabbits++;
			DelRabbit(i);
			i--;
		}

	}

	if (dead_foxes > 0)
		cout << "Oh no! It seems like " << dead_foxes << " fox(es) have died of old age!" << endl;
	if (dead_rabbits > 0)
		cout << "Unfortunately, " << dead_rabbits << " rabbit(s) gone to another world because of longevity .." << endl;
	if (dead_foxes > 0 || dead_rabbits > 0)
		cout << "After that, there are " << fox_size << " fox(es), " << rabbit_size << " rabbit(s) and " << grass << " grass..." << endl;


	



	cout << "\n\n\n\n";
}
void Environment::DelFox(int index) {
	if (foxptr == nullptr)return;
	if (fox_size == 1) {
		fox_size = 0;
		delete[] foxptr;
		foxptr = nullptr;
		return;
	}
	Fox* temp = new Fox[fox_size - 1];

	for (int i = 0; i < index; i++)
	{
		temp[i].SetAge(foxptr[i].GetAge());
		temp[i].SetMaxAge(foxptr[i].GetMaxAge());
	}

	for (int i = index; i < fox_size-1; ++i)
	{
		if (index == fox_size) {
			temp[i].SetAge(foxptr[i].GetAge());
			temp[i].SetMaxAge(foxptr[i].GetMaxAge());
		}
		temp[i].SetAge(foxptr[i + 1].GetAge());
		temp[i].SetMaxAge(foxptr[i + 1].GetMaxAge());
	}

	delete[] foxptr;
	foxptr = temp;
	fox_size--;
}
void Environment::DelRabbit(int index) {
	if (rabbitptr == nullptr)return;
	if (rabbit_size == 1) {
		rabbit_size = 0;
		delete[] rabbitptr;
		rabbitptr = nullptr;
		return;
	}

	Rabbit* temp = new Rabbit[rabbit_size - 1];

	for (int i = 0; i < index; i++)
	{
		temp[i].SetAge(rabbitptr[i].GetAge());
		temp[i].SetMaxAge(rabbitptr[i].GetMaxAge());
	}

	for (int i = index; i < rabbit_size - 1; ++i)
	{
		if (index == rabbit_size) {
			temp[i].SetAge(rabbitptr[i].GetAge());
			temp[i].SetMaxAge(rabbitptr[i].GetMaxAge());
		}
		temp[i].SetAge(rabbitptr[i + 1].GetAge());
		temp[i].SetMaxAge(rabbitptr[i + 1].GetMaxAge());
	}
	delete[]rabbitptr;
	rabbitptr = temp;
	rabbit_size--;
	
}
