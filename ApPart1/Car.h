#include <string>

using namespace std;

class Car
{
public:
	string brand;
	string model;
	int year;
	int price;

	string lastViewed;


	Car(string brand);
	Car(string brand, string model, int year, int price);

	friend bool operator== (const Car& c1, const Car& c2);
};

std::ostream& operator<<(ostream&, const Car&);