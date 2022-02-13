/*
Implements function definitions from Parser.h.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"

using namespace std;

/* 
Parser()
Constructor for the Parser class
*/
Parser::Parser()
{
    GetUserString();
    numCharA = 0;
    numCharB = 0;
    numCharC = 0;
    numCharD = 0;
    numCharE = 0;
    numCharF = 0;
    numCharG = 0;
    numCharH = 0;
    numCharI = 0;
    numCharJ = 0;
    numCharK = 0;
    numCharL = 0;
    numCharM = 0;
    numCharN = 0;
    numCharO = 0;
    numCharP = 0;
    numCharQ = 0;
    numCharR = 0;
    numCharS = 0;
    numCharT = 0;
    numCharU = 0;
    numCharV = 0;
    numCharW = 0;
    numCharX = 0;
    numCharY = 0;
    numCharZ = 0;
    totalNonAlphabetChars = 0;
    totalAlphabetChars = 0;
    totalNumPairs = 0;
    averageOccurences = 0.0;
}

/* 
GetUserString()
Promts the user to provide some string of characters
*/
void Parser::GetUserString()
{
    cout << "Provide some string of characters: ";
    cin >> this->userString;
    for (int i = 0; i < userString.size(); i++) //Converts each character to lowercase form
    {
        tolower(userString[i]);
    }
}

/* 
GatherData()
Runs the helper functions needed to obtain the information
that is to be printed to the output.txt file
*/
void Parser::GatherData()
{
    GetTotalNumOfAlphaAndNonAlpha();
    GetTotalNumOfPairs();
    CalcAverageOccurrences();
}

/* 
GetTotalNumofAplhaAndNonAlpha()
Looks through ever character in the userString and checks 
whether that character is an alphabet character or not. If yes
then it determines which and adds to a counter for that character.
If not it counts that character as a non-alphabet character and 
adds to a separate counter for those.
*/
void Parser::GetTotalNumOfAlphaAndNonAlpha()
{
    for (char c : userString)
    {
        if (isalpha(c))
        {
            if (c == 'a')
            {
                ++numCharA;
                ++totalAlphabetChars;
            }
            else if (c == 'b')
            {
                ++numCharB;
                ++totalAlphabetChars;
            }
            else if (c == 'c')
            {
                ++numCharC;
                ++totalAlphabetChars;
            }
            else if (c == 'd')
            {
                ++numCharD;
                ++totalAlphabetChars;
            }
            else if (c == 'e')
            {
                ++numCharE;
                ++totalAlphabetChars;
            }
            else if (c == 'f')
            {
                ++numCharF;
                ++totalAlphabetChars;
            }
            else if (c == 'g')
            {
                ++numCharG;
                ++totalAlphabetChars;
            }
            else if (c == 'h')
            {
                ++numCharH;
                ++totalAlphabetChars;
            }
            else if (c == 'i')
            {
                ++numCharI;
                ++totalAlphabetChars;
            }
            else if (c == 'j')
            {
                ++numCharJ;
                ++totalAlphabetChars;
            }
            else if (c == 'k')
            {
                ++numCharK;
                ++totalAlphabetChars;
            }
            else if (c == 'l')
            {
                ++numCharL;
                ++totalAlphabetChars;
            }
            else if (c == 'm')
            {
                ++numCharM;
                ++totalAlphabetChars;
            }
            else if (c == 'n')
            {
                ++numCharN;
                ++totalAlphabetChars;
            }
            else if (c == 'o')
            {
                ++numCharO;
                ++totalAlphabetChars;
            }
            else if (c == 'p')
            {
                ++numCharP;
                ++totalAlphabetChars;
            }
            else if (c == 'q')
            {
                ++numCharQ;
                ++totalAlphabetChars;
            }
            else if (c == 'r')
            {
                ++numCharR;
                ++totalAlphabetChars;
            }
            else if (c == 's')
            {
                ++numCharS;
                ++totalAlphabetChars;
            }
            else if (c == 't')
            {
                ++numCharT;
                ++totalAlphabetChars;
            }
            else if (c == 'u')
            {
                ++numCharU;
                ++totalAlphabetChars;
            }
            else if (c == 'v')
            {
                ++numCharV;
                ++totalAlphabetChars;
            }
            else if (c == 'w')
            {
                ++numCharW;
                ++totalAlphabetChars;
            }
            else if (c == 'x')
            {
                ++numCharX;
                ++totalAlphabetChars;
            }
            else if (c == 'y')
            {
                ++numCharY;
                ++totalAlphabetChars;
            }
            else if (c == 'z')
            {
                ++numCharZ;
                ++totalAlphabetChars;
            }
        }
        else
        {
            ++totalNonAlphabetChars;
        }
    }
}

/* 
GetTotalNumOfPairs()
Loops through the entire userString comparing a character at index i
to the character at index i+1. If those two characters match then 
increment the totalNumPairs member variable by 1.
*/
void Parser::GetTotalNumOfPairs()
{
    for (int i = 0; i < userString.size(); i++)
    {
        if ((userString[i] == userString[i+1]) && isalpha(userString[i]))
        {
            ++totalNumPairs;
        }
    }
}

/* 
CalcAverageOccurrences()
Calculates the average occurrences of alphabetical characters within
the entire userString by dividing the sum of alphabetical characters by 26.
*/
void Parser::CalcAverageOccurrences()
{
    averageOccurences = totalAlphabetChars / 26.0;
}

/* 
LogInfo()
Prints all necessary information for the assignment to a file 
called output.txt. Info includes: amount of each alphabet character, 
total number of alphabet chars, total non-alphabet chars, average 
occurrence of alphabet chars in userString, and the number of char pairs.
*/
void Parser::LogInfo()
{
    ofstream outFile;
    outFile.open("output.txt");

    outFile << "a:" << numCharA << endl;
    outFile << "b:" << numCharB << endl;
    outFile << "c:" << numCharC << endl;
    outFile << "d:" << numCharD << endl;
    outFile << "e:" << numCharE << endl;
    outFile << "f:" << numCharF << endl;
    outFile << "g:" << numCharG << endl;
    outFile << "h:" << numCharH << endl;
    outFile << "i:" << numCharI << endl;
    outFile << "j:" << numCharJ << endl;
    outFile << "k:" << numCharK << endl;
    outFile << "l:" << numCharL << endl;
    outFile << "m:" << numCharM << endl;
    outFile << "n:" << numCharN << endl;
    outFile << "o:" << numCharO << endl;
    outFile << "p:" << numCharP << endl;
    outFile << "q:" << numCharQ << endl;
    outFile << "r:" << numCharR << endl;
    outFile << "s:" << numCharS << endl;
    outFile << "t:" << numCharT << endl;
    outFile << "u:" << numCharU << endl;
    outFile << "v:" << numCharV << endl;
    outFile << "w:" << numCharW << endl;
    outFile << "x:" << numCharX << endl;
    outFile << "y:" << numCharY << endl;
    outFile << "z:" << numCharZ << endl;
    outFile << "alphabets:" << totalAlphabetChars << endl;
    outFile << "non-alphabets:" << totalNonAlphabetChars << endl;
    outFile << "average:" << averageOccurences << endl;
    outFile << "pairs:" << totalNumPairs << endl;

    outFile.close();
}