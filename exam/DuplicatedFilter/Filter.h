#pragma once

#include "WaterPressurePoints.h"
#include <vector>
#include <string>
#include <string_view>
#include <iostream>

class Filter
{
public:
	Filter(std::string_view filename) : mOutputFile(filename) {}

	void WriteWaterPressure(const std::vector<WaterPressurePoints>& points);
	void WriteWaterPressure_improve(const std::vector<WaterPressurePoints>& points);

private:
	template<class Container>
	void Dump(const Container& points) const
	{
		std::ofstream ofs(mOutputFile);

		for (const auto& p : points) {
			auto wp = roundToDecimal(p.water_pressure);
			ofs << p.x << " " << p.y << " " << wp << std::endl;
		}
	}
	
	std::string mOutputFile;
};

