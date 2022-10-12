#include "Environment.h"
#include <iostream>
using namespace std;


Environment::~Environment()
{
	if (foxptr != nullptr) delete[]foxptr;
	if (rabbitptr != nullptr) delete[] rabbitptr;
}

void Environment::Print() {

	if (fox_size == 0 && rabbit_size == 0) {
		cout << "They're all dead!" << endl;
		return;
	}
	for (int i = 0; i < fox_size; i++)
	{
		cout << "Fox # " << i+1 << "; age - " << foxptr[i].GetAge() << endl;
	}
	cout << endl;
	for (int i = 0; i < rabbit_size; i++)
	{
		cout << "Rabbit # " << i+1 << "; age - " << rabbitptr[i].GetAge() << endl;
	}
	cout << endl << endl;
}


void Environment::Scene()
{
	system("cls");
	cout << "There are " << fox_size << " foxes, " << rabbit_size << " rabbits and " << grass << " grass!" << endl;
	if(fox_size > 0 || rabbit_size > 0)Print();
	system("pause");
	system("cls");

	if (grass == 0 && (fox_size > 0 || rabbit_size > 0)) {
		system("cls");
		cout << "You just noticed that there is no grass in this desert area.." << endl;
		cout << "Divine forces are trying to make it rain!.." << endl;
		if (rand() % 2 == true) {
			cout << "Success! Clouds appeared out of nowhere and poured rain!" << endl;
			short random = rand() % (1 - 10) + 1;
			cout << "Grass + " << random << "!" << endl;
			grass += random;
			system("pause");
		}
		else {
			cout << "But it didn't rain..." << endl;
			system("pause");
		}
			
	}
	
	system("cls");

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
	if (dead_foxes > 0 || dead_rabbits > 0) {
		cout << "After that, there are " << fox_size << " fox(es), " << rabbit_size << " rabbit(s) and " << grass << " grass..." << endl;
		Print();
	}
	system("pause");
	system("cls");

	if (fox_size <= 0 && rabbit_size <= 0 ) {
		cout << "....." << endl;
		cout << "It seems, there is no one here." << endl;
		if (grass > 0) cout << grass << " units of grass drained over time.." << endl;
		else cout << "No foxes, no rabbits, no grass. You have created an absolute void. It's lonely here.. Congratulations!?" << endl;
	}
	else if (fox_size <= 0) {
		cout << "This environment looks so peaceful for " << rabbit_size << " rabbit(s)! There are no foxes!" << endl;
		if (grass > 0) {
			cout << "Moreover, grass grows here and rabbits can eat it, obviously.." << endl;
			if (grass >= rabbit_size) {
				grass -= rabbit_size;
				cout << "Each rabbit ate a blade of grass (" << grass << " grass left) and " << rabbit_size << " rabbit(s) lived happily ever after!" << endl;
			}
			else {
				dead_rabbits = 0;
				cout << "It seemed like a happy end, but there was clearly not enough grass for all the rabbits ..." << endl;
				while (grass != rabbit_size)
				{
					DelRabbit(0);
					dead_rabbits++;
				}
				cout << "Although " << dead_rabbits << " rabbit(s) died of starvation, " << rabbit_size << " of them, having eaten grass, continued to live happily. " << endl;
			}
		}
		else {
			cout << "One could rejoice, but there was not a single blade of grass in this area ..." << endl;
			cout << "All the rabbits died of starvation!!! You should have given them grass, killer! " << endl;
			DelRabbitTo(0);
		}
	}
	else if (rabbit_size <= 0) {
		cout << fox_size << " fox(es) out looking for food..." << endl;
		cout << "But there are no rabbits!" << endl;
		if (grass > 0) cout << "Fox(es) tried to eat the grass..\nThey didn't like it.." << endl;
		DelFoxesTo(0);
		cout << "The foxes have no choice but to starve to death.." << endl;
	}
	else if (rabbit_size > fox_size) {
		cout << fox_size << " fox(es) tried to attack " << rabbit_size << " rabbits!" << endl;
		cout << "But there were more rabbits and they were able to scare away the fox(es)!" << endl;
		cout << "The humiliated foxes have gone to another place.." << endl;
		if (grass > 0) {
			cout << "The happy and proud rabbits are hungry now..." << endl;
			if (grass >= rabbit_size) {
				grass -= rabbit_size;
				cout << "Each rabbit ate a blade of grass (" << grass << " grass left) and " << rabbit_size << " rabbit(s) lived happily ever after!" << endl;
				cout << "And the foxes managed to migrate successfully! Happy End!" << endl;
			}
			else {
				dead_rabbits = rabbit_size - grass;
				cout << "Although the rabbits managed to drive the foxes away, there was not enough food for everyone.." << endl;
				DelRabbitTo(grass);
				cout << "Sadly, " << dead_rabbits << " rabbit(s) died of starvation, " << rabbit_size << " of them, having eaten grass, continued to live happily. " << endl;
				cout << "All the foxes managed to migrate successfully!" << endl;
			}
		}
		else {
			cout << "They were able to defeat the foxes, but not the hunger. There was no grass and they soon died." << endl;
			cout << "But the foxes managed to migrate successfully!" << endl;
			while (rabbit_size != 0)
			{
				DelRabbit(0);
			}
		}

	}
	else if (fox_size >= rabbit_size) {
		cout << fox_size << " fox(es) out looking for food..." << endl;
		cout << "and they found " << rabbit_size << " rabbits!" << endl;
		if (fox_size == rabbit_size) {
			DelRabbitTo(0);
			cout << "Each fox ate one of the rabbits. And " << fox_size << " fox(es) continued to live!" << endl;
		}
		else {
			dead_foxes = fox_size - rabbit_size;
			cout << "But there won't be enough rabbits for all the foxes..." << endl;
			DelFoxesTo(rabbit_size);
			DelRabbitTo(0);
			cout << "Sadly, " << dead_foxes << " fox(s) died of starvation, " << fox_size << " of them, having eaten rabbits, continued to live happily. " << endl;
		}
	}
	cout << endl;
	cout << "THE END.\nSurvivors:\n";
	Print();
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

void Environment::DelRabbitTo(int summ_of_rabbits_remain)
{
	while (rabbit_size != summ_of_rabbits_remain)
	{
		DelRabbit(0);
	}
}
void Environment::DelFoxesTo(int summ_of_foxes_remain)
{
	while (fox_size != summ_of_foxes_remain)
	{
		DelFox(0);
	}
}
