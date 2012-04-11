#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>
#include "Car.h"

using namespace std;

string getQuery()
{
	cout << "\nEnter the model you wish to search for: ";

	string i;
	getline(cin, i);
	return i;
	
	/*
	// Uses iterators, but will only read once from the buffer.
	// It is most likely because it reaches the 'eof', and of course there will be no
	// more data beyond that point.
	istreambuf_iterator<char> eos;               // end-of-range iterator
	istreambuf_iterator<char> iit (cin.rdbuf()); // stdin iterator
	string str;

	cout << "\nEnter the model you wish to search for: ";

	while (iit!=eos && *iit!='\n'){
		str += *iit++;
	}

	return str;
	*/
}

void search(const string& brand, vector<Car>* cars)
{
	Car searchCar(brand);

	vector<Car>::iterator it = cars->begin();

	time_t rawtime;	
	time ( &rawtime );
	struct tm * timeinfo = localtime ( &rawtime );
	string now = asctime (timeinfo);

	while(it != cars->end())
	{
		it = find(it, cars->end(), searchCar);
		if(it == cars->end())
			break;

		cout << *it << "\n";

		it->lastViewed = now;

		++it;
	}
}

int main()
{
	vector<Car> cars;
	cars.push_back(Car("Mazda", "323", 2000, 219000));
	cars.push_back(Car("Skoda", "Octavia", 1995, 150000));
	cars.push_back(Car("Ferrari", "Enzo", 2010, 2000000));
	cars.push_back(Car("Ferrari", "Enzo1", 2010, 2000000));
	cars.push_back(Car("Ferrari", "Enzo2", 2010, 2000000));
	cars.push_back(Car("Mazda", "626", 2005, 315000));
	cars.push_back(Car("Skoda", "Octavia", 1995, 150000));

	cout << "Welcome to the car DB, type 'Q' to quit";

	string i;
	while(true)
	{
		string q = getQuery();

		if(q == "Q")
			break;
		
		if(q != "")
			search(q, &cars);
	}

	return 0;
}
