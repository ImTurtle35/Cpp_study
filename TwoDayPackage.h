// 12191706 ±èÁ¤Áø
// TwoDayPackage class definition
#pragma once
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
#include <string>

class TwoDayPackage : public Package {
public:
	TwoDayPackage(const std::string& sn, int sa, const std::string& sc, const std::string& ss, const std::string& szc, const std::string& rn, int ra,
		const std::string& rc, const std::string& rs, const std::string& rzc, double w, double cpo, double ff)
		:Package(sn, sa, sc, ss, szc, rn, ra, rc, rs, rzc, w, cpo) {
		flat_fee = ff;
	}
	
	double calculateCost() const {
		return flat_fee + Package::calculateCost();
	}

private:
	double flat_fee;
};

#endif TWODAYPACKAGE_H
