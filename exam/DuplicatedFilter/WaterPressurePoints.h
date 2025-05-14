#pragma once

#include <cmath>

constexpr const double EPSILON = 1e-9;

inline bool areApproximatelyEqual(double a, double b) {
	return std::fabs(a - b) < EPSILON;
}

inline double roundToDecimal(double value, int numberDecimal = 3) {
	double factor = std::pow(10, numberDecimal);
	return std::round(value * factor) / factor;
}

struct WaterPressurePoints {
	double x;
	double y;
	double water_pressure;

	bool operator==(const WaterPressurePoints& other) {
		return areApproximatelyEqual(x, other.x) && areApproximatelyEqual(y, other.y);
	}
};