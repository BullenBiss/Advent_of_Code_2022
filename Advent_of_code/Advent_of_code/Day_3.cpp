#include "Days.h"

int day_3(void)
{

    int task1(std::vector<int> rucksack);


    int sumPrio = 0;
    std::ifstream input("C:\\PROJECTS\\Advent of Code\\Day3\\rucksack.txt");
    for (std::string line; getline(input, line);)
    {
        std::size_t half_size = line.size() / 2;
        std::vector<int> rucksack(line.begin(), line.end());

        for (auto& element : rucksack)
        {
            if (element > 90)
                element = element - 96;
            else
                element = element - 38;
        }

        std::vector<int> firstComp(rucksack.begin(), rucksack.begin() + half_size);
        std::vector<int> secondComp(rucksack.begin() + half_size, rucksack.end());
        std::cout << std::endl;


        std::sort(firstComp.begin(), firstComp.end());
        std::sort(secondComp.begin(), secondComp.end());
        std::size_t firstHalfSize = firstComp.size() / 2;
        std::size_t secondHalfSize = secondComp.size() / 2;


        std::vector<int> checkedPrio;

        for (int element : firstComp)
        {
            std::vector<int>::iterator itStart;
            std::vector<int>::iterator itEnd;

            if (element >= secondComp.at(secondHalfSize))
            {
                itStart = secondComp.begin() + secondHalfSize;
                itEnd = secondComp.end();
            }
            else
            {
                itStart = secondComp.begin();
                itEnd = secondComp.begin() + secondHalfSize;
            }

            for (; itStart != itEnd; itStart++)
            {
                if ((element == *itStart) && (std::count(checkedPrio.begin(), checkedPrio.end(), element) == 0))
                {
                    checkedPrio.push_back(element);
                    sumPrio += element;
                    break;
                }
            }
        }

        //std::vector<int> firstComp(line.begin(), line.begin() + half_size);
        //std::vector<int> secondComp(line.begin() + half_size, line.end());



        //const char* firstCompChar = firstComp.c_str();
        //std::cout << lineChar[0] << std::endl;
    }
    return sumPrio;
}