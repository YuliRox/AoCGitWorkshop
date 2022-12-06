
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int score(char elve, char me)
{
    int shape;
    const int win = 6;
    const int draw = 3;
    const int loose = 0;

    switch (elve)
    {
    case 'A': // Rock
        shape = 1;
        switch (me)
        {
        case 'A':
            return shape + draw;
        case 'B':
            return shape + win;
        case 'C':
            return shape + loose;
        }
    case 'B':  // Paper
        shape = 2;
        switch (me)
        {
        case 'A':
            return shape + loose;
        case 'B':
            return shape + draw;
        case 'C':
            return shape + win;
        }
    case 'C': // Scissors
        shape = 3;
        switch (me)
        {
        case 'A':
            return shape + win;
        case 'B':
            return shape + loose;
        case 'C':
            return shape + draw;
        }
    default:
        int e = elve;
        int m = me;
        cout << "unreckognised shape! " << elve << e << me << m << "\n";
        return -1;
    }
}

int main(int argc, char *argv[])
{
    cout << "AoCGitWorkshop 2022 day 2 part 1\n";

    char elve, me;
    char cnvShape[] = {'A', 'B', 'C', 'A', 'B', 'C'};

    int readLines = 0;
    long posScores[] = {0, 0, 0};

    while (cin.peek() != EOF)
    {
        char c = cin.get();

        switch (c)
        {
            case 'A':
            case 'B':
            case 'C':
                elve = c;
                break;
            case 'X':
            case 'Y':
            case 'Z':
                me = c;
                posScores['X' - 'X'] += score(elve, cnvShape[me - 'X' + 3]);
                posScores['Y' - 'X'] += score(elve, cnvShape[me - 'Y' + 3]);
                posScores['Z' - 'X'] += score(elve, cnvShape[me - 'Z' + 3]);
                readLines++;
                break;
        }
    }

    cout << "\n*** Answer part 1 ***\n\n";
    cout << "Lines read: " << readLines <<"\n";
    cout << "your options are:\n";
    cout << "Option | X        | Y        | Z        | Score\n";
    cout << "    #1 | Rock     | Paper    | Scissors | " << posScores[0] << "\n";
    cout << "    #2 | Paper    | Scissors | Rock     | " << posScores[1] << "\n";
    cout << "    #3 | Scissors | Rock     | Paper    | " << posScores[2] << "\n";

    cout << "\nThe highest scoring option is option ";
    int maxScore = 0;
    int bestOption = 0;
    for (int i = 0; i < sizeof(posScores) / sizeof(posScores[0]) ; i++)
    {
        if ( posScores[i] > maxScore)
        {
            maxScore = posScores[i];
            bestOption = i + 1;
        }
    }
    cout << maxScore << ".\n\n";
    

//    cout << "\n**** Answer part 2 ****\n";

    return 0;
}
