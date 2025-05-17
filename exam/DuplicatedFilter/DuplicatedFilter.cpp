// DuplicatedFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Filter.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<WaterPressurePoints> points = {
		{0, 0, 0},
		{0, 0, 15},
		{1e-19, 0, 10},
		{0.5, 0, 25.123},
		{0.1, 10, 25}
	};

	std::string filename = "WaterPressure.txt";

	Filter filter(filename);
	filter.WriteWaterPressure(points);

	std::cout << "The output file: " << filename << std::endl;
	std::cout << "Press Enter to stop the application..." << std::endl;
	std::cin.get();  // Waits until Enter is pressed
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
