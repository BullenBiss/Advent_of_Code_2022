#include "..\Days.h"

void task_1(std::vector<int> rucksack, std::size_t half_size, int *psumPrio);
void task_2(std::vector<std::vector<int>> _ruckGroup, int *psumPrio2);
bool searchVec(int findMe, std::vector<int> targetVec);

int day_3(void)
{
    int sumPrioTask1 = 0;
    int sumPrioTask2 = 0;
    std::vector<std::vector<int>> ruckGroup;

    std::ifstream input("C:\\PROJECTS\\Advent of Code\\Day3\\rucksack.txt");
    for (std::string line; getline(input, line);)
    {
        std::size_t _half_size = line.size() / 2;
        std::vector<int> _rucksack(line.begin(), line.end());

        for (auto& element : _rucksack)
        {
            if (element > 90)
                element = element - 96;
            else
                element = element - 38;
        }


        task_1(_rucksack, _half_size, &sumPrioTask1);

        std::sort(_rucksack.begin(), _rucksack.end());
        ruckGroup.push_back(_rucksack);

        if (ruckGroup.size() == 3)
        {
            task_2(ruckGroup, &sumPrioTask2);
            ruckGroup.clear();
        }

    }
    return sumPrioTask2;
}

void task_1(std::vector<int> rucksack, std::size_t half_size, int *psumPrio)
{
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
                *psumPrio += element;
                break;
            }
        }
    }
}

void task_2(std::vector<std::vector<int>> _ruckGroup, int* psumPrio2)
{

    for (int element : _ruckGroup[0])
    {
        if (searchVec(element, _ruckGroup[1]))
        {
            if (searchVec(element, _ruckGroup[2]))
            {
                *psumPrio2 += element;
                break;
            }
        }
    }
}

bool searchVec(int findMe, std::vector<int> targetVec)
{
    std::size_t halfSize = targetVec.size() / 2;
    std::vector<int>::iterator itStart;
    std::vector<int>::iterator itEnd;

    if (findMe >= targetVec.at(halfSize))
    {
        itStart = targetVec.begin() + halfSize;
        itEnd = targetVec.end();
    }
    else
    {
        itStart = targetVec.begin();
        itEnd = targetVec.begin() + halfSize;
    }

    for (; itStart != itEnd; itStart++)
    {
        if (findMe == *itStart)
        {
            return true;
        }
    }
    return false;
    
}