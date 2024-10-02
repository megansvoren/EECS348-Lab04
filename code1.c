#include <stdio.h>
void printCombos(int score)
{
    for (int numTD_2pt = 0; numTD_2pt <= score / 8; numTD_2pt++)
    {
        int tempScore1 = score - numTD_2pt * 8;
        for (int numTD_1pt = 0; numTD_1pt <= tempScore1 / 7; numTD_1pt++)
        {
            int tempScore2 = tempScore1 - numTD_1pt * 7;
            for (int numTD = 0; numTD <= tempScore2 / 6; numTD++)
            {
                int tempScore3 = tempScore2 - numTD * 6;
                for (int numFG = 0; numFG <= tempScore3 / 3; numFG++)
                {
                    int tempScore4 = tempScore3 - numFG * 3;
                    if (tempScore4 % 2 == 0)
                    {
                        int numSafety = tempScore4 / 2;
                        printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", numTD_2pt, numTD_1pt, numTD, numFG, numSafety);
                    }
                }
            }
        }
    }
}



int main()
{
    int score;
    while (1)
    {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score == 0 || score == 1)
        {
            break;
        }
        else
        {
            printCombos(score);
        }
    }
    return 0;
}