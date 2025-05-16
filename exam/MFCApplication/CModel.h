#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class CModel final
{
public:
	CModel(const std::string& filePath);
	~CModel();

	void load();
	void save();

private:
	void loadFromJson(json js, std::vector<std::string>& outVec, int& selectedIndex);
	json convertToJson(const std::vector<std::string>& inVec, int selectedIndex);

	std::string m_filePath;
	std::vector<std::string> m_groundWaterMethods;
	int m_gwmSelectedIndex = 0;
	std::vector<std::string> m_thermalMethods;
	int m_thrSelectedIndex = 0;
};

