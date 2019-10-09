// 12191706 ±èÁ¤Áø
// Chapter 10 - 10.8
// Member-function definitions for class MotorVehicle.
#include "MotorVehicle.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor that initializes the three data members
MotorVehicle::MotorVehicle (string company, int madeyear, int engine_dur)
: make{ company }, yearOfManufacture{ madeyear }, engineCapacity{ engine_dur } {}

// function to set the Car make
void MotorVehicle::setMake(string company) {
	make = company;
}

// function to retrieve the Car make
string MotorVehicle::getMake() const {
	return make;
}

// function to set the Car fuelType
void MotorVehicle::setFuelType(string fuel_name) {
	fuelType = fuel_name;
}

// function to retrieve the Car fuelType
string MotorVehicle::getFuelType() const {
	return fuelType;
}

// function to set the Car yearOfManufacture
void MotorVehicle::setYearOfManufacture(int made_year) {
	yearOfManufacture = made_year;
}

// function to retrieve the Car yearOfManufacture
int MotorVehicle::getYearOfManufacture() const {
	return yearOfManufacture;
}

// function to set the Car color
void MotorVehicle::setColor(string car_color) {
	color = car_color;
}

// function to retrieve the Car color
string MotorVehicle::getColor() const {
	return color;
}

// function to set the Car engineCapacity
void MotorVehicle::setEngineCapacity(int engine_dur) {
	engineCapacity = engine_dur;
}

// function to retrieve the Car engineCapacity
int MotorVehicle::getEngineCapacity() const {
	return engineCapacity;
}

// displays the five data members in five separate lines in the form "member name: member value"
void MotorVehicle::displayCarDetails() {
	cout << "\nmake : " << getMake()
		<< "\nfuelType : " << getFuelType()
		<< "\nyearOfManufacture : " << getYearOfManufacture()
		<< "\ncolor : " << getColor()
		<< "\nengineCapacity : " << getEngineCapacity() << endl << endl;
}

bool MotorVehicle::operator==(const MotorVehicle& right) const {
	if (make != right.make || fuelType != right.fuelType || yearOfManufacture != right.yearOfManufacture || color != right.color || engineCapacity != right.engineCapacity) {
		return false;
	}
	return true;
}

bool MotorVehicle::operator!=(const MotorVehicle& right) const {
	return !(*this == right);
}

bool MotorVehicle::operator>(const MotorVehicle& right) const {
	if (yearOfManufacture < right.yearOfManufacture) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& output, const MotorVehicle& obj) {
	output << "\nmake : " << obj.getMake()
		<< "\nfuelType : " << obj.getFuelType()
		<< "\nyearOfManufacture : " << obj.getYearOfManufacture()
		<< "\ncolor : " << obj.getColor()
		<< "\nengineCapacity : " << obj.getEngineCapacity() << endl << endl;
	return output;
}