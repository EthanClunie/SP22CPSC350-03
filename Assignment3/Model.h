/*
Header file for Model class.
Contains function definitions to be implemented as well as any private/public variables
*/
#include <string>

using namespace std;

class Model
{
    private:
        bool isVowel(char c);
    public:
        Model();
        ~Model();
        string translateSingleCharacter(char c);
        string translateDoubleCharacter(char cc);
};