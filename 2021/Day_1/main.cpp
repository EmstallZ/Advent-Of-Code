#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    std::ifstream FILE;
    FILE.open("input", std::ios::in);
    if (FILE.is_open())
    {
        std::vector<std::int16_t> measurements;
        std::string depth;
        while(std::getline(FILE, depth)){
            measurements.push_back(std::stoi(depth));
        }

        int16_t increases = 0;
        // part 1
        for (std::int16_t i = 0; i <= measurements.size() - 1; i++)
        {
            if (measurements[i] < measurements[i + 1])
            {
                increases++;
            }
        }
        std::cout << increases << std::endl;
    }
    return 0;
}
