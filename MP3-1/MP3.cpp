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

int main() {
	double amount;
	char unit;
	double pricePerUnit;
	cin >> amount >> unit >> pricePerUnit;
	cout << toGallons(amount, unit) << endl;
	cout << fillUpCost(amount, pricePerUnit);


}
