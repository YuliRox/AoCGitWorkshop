
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "AoCGitWorkshop 2022 day 3 part 1\n";

    int totalPriotity = 0; //
    int cntRuck = 1;

    while (cin.peek() != EOF)
    {
        vector<char> itemsInR;

        // read on line, aka contend of one rucksack
        int cntItems = 0;
        while (cin.peek() != '\n' ) //10 = EOL
        {
            itemsInR.push_back( cin.get() );
            cntItems++;
        }
        // discard the LF, witch stoped the Loop
        cin.get();

        cout << "\n# " << cntRuck++ << " | " << cntItems << " Items |";

        bool heureka = false;

        // walk first half of the Vector
        for (int i = 0 ; i < cntItems / 2 && ! heureka ; i++)
        {
            // walk second half of the Vector
            for (int j = cntItems / 2 ; j < cntItems && ! heureka ; j++)
            {
                // find match
                if (itemsInR[i] == itemsInR[j]){

                    cout << " Item " << itemsInR[i];
                    
                    // summ up prioritys
                    int prio = 0;
                    if ( itemsInR[i] >= 'a' - 1 && itemsInR[i] <= 'z' )
                    {
                        // On lower case asign Prioritys from 1 to 26
                        prio = itemsInR[i] - 'a' + 1;
                    }
                    if ( itemsInR[i] >= 'A' - 1 && itemsInR[i] <= 'Z' )
                    {
                        // On uper case asign Prioritys from 27 to 52
                        prio = itemsInR[i] - 'A' + 27;
                    }

                    cout << " (" << prio << ") |";

                    totalPriotity += prio;
                    heureka = true;
                }
            }
        }
    }
    
    cout << "\n\n***** Answer part 1 *****\n";

    cout << "\nThe total priority is " << totalPriotity <<"\n";

//    cout << "\n**** Answer part 2 ****\n";

    return 0;
}
