#include <string>
#include "Car.h"

using namespace std;

// Initialization list for improved performance
Car::Car(string d_brand) : brand(d_brand) { }
Car::Car(string d_brand, string d_model, int d_year, int d_price) : brand(d_brand), model(d_model), year(d_year), price(d_price), lastViewed("never") { }

bool operator==(const Car& c1, const Car& c2)
{
	return c1.brand == c2.brand;
}

std::ostream& operator<<(std::ostream& s, const Car& c){
	return s << "Brand: " << c.brand << "\nModel: " << c.model << "\nYear: " << c.year << "\nPrice: " << c.price << "\n(Last viewed: " << c.lastViewed << ")\n";
}