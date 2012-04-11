#include <map>
#include <vector>
#include "Car.h"

using namespace std;

class CarDB
{
public:
	typedef vector<Car>::iterator VCI;

private:
	bool indexOutOfDate;
	vector<Car> cars;
	multimap<int, VCI> priceIndex;

	void clearIndices();
	string now();

public:
	CarDB();
	CarDB(vector<Car> cars);

	void addCarToDB(Car c);
	void makeIndices();
	void findByBrand(string& brand); 
	void findByPrice(const int p);
};