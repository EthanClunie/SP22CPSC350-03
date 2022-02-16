/*
Defines functions and variables needed to complete the whole project.
*/
#include <string>

using namespace std;

class Parser
{
    private:
        string userString;
        short numCharA, numCharB, numCharC;
        short numCharD, numCharE, numCharF;
        short numCharG, numCharH, numCharI;
        short numCharJ, numCharK, numCharL;
        short numCharM, numCharN, numCharO;
        short numCharP, numCharQ, numCharR;
        short numCharS, numCharT, numCharU;
        short numCharV, numCharW, numCharX;
        short numCharY, numCharZ;
        short totalNonAlphabetChars;
        short totalAlphabetChars;
        short totalNumPairs;
        double averageOccurences;
    public:
        Parser();
        void GetUserString();
        void GatherData();
        void GetTotalNumOfAlphaAndNonAlpha();
        void GetTotalNumOfPairs();
        void CalcAverageOccurrences();
        void LogInfo();
};