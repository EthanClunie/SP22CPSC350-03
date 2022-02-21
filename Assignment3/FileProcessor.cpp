/*
Takes txt files as inputs. One input and one output.
Using those text files, FileProcessor takes information from one file
to pass onto other classes in order to translate those messages before
pushing them out to the output file.
*/
#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>

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
 * processFile
 * @brief Handles fileIO. Takes text from inputFile, passes it to Translator,
 * receives the translated text, and passes that back into outputFile
 * 
 * @param inputFile 
 * @param outputFile 
 */
void FileProcessor::processFile(string inputFile, string outputFile)
{
    Translator translator;

    string line;

    ifstream inFile(inputFile, ios::in);
    ofstream outFile(outputFile, ios::out);

    if (inFile.is_open())
    {
        string translation;
        while (getline(inFile, line))
        {
            translation = translator.translateEnglishSentence(line);
            outFile << translation << endl;
            translation = "";
        }

        inFile.close();
        outFile.close();
    }
    else
    {
        cout << "Error opening inFile" << endl;
    }
}