#include "..\Days.h"

int day_1(void)
{
    int calory_sum = 0;
    int elf_number = 1;
    int calory_max = 0;

    std::vector<int> topThree = { 0,0,0 };

    std::ifstream input("C:\\PROJECTS\\Advent of Code\\Day1\\elves.txt");
    for (std::string line; getline(input, line);)
    {
        if (line == "")
        {
            for (auto& element : topThree)
            {
                if (calory_sum > element)
                {
                    element = calory_sum;
                    calory_max = topThree[0] + topThree[1] + topThree[2];
                    std::sort(topThree.begin(), topThree.end());
                    break;
                }
            }
            elf_number++;
            calory_sum = 0;
        }
        else
        {
            int line_int = std::stoi(line);
            calory_sum += line_int;
        }
    }

    return calory_max;
}
