#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

inline uint16_t getLinePriorityPart1(std::string inputLine);
uint16_t getLinePriorityPart2(std::string inputLine, uint64_t* commonBadgeSack, int lineCount);
inline uint16_t getCharPrioity(uint64_t inputChar);

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

	int totalPriorityPart1 = 0, totalPriorityPart2 = 0, lineCount = 0;
	uint64_t commonBadgeSack = 0;
	std::string line;
	while (std::getline(input_file, line))
	{
		totalPriorityPart1 += getLinePriorityPart1(line);
		totalPriorityPart2 += getLinePriorityPart2(line, &commonBadgeSack, ++lineCount);
	}

	std::cout << "Part 1: ";
	std::cout << totalPriorityPart1 << std::endl;

	std::cout << "Part 2: ";
	std::cout << totalPriorityPart2 << std::endl;

	input_file.close();

	return 0;
}


inline uint16_t getLinePriorityPart1(std::string inputLine)
{
	int compartmentSize = static_cast<int>(inputLine.length()) / 2;
	uint64_t firstCompartment = 0, secondCompartment = 0;

	for (int i = 0; i < compartmentSize; i++)
	{
		firstCompartment |= static_cast<unsigned long long>(1) << (inputLine[i] - 'A');
		secondCompartment |= static_cast<unsigned long long>(1) << (inputLine[i + compartmentSize] - 'A');
	}

	return getCharPrioity(firstCompartment & secondCompartment);
}

uint16_t getLinePriorityPart2(std::string inputLine, uint64_t *commonBadgeSack, int lineCount)
{
	int rucksackSize = static_cast<int>(inputLine.length());
	uint64_t currentSack = 0;

	for (int i = 0; i < rucksackSize; i++)
	{
		currentSack |= static_cast<unsigned long long>(1) << (inputLine[i] - 'A');
	}

	switch (lineCount % 3)
	{
	case 0:
		return getCharPrioity(*commonBadgeSack & currentSack);
		break;
	case 1:
		*commonBadgeSack = currentSack;
		break;
	default:
		*commonBadgeSack &= currentSack;
		break;
	}

	return 0;
}

inline uint16_t getCharPrioity(uint64_t inputSack)
{
	unsigned long rucksackItemBitLocation;
	_BitScanForward64(&rucksackItemBitLocation, inputSack);

	char commonCharacter = static_cast<char>(rucksackItemBitLocation + 'A');
	uint16_t priority = commonCharacter < 'a' ? ((commonCharacter - 'A') + 1) + (('Z' - 'A') + 1) : (commonCharacter - 'a') + 1;

	return priority;
}