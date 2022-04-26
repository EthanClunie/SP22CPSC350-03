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
 * ReadStandardFile
 * @brief Reads the contents from a standard input file and passes those into a vector<string>
 * 
 * @param fileToRead
 * 
 * @return vector<string> 
 */
vector<string> FileProcessor::ReadStandardFile(string fileToRead)
{
    exactContents.clear();
    try
    {
        HandleStandardRead(fileToRead);
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }

    return exactContents;
}


/**
 * WriteStandardToFile
 * @brief Takes a string as input and writes the contents of that string to an out file
 * 
 * @param contentsToWrite 
 * @param fileName
 */
void FileProcessor::WriteStandardToFile(string contentsToWrite, string fileName)
{
    // Implement later
}


/**
 * HandleStandardRead
 * @brief Reads a file as just plain text into the private exactContents vector
 * 
 * @param fileToRead 
 */
void FileProcessor::HandleStandardRead(string fileToRead)
{
    try
    {
        ifstream inFile(fileToRead, ios::in);

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
        }

        inFile.close();
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }
}