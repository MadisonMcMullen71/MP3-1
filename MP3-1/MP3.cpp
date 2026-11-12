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

//calculating sum of array
double sumOf(double values[], int count) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum = sum + values[i];
	}
	return sum;
}

//smallest
int indexOfSmallest(double values[], int count) {
	int smallest = 0;
	for (int i = 1; i < count; i++) {
		if (values[i] < values[smallest]) {
			smallest = i;
		}
	}
	return smallest;
}

//largest 
int indexOfLargest(double values[], int count) {
	int largest = 0;
	for (int i = 1; i < count; i++) {
		if (values[i] > values[largest]) {
			largest = i;
		}
	}
	return largest;
}


int main() {
	const int MAX_FILLUPS = 20;
	double amount;
	char unit;
	double pricePerUnit;
	double miles;
	double cost;
	double values[MAX_FILLUPS] = { 1, 1, 1, };
	int count = 3;
	
	
	//cin >> amount >> unit >> pricePerUnit >> miles;
	//cout << toGallons(amount, unit) << endl;
	//double gallons = toGallons(amount, unit);
	//cout << fillUpCost(amount, pricePerUnit);

	//cout << milesPerGallon(miles, gallons);
	

	cout << sumOf(values, count);
	cout << indexOfSmallest(values, count);
	cout << indexOfLargest(values, count);
	return 0;
}
