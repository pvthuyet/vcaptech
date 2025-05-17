#include "pch.h"
#include "CModel.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

CModel::CModel(const std::string& filePath)
	: m_filePath(filePath)
{
    load();
}

CModel::~CModel()
{
	save();
}

void CModel::load()
{
	json js;
	if (fs::exists(m_filePath)) {
		std::ifstream f(m_filePath);
		js = json::parse(f);
	}
	else {
		// init default data
		js = json::parse(R"(
		  {
			"ground_water_method": { "data": ["Static Water", "Steady FEA", "Transient FEA"], "selected": 0 },
			"thermal_method": { "data": ["Static Temperature", "Steady Thermal FEA", "Transient Thermal FEA"], "selected": 0 }
		  }
		)");
	}

	loadFromJson(js["ground_water_method"], m_groundWaterMethods, m_gwmSelectedIndex);
	loadFromJson(js["thermal_method"], m_thermalMethods, m_thrSelectedIndex);
}

void CModel::loadFromJson(json js, std::vector<std::string>& outVec, int& selectedIndex)
{
	selectedIndex = js["selected"].template get<int>();
	auto data = js["data"];
	outVec.reserve(data.size());
	for (auto& el : data.items()) {
		outVec.push_back(el.value());
	}

	selectedIndex = std::min<int>(selectedIndex, outVec.size() - 1);
}

json CModel::convertToJson(const std::vector<std::string>& inVec, int selectedIndex)
{
	json js;
	js["selected"] = selectedIndex;
	js["data"] = json(inVec);
	return js;
}

void CModel::save()
{
	json js;
	js["ground_water_method"] = convertToJson(m_groundWaterMethods, m_gwmSelectedIndex);
	js["thermal_method"] = convertToJson(m_thermalMethods, m_thrSelectedIndex);
	
	std::ofstream ofs(m_filePath);
	ofs << js;
}