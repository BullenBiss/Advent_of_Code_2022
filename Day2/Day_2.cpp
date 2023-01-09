#include "..\Days.h"

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
