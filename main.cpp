
#include <iostream>
#include <vector>
#include <limits>
//#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "AoCGitWorkshop 2022 day 1 part 1 & 2\n";

    vector<int> elves;
    long calsPerElv = 0;
    int nlCnt = 0;
    int parsedNumber = 0;
    bool goOnReading = true;

    while (goOnReading)
    {
        char c = cin.get();

        switch (c)
        {
            case EOF:
                goOnReading = false;
            case 10: // LF
                if ( nlCnt == 0) // Number finisched. Now add!
                {
                    cout << "Cals read " << parsedNumber << "\n";        
                    calsPerElv += parsedNumber;
                    parsedNumber = 0;
                    nlCnt++;
                }
                else if ( nlCnt > 0) // switch elve
                {
                    cout << "Total cals on elve " << calsPerElv << "\n";        
                    elves.push_back(calsPerElv);
                    calsPerElv = 0;
                    nlCnt = 0;
                }
                break;
            case '0': // numbers
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            c -= 48; // offset in ascii table
                parsedNumber = parsedNumber * 10 + c;
                nlCnt = 0;
                break;
        }
    }

    cout << "\nThere are " << elves.size() << " on the expedition.\n";

    int maxCals = 0;
    int powerElvesNumber = 0;

    for (int i = 0; i < elves.size(); i++)
    {
        if (elves[i] > maxCals)
        {
            maxCals = elves[i];
            powerElvesNumber = i + 1;
        }
    }

    cout << "\n* Answer part 1 *\n";
    cout << "The number " << powerElvesNumber << " elve carryies the most calories. \nHe carryes " << maxCals << " cals.\n";

    // On each run the highest number ist moved to the first position
    // In consequende each run can omit one more element at the beginning
    const int mRuns = 3;
    int sortTmp;

    for ( int j = 0 ; j < mRuns ; j++ )
    {
        for (int i = elves.size() - 1; i > j ; i--)
        {
            if (elves[i - 1] < elves[i])
            {
                sortTmp = elves[i - 1];
                elves[i - 1] = elves[i];
                elves[i] = sortTmp;
            }
        }
        
    }

    int topElvesCals = 0;

    for (int i = 0; i < mRuns; i++)
    {
        topElvesCals += elves[i];
    }
    
    cout << "\n** Answer part 2 **\n";
    cout << "The total calories carried by the top " << mRuns << " elves are " << topElvesCals << " cals.\n";

    return 0;
}
