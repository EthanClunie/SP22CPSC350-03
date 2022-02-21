/*
Header file for Translator class.
Contains function definitions to be implemented as well as any private/public variables.
Uses the Model class.
*/
#include <string>

using namespace std;

class Translator
{
    private:
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string singleEngWord);
        string translateEnglishSentence(string singleEngSentence);
};