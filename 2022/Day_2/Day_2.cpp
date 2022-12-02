#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

int getLineScorePart1(std::string inputLine);
int getLineScorePart2(std::string inputLine);

const int scoreList[3][3] = {	{4, 8, 3},
								{1, 5, 9},
								{7, 2, 6}	};

const int offsetTable[3][3] = {	{2, 0, 1},
								{0, 1, 2},
								{1, 2, 0} };

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

	int totalScorePart1 = 0;
	int totalScorePart2 = 0;
	std::string line;
	while (std::getline(input_file, line))
	{
		if (line.empty())
		{
			break;
		}
		totalScorePart1 += getLineScorePart1(line);
		totalScorePart2 += getLineScorePart2(line);
	}

	std::cout << "Part 1: ";
	std::cout << totalScorePart1 << std::endl;

	std::cout << "Part 2: ";
	std::cout << totalScorePart2 << std::endl;
	

	input_file.close();
	return 0;
}

int getLineScorePart1(std::string inputLine)
{
	int score = scoreList[inputLine[0] - 'A'][inputLine[2] - 'X'];
	return score;
}

int getLineScorePart2(std::string inputLine)
{
	int score = scoreList[inputLine[0] - 'A'][offsetTable[inputLine[0] - 'A'][inputLine[2] - 'X']];
	return score;
}

// Part 1:
// 1 for Rock, 2 for Paper, and 3 for Scissors)
// (0 if you lost, 3 if the round was a draw, and 6 if you won).
//		V----------|   V-----------|
// AX ROCK (1), BY PAPER (2), CZ SCISSOR (3)
//     |----------------------------^
// A, B, C, X, Y, Z

// Part 2:
// X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win
