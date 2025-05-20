#pragma once

#include <cmath>
#include <limits>
#include <functional>

constexpr const double EPSILON = std::numeric_limits<double>::epsilon();

inline bool areApproximatelyEqual(double a, double b) {
	return std::fabs(a - b) < EPSILON;
}

inline double roundToDecimal(double value, int numberDecimal = 3) {
	const double factor = std::pow(10, numberDecimal);
	return std::round(value * factor) / factor;
}

struct WaterPressurePoints {
	double x;
	double y;
	double water_pressure;

	bool operator==(const WaterPressurePoints& other) const noexcept {
		return areApproximatelyEqual(x, other.x) && areApproximatelyEqual(y, other.y);
	}
};

// Hash specialization
namespace std {
    template <>
    struct hash<WaterPressurePoints> {
        std::size_t operator()(const WaterPressurePoints& p) const {
            auto quantize = [](double value) {
                // Quantize the value to a grid to help with approximate comparisons
                return static_cast<std::size_t>(value / EPSILON);
            };

            std::size_t h1 = std::hash<std::size_t>{}(quantize(p.x));
            std::size_t h2 = std::hash<std::size_t>{}(quantize(p.y));

            // Combine hashes
            return h1 ^ (h2 << 1); // simple hash combining technique
        }
    };
}