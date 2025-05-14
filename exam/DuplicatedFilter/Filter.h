#pragma once

#include "WaterPressurePoints.h"
#include <vector>
#include <string>
#include <string_view>

class Filter
{
public:
	Filter(std::string_view filename) : mOutputFile(filename) {}
	void WriteWaterPressure(const std::vector<WaterPressurePoints>& points);

private:
	void Dump(const std::vector<WaterPressurePoints>& points) const;
	
	std::string mOutputFile;
};

