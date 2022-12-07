#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <stack>

namespace fs = std::filesystem;

void moveCratesPart1(std::string inputLine, std::vector<std::stack<char>> &outputVector);
void moveCratesPart2(std::string inputLine, std::vector<std::stack<char>> &outputVector);
std::string getTopCrates(std::vector<std::stack<char>> &outputVector);

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

	std::vector<std::stack<char>> crateVectorPart1;
	std::vector<std::stack<char>> crateVectorPart2;
	std::vector<std::string> crateInputString;
	std::stringstream crateInputStream;
	bool isInputParsed = false;
	std::string line;
	while (std::getline(input_file, line))
	{
		if (!isInputParsed)
		{
			if (line.empty())
			{
				// Row-major order to Column-major order
				for (int i = 0; i < crateInputString.at(1).length(); i++)
				{
					for (int j = 0; j < crateInputString.size(); j++)
					{
						char inputChar = crateInputString.at(j).c_str()[i];
						if (isalnum(inputChar))
						{
							crateInputStream << inputChar;
						}
					}
				}

				// Put characters (crates) from input stream on the stack, for each stack
				std::stack<char> crateStackReversed;
				for (int i = 0; i < crateInputStream.str().length(); i++)
				{
					char inputChar;
					crateInputStream >> inputChar;
					if (isalpha(inputChar))
					{
						crateStackReversed.push(inputChar);
					}
					else if (isdigit(inputChar))
					{	
						// Reverse stack and push stack onto crate vector
						std::stack<char> crateStackOrdered;
						while (!crateStackReversed.empty())
						{
							crateStackOrdered.push(crateStackReversed.top());
							crateStackReversed.pop();
						}
						crateVectorPart1.push_back(crateStackOrdered);
					}
				}
				crateVectorPart2 = crateVectorPart1;
				isInputParsed = true;
			}
			else
			{
			crateInputString.push_back(line);
			}
		}
		else
		{
		moveCratesPart1(line, crateVectorPart1);
		moveCratesPart2(line, crateVectorPart2);
		}


	}

	std::cout << "Part 1: ";
	std::cout << getTopCrates(crateVectorPart1) << std::endl;

	std::cout << "Part 2: ";
	std::cout << getTopCrates(crateVectorPart2) << std::endl;

	input_file.close();

	return 0;
}

void moveCratesPart1(std::string inputLine, std::vector<std::stack<char>> &outputVector)
{
	// [0] Amount to move
	// [1] From (index + 1)
	// [2] To (index + 1)
	int instruction[3]{};
	std::string placeholder;
	std::istringstream(inputLine) >> placeholder >> instruction[0] >> placeholder >> instruction[1]>> placeholder >> instruction[2];

	for (int i = 0; i < instruction[0]; i++)
	{
		if (outputVector.at(instruction[1]-1).empty())
		{
			break;
		}
		outputVector.at(instruction[2]-1).push(outputVector.at(instruction[1]-1).top());
		outputVector.at(instruction[1]-1).pop();
	}
}

void moveCratesPart2(std::string inputLine, std::vector<std::stack<char>> &outputVector)
{
	// [0] Amount to move
	// [1] From (index + 1)
	// [2] To (index + 1)
	int instruction[3]{};
	std::string placeholder;
	std::stack<char> reversedStack;
	std::istringstream(inputLine) >> placeholder >> instruction[0] >> placeholder >> instruction[1] >> placeholder >> instruction[2];

	for (int i = 0; i < instruction[0]; i++)
	{
		if (outputVector.at(instruction[1] - 1).empty())
		{
			break;
		}
		reversedStack.push(outputVector.at(instruction[1] - 1).top());
		outputVector.at(instruction[1] - 1).pop();
	}

	while (!reversedStack.empty())
	{
		outputVector.at(instruction[2] - 1).push(reversedStack.top());
		reversedStack.pop();
	}
}

std::string getTopCrates(std::vector<std::stack<char>> &outputVector)
{
	std::string outputString;
	for (int i = 0; i < outputVector.size(); i++)
	{
		outputString += outputVector.at(i).top();
	}
	return outputString;
}