#pragma once

#include "WaterPressurePoints.h"
#include <vector>

class Filter
{
public:
	void WriteWaterPressure(const std::vector<WaterPressurePoints>& points);

private:
	void Dump(const std::vector<WaterPressurePoints>& points) const;
};

