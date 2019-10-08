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
	cout << "New MotorVehicle has been created.\n"
		<< "Display information by displayCarDetails function.";
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

	// display new car's information by output operator(<<)
	cout << "\nDisplay information by output operator." << newmotor;

	// another new car has been created.
	MotorVehicle anothermotor("BMW", 2010, 1);
	cout << "Another new MotorVehicle has been created.\n";

	// input anothercar's information
	cout << "Fill in anothermotor's make : ";
	cin >> company;
	anothermotor.setMake(company);

	cout << "Fill in anothermotor's fuelType : ";
	cin >> fuel_name;
	anothermotor.setFuelType(fuel_name);

	cout << "Fill in anothermotor's yearOfManufacture : ";
	cin >> made_year;
	anothermotor.setYearOfManufacture(made_year);

	cout << "Fill in anothermotor's color : ";
	cin >> car_color;
	anothermotor.setColor(car_color);

	cout << "Fill in anothermotor's engineCapacity : ";
	cin >> engine_dur;
	anothermotor.setEngineCapacity(engine_dur);

	// display new car's information by output operator(<<)
	cout << "\nDisplay information by output operator." << newmotor;

	// compare new car and another car and display greater one. (which was manufactured before than other)
	if (newmotor == anothermotor)
		cout << "Both motors are same model.\n";
	else if (newmotor != anothermotor) {
		cout << "Both motors are not same model.\nDisplay greater motor's information.\n";
		if (newmotor > anothermotor)
			cout << "Greater motor is newmotor." << newmotor;
		else if(anothermotor > newmotor)
			cout << "Greater motor is anothermotor." << anothermotor;
		else
			cout << "Both motors are not same model, but they are both great."
	}
}
