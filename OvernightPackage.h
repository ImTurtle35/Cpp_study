// 12191706 ±èÁ¤Áø
// OvernightPackage class definition
// derived from class Package
#pragma once
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package{
public:
	// constructor
	OvernightPackage(const std::string& sn, int sa, const std::string& sc, const std::string& ss, const std::string& szc, const std::string& rn, int ra,
		const std::string& rc, const std::string& rs, const std::string& rzc, double w, double cpo, double afpo)
		// explicitly call base-class constructor
		:Package(sn, sa, sc, ss, szc, rn, ra, rc, rs, rzc, w, cpo) {
		additional_fee_per_ounce = afpo; // store additional_fee_per_ounce
	}

	// calculate cost
	double calculateCost() const{
		return (cost_per_ounce + additional_fee_per_ounce) * weight;
	}

private:
	double additional_fee_per_ounce;
};

#endif OVERNIGHTPACKAGE_H
