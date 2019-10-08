// 12191706 ±èÁ¤Áø
// Chpater 10 - 10.8
// MotorVehicle class definition.
#pragma once
#include <iostream>
#include <string>

// prevent multiple inclusions of header
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

class MotorVehicle {
	friend std::ostream& operator<<(std::ostream&, const MotorVehicle&); // overloaded output operator

public:
	explicit MotorVehicle(std::string ,int ,int); // constructor with three data member

	void setMake(std::string); // set make function
    std::string getMake() const; // get make function

	void setFuelType(std::string); // set fuelType function
	std::string getFuelType() const; // get fuelType function

	void setYearOfManufacture(int); // set yearOfManufacture function
	int getYearOfManufacture() const; // get yearOfManufacture function

	void setColor(std::string); // set color function
	std::string getColor() const; // get color function

	void setEngineCapacity(int); // set engineCapacity function
	int getEngineCapacity() const; // get engineCapacity function

	void displayCarDetails(); // display data members function

	bool operator==(const MotorVehicle&) const; // equaility operator
	bool operator!=(const MotorVehicle&) const; // inequaility operator

	bool operator>(const MotorVehicle&) const; // greater than operator

private:
	std::string make;
	std::string fuelType;
	int yearOfManufacture;
	std::string color;
	int engineCapacity;
};

#endif // !MOTORVEHICLE_H

