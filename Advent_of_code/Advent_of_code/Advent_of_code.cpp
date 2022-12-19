// Advent_of_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int day_1(void);
int day_2(void);
int day_3(void);

int main()
{
    int result = day_3();

    std::cout << result << std::endl;
    return 0;
}

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
            for(auto &element : topThree)
            {
                if (calory_sum > element)
                {
                    element = calory_sum;
                    calory_max = topThree[0]+topThree[1]+topThree[2];
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


int day_2(void)
{
    int lineCount = 0;
    int totalScore = 0;
    char firstLetter;
    char secondLetter; 

    std::ifstream input("C:\\PROJECTS\\Advent of Code\\Day2\\RockPaperSissor.txt");
    for (std::string line; getline(input, line);)
    {
        int roundEval = 0;
        int choiceEval = 0;

        firstLetter = line[0];
        secondLetter = line[2];

        switch (firstLetter)
        {
           case 'A':
               if (secondLetter == 'Y')
               {
                   roundEval = 3;  
                   choiceEval = 1;
               }
               else if (secondLetter == 'Z')
               {
                   roundEval = 6;
                   choiceEval = 2;
               }
               else if (secondLetter == 'X')
               {
                   roundEval = 0;
                   choiceEval = 3;
               }
               break;

           case 'B':
               choiceEval = 2;
               if (secondLetter == 'X')
               {
                   roundEval = 0;
                   choiceEval = 1;
               }
               else if (secondLetter == 'Z')
               {
                   roundEval = 6;
                   choiceEval = 3;
               }
               else if (secondLetter == 'Y')
               {
                   roundEval = 3;
                   choiceEval = 2;
               }
               break;

           case 'C':
               choiceEval = 3;
               if (secondLetter == 'X')
               {
                   roundEval = 0;
                   choiceEval = 2;
               }
               else if (secondLetter == 'Y')
               {
                   roundEval = 3;
                   choiceEval = 3;
               }
               else if (secondLetter == 'Z')
               {
                   roundEval = 6;
                   choiceEval = 1;
               }
               break;

        default:
            std::cout << "DEFAULT HIT FIRST LETTER" << std::endl;
            break;
        }

        totalScore += (choiceEval + roundEval);

    }
    return totalScore;
}

int day_3(void)
{
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

        std::sort(firstComp.begin(), firstComp.end());
        std::sort(secondComp.begin(), secondComp.end());
        std::size_t firstHalfSize = firstComp.size() / 2;
        std::size_t secondHalfSize = firstComp.size() / 2;


        std::vector<int> checkedPrio;

        for (int element : firstComp)
        {
            std::vector<int>::iterator itStart;
            std::vector<int>::iterator itEnd;

            if(element > secondComp.at(secondHalfSize))
            {
                itStart = secondComp.begin() + secondHalfSize;
                itEnd = secondComp.end();
            }
            else
            {
                itStart = secondComp.begin();
                itEnd = secondComp.begin() + secondHalfSize;
            }
            
            for (; itStart != itEnd; ++itStart)
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