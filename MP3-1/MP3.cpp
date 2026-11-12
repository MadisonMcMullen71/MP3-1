#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//converting liters to gallons
double toGallons(double amount, char unit) {
	const double LITERSPERGALLON = 0.26417205;
	if (unit == 'i' || unit == 'L') {
		amount = amount * LITERSPERGALLON;
		return amount;
	}
}

//calculating fill up cost
double fillUpCost(double amount, double pricePerUnit) {
	double totalcost;
	totalcost = amount * pricePerUnit;
	return totalcost;
}

//calculating miles per gallon
double milesPerGallon(double miles, double gallons) {
	double costPerGallon;
	costPerGallon = miles / gallons;
	return costPerGallon;
}

//calculating cost per mile
double costPerMile(double cost, double miles) {
	double costPerMile;
	costPerMile = cost / miles;
	return costPerMile;
}




int main() {
	double amount;
	char unit;
	double pricePerUnit;
	double miles;
	double cost;
	
	cin >> amount >> unit >> pricePerUnit >> miles;
	cout << toGallons(amount, unit) << endl;
	double gallons = toGallons(amount, unit);
	cout << fillUpCost(amount, pricePerUnit);

	cout << milesPerGallon(miles, gallons);


}
