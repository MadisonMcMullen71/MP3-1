#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

using namespace std;

// converting liters to gallons
double toGallons(double amount, char unit) {
	const double LITERSPERGALLON = 0.26417205;
	if (unit == 'l' || unit == 'L') {
		return amount * LITERSPERGALLON;
	}
	return amount;
}

// calculating fill up cost
double fillUpCost(double amount, double pricePerUnit) {
	double totalcost;
	totalcost = amount * pricePerUnit;
	return totalcost;
}
 
// calculating miles per gallon
double milesPerGallon(double miles, double gallons) {
	double mpgVal;
	mpgVal = miles / gallons;
	return mpgVal;
}

// calculating cost per mile
double costPerMile(double cost, double miles) {
	double cpmVal;
	cpmVal = cost / miles;
	return cpmVal;
}

// calculating sum of array
double sumOf(double values[], int count) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum = sum + values[i];
	}
	return sum;
}

// smallest
int indexOfSmallest(double values[], int count) {
	int smallest = 0;
	for (int i = 1; i < count; i++) {
		if (values[i] < values[smallest]) {
			smallest = i;
		}
	}
	return smallest;
}

// largest
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
	const int MIN_FILLUPS = 1;
	int numberFillups = 0;
	int odometer[MAX_FILLUPS + 1];
	double amount[MAX_FILLUPS];
	char unit[MAX_FILLUPS];
	double pricePerUnit[MAX_FILLUPS];
	double miles[MAX_FILLUPS];
	double cost[MAX_FILLUPS];
	int totalspent[MAX_FILLUPS];
	double gallons[MAX_FILLUPS];
	double mpg[MAX_FILLUPS];
	double cpm[MAX_FILLUPS];
	double budget;

	// have user give starting odometer
	cout << "Enter starting odometer: ";
	cin >> odometer[0];

	while (true) {
		cout << "Enter number of fill ups (1-20): ";
		cin >> numberFillups;
		if (numberFillups <= MAX_FILLUPS && numberFillups >= MIN_FILLUPS) {
			break;
		}
		else {
			cout << "Number does not fall into range" << endl;
		}
	}

	// have user give budget for trip
	cout << "Enter fuel budget for trip: ";
	cin >> budget;

	// Have user enter literally all the inputs
	for (int i = 0; i < numberFillups; i++) {
		cout << "Fill-up " << i + 1 << " (odometer, amount, G or L, price, total): ";
		cin >> odometer[i + 1] >> amount[i] >> unit[i] >> pricePerUnit[i] >> totalspent[i];

		// if they give the wrong unit
		if (unit[i] != 'l' && unit[i] != 'L' && unit[i] != 'g' && unit[i] != 'G') {
			cout << "Unit must be L or G" << endl;
		}
		else if (odometer[i + 1] <= odometer[i]) {
			cout << "Odometer had to be bigger than previous odometer input" << endl;
		}

		// calculating miles, cost, miles per gallon, cost per mile
		gallons[i] = toGallons(amount[i], unit[i]);
		miles[i] = odometer[i + 1] - odometer[i];
		cost[i] = fillUpCost(amount[i], pricePerUnit[i]);
		mpg[i] = milesPerGallon(miles[i], gallons[i]);
		cpm[i] = costPerMile(cost[i], miles[i]);
	}

	// Fuel log report
	printf("\n");
	printf("%-8s %10s %10s %10s %10s %15s\n", "Leg", "Miles", "Gallons", "MPG", "Cost", "Cost/mile");

	for (int i = 0; i < numberFillups; i++) {
		printf("%-8d %10.1f %10.2f %10.1f %10.2f %15.3f\n",
			i + 1, miles[i], gallons[i], mpg[i], cost[i], cpm[i]);
	}
	

	// totals of trip and summary
	double totalMiles = sumOf(miles, numberFillups);
	double totalGallons = sumOf(gallons, numberFillups);
	double totalCost = sumOf(cost, numberFillups);
	double overallMPG = milesPerGallon(totalMiles, totalGallons);
	double overallCostPerMile = costPerMile(totalCost, totalMiles);

	printf("\n");
	printf("Total Miles:          %.1f\n", totalMiles);
	printf("Total Gallons:        %.2f\n", totalGallons);
	printf("Overall MPG:          %.1f\n", overallMPG);
	printf("Total Fuel Cost:      $%.2f\n", totalCost);
	printf("Overall cost per mile: $%.3f\n", overallCostPerMile);

	int cheapest = indexOfSmallest(cpm, numberFillups);
	int expensive = indexOfLargest(cpm, numberFillups);

	printf("\n");
	printf("Cheapest leg per mile: Leg %d ($%.3f)\n", cheapest + 1, cpm[cheapest]);
	printf("Most expensive leg per mile: Leg %d ($%.3f)\n", expensive + 1, cpm[expensive]);

	printf("\n");
	if (totalCost < budget) {
		printf("Trip was under budget by $%.2f\n", budget - totalCost);
	}
	else if (totalCost > budget) {
		printf("Trip was over budget by $%.2f\n", totalCost - budget);
	}
	else {
		printf("Trip was exactly on budget!\n");
	}

	return 0;
}


