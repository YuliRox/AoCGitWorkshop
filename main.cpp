
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> numbers;
    while(cin.peek() != EOF) {
        int parsedNumber = 0;
        cin >> parsedNumber;

        // detect invalid input
        if(cin.fail()) {
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

    return 0;
}
