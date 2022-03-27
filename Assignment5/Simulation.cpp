/**
 * @file Simulation.cpp
 * @author Ethan Clunie
 * @brief Contains the implementations of all the method definitions from the Simulation header file.
 * Runs through a single simulation of the delimiter checking program.
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Simulation.h"

using namespace std;

/**
 * Simulation
 * @brief Construct a new Simulation:: Simulation object
 * 
 */
Simulation::Simulation()
{
    fp = new FileProcessor();
    fileContents = "";
}

/**
 * ~Simulation
 * @brief Destroy the Simulation:: Simulation object along with the FileProcessor pointer
 * 
 */
Simulation::~Simulation()
{
    delete fp;
}


/**
 * Simulate
 * @brief Runs through a single simulation of the delimiter checking code
 * 
 */
void Simulation::Simulate()
{
    try
    {
        bool continueOrExit;
        // Main loop until the user either does not wish to continue or an error is encountered
        do
        {   
            fileContents = fp->ReadFromFile();
            CheckFileContents();
            continueOrExit = ConfirmNextSimulation();
        } while (continueOrExit);
        
    }
    catch(runtime_error e)
    {
        cout << e.what() << '\n';
    }
}


/**
 * CheckFileContents
 * @brief Runs through each line of the passed in file and checks for valid delimiters
 * 
 */
void Simulation::CheckFileContents()
{
    // ArrayStack object that stores all the "open" delimiters to be checked later in program
    AStack<char> delimiterStack(4);
    
    // Loops through every character in the fileContents to check for delimiters
    short charCounter = 0;
    for (char c : fileContents)
    {
        // push every opening delimiter onto the stack
        if (IsOpeningDelimiter(c))
        {
            delimiterStack.push(c);
        }
        else if (IsClosingDelimiter(c))
        {
            if (fileContents.empty() || !ArePair(delimiterStack.topValue(), c))
            {
                if (!ArePair(c, delimiterStack.topValue()))
                {
                    char match = FindMatchingDelimiter(delimiterStack.topValue());

                    int lineWithError = FindLineWithError(charCounter, match);
                    if (lineWithError == -1)
                    {
                        throw runtime_error("ERROR: Could not find line with error in the given file");
                    }

                    string expectedChar = " ";
                    expectedChar += match;

                    throw runtime_error("ERROR: Line " + to_string(lineWithError) + ": expected" + expectedChar + ", found " + c);
                }
                else
                {
                    throw runtime_error("ERROR: Given file is empty");
                }
            }
            else
            {
                delimiterStack.pop();
            }
        }
        charCounter++;
        
    }

    if (delimiterStack.length() != 0)
    {
        string missingChar = " ";
        missingChar += FindMatchingDelimiter(delimiterStack.topValue());

        throw runtime_error("ERROR: Reached end of file: missing" + missingChar);
    }
}


/**
 * ConfirmNextSimulation
 * @brief Asks the user to provide an integer to represent their choice to either
 * continue (1) with a new file or exit the code (0). Returns a boolean representing
 * the user choice
 * 
 * @return true 
 * @return false 
 */
bool Simulation::ConfirmNextSimulation()
{
    short userModeChoice;

    do
    {
        cout << "The previous file was valid" << endl;
        cout << "There are now two options to choose from:" << endl;
        cout << "Select one of the two by entering their matching value" << endl;
        cout << "\t(0) Exit the program" << endl << "\t(1) Provide another file" << endl;
        cout << "Your choice: ";

        cin >> userModeChoice;
        cout << endl;
    } while ((userModeChoice < 0) || (userModeChoice > 1));

    return (userModeChoice == 1);

}


/**
 * IsOpeningDelimiter
 * @brief Returns a boolean value to show whether the passed in character is an opening delimeter.
 * Examples: (, {, [
 * 
 * @param testChar 
 * @return true 
 * @return false 
 */
bool Simulation::IsOpeningDelimiter(char testChar)
{
    return ((testChar == '(') || (testChar == '{') || (testChar == '['));
}


/**
 * IsClosingDelimiter
 * @brief Returns a boolean value to show whether the passed in character is a closing delimeter.
 * Examples: ), }, ]
 * 
 * @param testChar 
 * @return true 
 * @return false 
 */
bool Simulation::IsClosingDelimiter(char testChar)
{
    return ((testChar == ')') || (testChar == '}') || (testChar == ']'));
}


/**
 * ArePair
 * @brief Takes two characters as input, one from the stack and one from the file being checked
 * and checks whether they are a matching pair of open-close delimiters. Returns a boolean value with that information.
 * 
 * @param c1 
 * @param c2 
 * @return true 
 * @return false 
 */
bool Simulation::ArePair(char c1, char c2)
{
    return ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']'));
}


/**
 * FindMatchingDelimiter
 * @brief Finds and returns the matching delimiter of the passed in character. 
 * Returns 'x' if it failed to properly change to a match
 * 
 * @param charToMatch 
 * @return char 
 */
char Simulation::FindMatchingDelimiter(char charToMatch)
{
    char matchingChar = 'x';

    if (charToMatch == '(')
    {
        matchingChar = ')';
    }
    else if (charToMatch == '{')
    {
        matchingChar = '}';
    }
    else if (charToMatch == '[')
    {
        matchingChar = ']';
    }

    return matchingChar;
}


/**
 * FindLineWithError
 * @brief Returns an int storing the line where an error occurred when checking the delimiters
 * 
 * @param charNumWithError
 * @param c1
 * @return int 
 */
int Simulation::FindLineWithError(short charNumWithError, char c1)
{
    int lineWithError = -1;
    vector<string> contents = fp->GetExactFileContents();
    short correctedErrorPosition = GetCorrectErrorPosition(charNumWithError, contents);

    // Loop through each character in each line of the given file
    short errorPosition = 1;
    for (int rowPosition = 0; rowPosition < contents.size(); rowPosition++)
    {
        for (int columnPosition = 0; columnPosition < contents[rowPosition].size(); columnPosition++)
        {
            // Skips all characters until it reaches the character position where the error occurred
            if (errorPosition < correctedErrorPosition)
            {
                ++errorPosition;
            }
            else
            {
                // Checks that this location matches the actual delimiter error
                if (contents[rowPosition][columnPosition] == c1)
                {
                    return (rowPosition+1);
                }
            }
        }
    }

    return lineWithError;
}


/**
 * GetCorrectErrorPosition
 * @brief Corrects the short containing the character number at which the error occurred by
 * looping through the exactContents of the file and accounting for previously skipped comments
 * 
 * @param charNumWithError 
 * @param exactContents
 * @return short 
 */
short Simulation::GetCorrectErrorPosition(short charNumWithError, vector<string> exactContents)
{
    short correctErrorPosition = charNumWithError;

    for (int i = 0; i < exactContents.size(); i++)
    {
        string line = exactContents[i];
        if (line[0] == '#' || (line.find('/') != -1 && line[line.find('/')] == line[line.find('/')+1]))
        {
            for (int j = 0; j < line.size(); j++)
            {
                ++correctErrorPosition;
            }
        }
    }
    return correctErrorPosition;
}