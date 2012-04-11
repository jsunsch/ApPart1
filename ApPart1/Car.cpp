#include <string>
#include "Car.h"

using namespace std;

// Initialization list for improved performance
Car::Car(string pBrand, string pModel, int pYear, int pPrice) : brand(pBrand), model(pModel), year(pYear), price(pPrice)
{
}