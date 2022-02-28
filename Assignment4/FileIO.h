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
        void LoadMapFile(string inputMapFile, char **someGrid);
        void SaveCurrentState(char **currGameState);
    private:
};