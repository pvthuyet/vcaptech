#pragma once

#include <cmath>

constexpr const double EPSILON = 1e-9;

inline bool areApproximatelyEqual(double a, double b) {
	return std::fabs(a - b) < EPSILON;
}

inline double roundTo3DecimalPlaces(double value) {
	return std::round(value * 1000.0) / 1000.0;
}

struct WaterPressurePoints {
	double x;
	double y;
	double water_pressure;

	bool operator==(const WaterPressurePoints& other) {
		return areApproximatelyEqual(x, other.x) && areApproximatelyEqual(y, other.y);
	}
};