#include "CarDB.h"
#include <sstream>

using namespace std;

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

	CarDB db(cars);

	db.makeIndices();


	cout << "Welcome to the car DB, type 'Q' to quit\nWrite P to search for a price\nWrite B to search for a brand\n";

	string q;
	while(true)
	{
		cout << "Chose what to search for (P = price, B = brand): ";
		getline(cin, q);

		if(q == "Q")
			break;
		
		if(q == "P"){
			cout << "Enter your price: ";
			getline(cin, q);
			if(q == ""){
				cout << "Bad query\n";
				continue;
			}

			int price;
			stringstream convert(q);
			if(!(convert >> price)){
				cout << "Bad query, not a price\n";
				continue;
			}

			//db.findByPrice(price);
		}

		if(q == "B"){
			cout << "Enter the brand: ";
			getline(cin, q);
			if(q == ""){
				cout << "Bad query\n";
				continue;
			}
			db.findByBrand(q);
		}
	}

	return 0;
}
