#include "Filter.h"
#include <algorithm>
#include <fstream>
#include <unordered_set>

void Filter::WriteWaterPressure(const std::vector<WaterPressurePoints>& points)
{
	std::vector<WaterPressurePoints> result;
	result.reserve(points.size());

	auto isExisted = [&](const WaterPressurePoints& p) -> bool {
			auto found = std::find(result.begin(), result.end(), p);
			return found != result.end();
		};

	for (const auto& p : points) {
		if (!isExisted(p)) {
			result.push_back(p);
		}
	}

	Dump(result);
}

void Filter::WriteWaterPressure_improve(const std::vector<WaterPressurePoints>& points)
{
	std::unordered_set<WaterPressurePoints> result;
	result.reserve(points.size());

	for (const auto& p : points) {
		result.insert(p);
	}

	Dump(result);
}
