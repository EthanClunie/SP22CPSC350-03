/*
Calls necesarry functions from Parser class.
Through those function calls, obtains information from a string.
Then prints that information to a file called output.txt
*/
#include <iostream>
#include <string>
#include "Parser.h"

using namespace std;

/*
TODO & Notes:
- use a ton of if statements in a for loop
- Cannot use any data structures (arrays, pointers, LinkedLists, vectors, etc)
- Separate the work into multiple other files & just have main() run like 2 functions
  > in other classes could have a Write() function to write to file
  > a GetValues() function to obtain the different values needed to write to the file
  > a Load() func that loads the string
- don't need to handle capital letters
*/

int main()
{
    Parser parser;

    parser.GatherData();
    parser.LogInfo();

    return 0;
}