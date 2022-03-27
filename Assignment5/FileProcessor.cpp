/**
 * @file FileProcessor.cpp
 * @author Ethan Clunie
 * @brief 
 * @version 0.1
 * @date 2022-03-22
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
}


/**
 * ReadFromFile
 * @brief Reads the contents from an input file and passes those on to be checked in Simulation
 * 
 * @return string 
 */
string FileProcessor::ReadFromFile()
{
    string contents = "";
    exactContents.clear();
    numLinesInFile = 0;
    try
    {
        string inFileName = GetInputFilePath();
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
            // Skip any comments in the file
            if (line[0] == '#' || (line.find('/') != -1 && line[line.find('/')] == line[line.find('/')+1]))
            {
                // Comment found. Do nothing
            }
            else
            {  
                contents += line + '\n';
            }
            exactContents.push_back(line + '\n');
            ++numLinesInFile;
        }

        inFile.close();
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }

    return contents;
}


/**
 * GetInputFileName
 * @brief Prompts user for an input file command line path and checks that it is a valid file name before 
 * returning that file name
 * 
 * @return string 
 */
string FileProcessor::GetInputFilePath()
{
    string filePath;
    cout << "Provide a valid location for the source code file you wish to test." << endl;
    cout << "The file path should be in a form similar to: \" foo.cpp \"" << endl;
    cout << "Your input: ";
    cin >> filePath;
    cout << endl;
    
    return filePath;
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


/**
 * GetExactFileContents
 * @brief Returns the exact file contents to allow them to be used elsewhere
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> FileProcessor::GetExactFileContents()
{
    return exactContents;
}