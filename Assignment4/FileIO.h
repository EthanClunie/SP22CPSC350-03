/*
Header file for FileIO class.
Contains the function definitions and any necessary private members
*/
#include <string>

using namespace std;

class FileIO
{
    public:
        FileIO();
        ~FileIO();
        string LoadMapFile(string inputMapFile);
        void SaveCurrentState(char **currGameState);
    private:
};