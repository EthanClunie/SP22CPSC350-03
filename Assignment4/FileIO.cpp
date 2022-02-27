/*

*/
#include <fstream>

#include "FileIO.h"

using namespace std;

/**
 * @brief Construct a new File IO object
 * 
 */
FileIO::FileIO()
{
}

/**
 * @brief Destroy the File IO object
 * 
 */
FileIO::~FileIO()
{
}

/**
 * LoadMapFile
 * @brief Loads a file for the initial game state from the user
 * 
 * @param inputMapFile 
 * @return string 
 */
string FileIO::LoadMapFile(string inputMapFile)
{
    ifstream inFile(inputMapFile, ios::in);

}

/**
 * SaveCurrentState
 * @brief Saves the current game state to a file named save.txt
 * 
 * @param fileToSave 
 */
void FileIO::SaveCurrentState(char **currGameState)
{
    string outputFileName = "save.txt";
    ofstream outFile(outputFileName, ios::out);

}