
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> numbers;

    while (cin.peek() != EOF)
    {
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

        numbers.push_back(parsedNumber);
    }

    cout << "Read " << numbers.size() << " numbers!\n";
    cout << "AoCGitWorkshop 2021 day 1 part 1\n";

    int cntr = 0;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] < numbers[i + 1])
        {
            cntr++;
        }
    }

    cout << "the solution for part one is " << cntr << "\n";

    cout << "AoCGitWorkshop 2021 day 1 part 2\n";

    cntr = 0;

    for (int i = 0; i < numbers.size() - 3; i++)
    {
        if (numbers[i] + numbers[i + 1] + numbers[i + 2] < numbers[i + 1] + numbers[i + 2] + numbers[i + 3])
        {
            cntr++;
        }
    }

    cout << "the solution for part two is " << cntr << "\n";

    return 0;
}
