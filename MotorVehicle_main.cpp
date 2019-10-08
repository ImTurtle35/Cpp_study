// 12191706 ±èÁ¤Áø
// Chpater 10 - 10.8
// test program to demonstrate MotorVehicle's capabilities.
#include <string>
#include <iostream>
#include "MotorVehicle.h" // MotorVehicle class definition
using namespace std;

int main() {
	string company, fuel_name, car_color;
	int made_year, engine_dur;

	// new car has been created and display it's information
	MotorVehicle newmotor("HD", 2000, 50);
	cout << "New MotorVehicle has been created.\n";
	newmotor.displayCarDetails();

	// input new car's information
	cout << "Fill in newmotor's make : ";
	cin >> company;
	newmotor.setMake(company);

	cout << "Fill in newmotor's fuelType : ";
	cin >> fuel_name;
	newmotor.setFuelType(fuel_name);

	cout << "Fill in newmotor's yearOfManufacture : ";
	cin >> made_year;
	newmotor.setYearOfManufacture(made_year);

	cout << "Fill in newmotor's color : ";
	cin >> car_color;
	newmotor.setColor(car_color);

	cout << "Fill in newmotor's engineCapacity : ";
	cin >> engine_dur;
	newmotor.setEngineCapacity(engine_dur);

	// display new car's information
	newmotor.displayCarDetails();
}
