#include "Filter.h"
#include <iostream>
#include <algorithm>
#include <fstream>

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

void Filter::Dump(const std::vector<WaterPressurePoints>& points) const
{
	std::ofstream ofs(mOutputFile);

	for (const auto& p : points) {
		auto wp = roundToDecimal(p.water_pressure);
		ofs << p.x << " " << p.y << " " << wp << std::endl;
	}
}
