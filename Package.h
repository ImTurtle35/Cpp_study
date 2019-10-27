// 12191706 ±èÁ¤Áø
// Package class definition
#pragma once
#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <stdexcept>

class Package {
public:
	// cosntructor
	Package(const std::string& sn, int sa, const std::string& sc, const std::string& ss, const std::string& szc, const std::string& rn, int ra,
		const std::string& rc, const std::string& rs, const std::string& rzc, double w, double cpo)
		: sender_name{ sn }, sender_address{ sa }, sender_city{ sc }, sender_state{ ss }, sender_zip_code{szc},
		recipient_name{ rn }, recipient_address{ ra }, recipient_city{ rc }, recipient_state{ rs }, recipient_zip_code{ rzc } {
		
		// ensure that the weight and cost per ounce contain positive values.
		if (w >= 0 || cpo >= 0) {
			weight = w;
			cost_per_ounce = cpo;
		}
		else {
			throw std::invalid_argument("The value is not positive.");
		}
	}

	// calculate cost
	double calculateCost() const{
		return weight * cost_per_ounce;
	}

protected:
	std::string sender_name;
	int sender_address;
	std::string sender_city;
	std::string sender_state;
	std::string sender_zip_code;
	std::string recipient_name;
	int recipient_address;
	std::string recipient_city;
	std::string recipient_state;
	std::string recipient_zip_code;
	double weight;
	double cost_per_ounce;
};

#endif PACKAGE_H
