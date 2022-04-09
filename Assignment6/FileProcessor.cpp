/**
 * @file FileProcessor.cpp
 * @author Ethan Clunie
 * @brief Implementation file for functions needed to read information from a file or to print
 * information to a file
 * 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "FileProcessor.h"

using namespace std;

/**
 * FileProcessor
 * @brief Construct a new File Processor:: File Processor object
 * 
 */
FileProcessor::FileProcessor()
{
}


/**
 * ~FileProcessor
 * @brief Destroy the File Processor:: File Processor object
 * 
 */
FileProcessor::~FileProcessor()
{
    delete this;
}


/**
 * ReadFromFile
 * @brief Reads the contents from an input file and passes those on to be checked in Simulation
 * 
 * @return string 
 */
vector<string> FileProcessor::ReadFromFile(string file)
{
    exactContents.clear();
    numLinesInFile = 0;
    try
    {
        string inFileName = file;
        ifstream inFile(inFileName, ios::in);

        // Checks if the file is opened properly and throws an exception if not
        if (!inFile.is_open())
        {
            string fileWithError = __FILE__;
            throw runtime_error("Could not open inFile, Loc: (File: " + fileWithError + ", Line: " + to_string(__LINE__) + ")");
        }

        // Reads the entire passed in file and copies it into the string contents
        string line;
        while (getline(inFile, line))
        {
            exactContents.push_back(line + '\n');
            ++numLinesInFile;
        }

        inFile.close();
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }

    return exactContents;
}


/**
 * GetNumLinesInFile
 * @brief Returns the number of lines in the file being read
 * 
 * @return short 
 */
short FileProcessor::GetNumLinesInFile()
{
    return numLinesInFile;
}