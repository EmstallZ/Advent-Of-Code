#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

namespace fs = std::filesystem;

void fillPairArray(std::string inputLine, int outputArray[2][2]);
bool isPairIntersected(std::string inputLine);
bool isPairOverlapping(std::string inputLine);

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

	int pairsIntersectingOther = 0;
	int pairsOverlappingOther = 0;
	std::string line;
	while (std::getline(input_file, line))
	{
		pairsIntersectingOther += isPairIntersected(line);
		pairsOverlappingOther += isPairOverlapping(line);
	}

	std::cout << "Part 1: ";
	std::cout << pairsIntersectingOther << std::endl;

	std::cout << "Part 2: ";
	std::cout << pairsOverlappingOther << std::endl;

	input_file.close();

	return 0;
}

bool isPairIntersected(std::string inputLine)
{
	// Pair array
	int arr[2][2];
	fillPairArray(inputLine, arr);

	if ((arr[0][0] <= arr[1][0] && arr[1][1] <= arr[0][1]) || (arr[1][0] <= arr[0][0] && arr[0][1] <= arr[1][1]))
	{
		return true;
	}

	return false;
}

bool isPairOverlapping(std::string inputLine)
{
	// Pair array
	int arr[2][2];
	fillPairArray(inputLine, arr);

	if (std::max(arr[0][0], arr[1][0]) <= std::min(arr[0][1], arr[1][1]))
	{
		return true;
	}

	return false;
}

void fillPairArray(std::string inputLine, int outputArray[2][2])
{
	char placeholder = 0;
	std::istringstream(inputLine) >> outputArray[0][0] >> placeholder >> outputArray[0][1] >> placeholder >> outputArray[1][0] >> placeholder >> outputArray[1][1];
}