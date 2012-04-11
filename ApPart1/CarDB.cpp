#include "CarDB.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

CarDB::CarDB()
{
	indexOutOfDate = true;
}

CarDB::CarDB(vector<Car> d_cars) : cars(d_cars)
{
	CarDB();
}

void CarDB::clearIndices()
{
	priceIndex.clear();
}

string CarDB::now()
{	
	time_t rawtime;	
	time ( &rawtime );
	struct tm * timeinfo = localtime ( &rawtime );
	string now = asctime (timeinfo);

	return now;
}

void CarDB::addCarToDB(Car c)
{
	cars.push_back(c);
	indexOutOfDate = true;
	clearIndices();
}

void CarDB::makeIndices()
{
	clearIndices();

	if(cars.empty())
		return;

	for(vector<Car>::iterator it = cars.begin();
		it != cars.end();
		it++)
	{
		priceIndex.insert(pair<int, VCI>((*it).price, it));
	}
}
/*
void CarDB::findByPrice(const int p)
{
	vector<VCI> result;

	multimap<int, VCI>::iterator it = priceIndex.begin();

	string now = CarDB::now();
	
	while(it != priceIndex.end())
	{
		it = find(it, priceIndex.end(), p);
		if(it == priceIndex.end())
			break;
		
		cout << *(it->second) << "\n";
		
		it->second->lastViewed = now;

		++it;
	}
}
*/
void CarDB::findByBrand(string& brand)
{
	Car searchCar(brand);

	vector<Car>::iterator it = cars.begin();

	string now = CarDB::now();

	while(it != cars.end())
	{
		it = find(it, cars.end(), searchCar);
		if(it == cars.end())
			break;

		cout << *it << "\n";

		it->lastViewed = now;

		++it;
	}
}