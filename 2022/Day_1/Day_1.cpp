#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

fs::path FilePath = "input";

int main()
{
	std::fstream input_file;
	input_file.open(FilePath.c_str(), std::ios::in);

	if (!input_file.is_open())
	{
		std::cerr << "Could not open file..." << std::endl;
		return 0;
	}

	std::vector<int> elfCaloriesList;
	int calorieCount = 0;
	std::string line;
	while (std::getline(input_file, line))
	{
		if (line.empty())
		{
			elfCaloriesList.push_back(calorieCount);
			calorieCount = 0;
		}
		else
		{
			calorieCount += std::stoi(line);
		}
	}

	std::cout << "Part 1: ";
	std::cout << *std::max_element(elfCaloriesList.begin(), elfCaloriesList.end()) << std::endl;

	// Part 2
	std::sort(elfCaloriesList.begin(), elfCaloriesList.end(), std::greater<>());
	std::cout << "Part 2: " << elfCaloriesList.at(0) + elfCaloriesList.at(1) + elfCaloriesList.at(2) << std::endl;

	input_file.close();
	return 0;
}

//This list represents the Calories of the food carried by five Elves :
//
//The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
//The second Elf is carrying one food item with 4000 Calories.
//The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
//The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
//The fifth Elf is carrying one food item with 10000 Calories.
