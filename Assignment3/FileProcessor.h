/*
Header file for FileProcessor class.
Contains function definitions to be implemented as well as any private/public variables
*/
#include <string>

using namespace std;

class FileProcessor
{
    private:
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string inputFile, string outputFile);
};