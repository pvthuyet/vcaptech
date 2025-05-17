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

    std::vector<std::string> getGroundWaterMethods() const { return m_groundWaterMethods; }
    int getGroundWaterMethodSelectedIndex() const { return m_gwmSelectedIndex; }
    void setGroundWaterMethodSelectedIndex(int index) { m_gwmSelectedIndex = index; }
    std::string getGroundWaterMethodSelected() const { return m_groundWaterMethods[m_gwmSelectedIndex]; }

    std::vector<std::string> getThermalMethods() const { return m_thermalMethods; }
    int getThermalMethodSelectedIndex() const { return m_thrSelectedIndex; }
    void setThermalMethodSelectedIndex(int index) { m_thrSelectedIndex = index; }
    std::string getThermalMethodSelected() const { return m_thermalMethods[m_thrSelectedIndex]; }


private:
	void load();
	void save();

	void loadFromJson(json js, std::vector<std::string>& outVec, int& selectedIndex);
	json convertToJson(const std::vector<std::string>& inVec, int selectedIndex);

	std::string m_filePath;
	std::vector<std::string> m_groundWaterMethods;
	int m_gwmSelectedIndex = 0;
	std::vector<std::string> m_thermalMethods;
	int m_thrSelectedIndex = 0;
};

