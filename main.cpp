
#include <iostream>
#include <vector>
#include <limits>
//#include <String>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "AoCGitWorkshop 2022 day 1 part 1\n";

    vector<int> elves;
    int calsPerElv = 0;

    while (cin.peek() != EOF)
    {
//        String inStr = String(10);
//        cin >> inStr;
//        cout << inStr;
        int parsedNumber = 0;
        cin >> parsedNumber;

        // detect invalid input
        if (cin.fail())
        {
            cout << "something went wrong parsing input\n";
            // reset error bits on cin
            cin.clear();
            // skip invalid input up until newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // skip adding to vector
            continue;
        }

        if (parsedNumber != 0)
        {
            calsPerElv += parsedNumber;
        }
        else
        {
            elves.push_back(calsPerElv);
        }
    }

    cout << "Number of Elves in the expedition " << elves.size() << ".\n";

    int maxCals = 0;
    int powerElvesNumber = 0;

    for (int i = 0; i < elves.size() - 1; i++)
    {
        if (elves[i] > maxCals)
        {
            maxCals = elves[i];
            powerElvesNumber = i;
        }
    }

    cout << "the " << powerElvesNumber << " carryies " << maxCals << " Calories.\n";

    return 0;
}
