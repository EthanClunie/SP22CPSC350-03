/**
 * @file FileProcessor.h
 * @author Ethan Clunie
 * @brief Header file for FileProcessor class. Contains the method definitions for all
 * methods needed to handle any file IO in Assignment5.
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();

        std::string ReadFromFile();
        short GetNumLinesInFile();
        std::vector<std::string> GetExactFileContents();

    private:
        short numLinesInFile;
        std::vector<std::string> exactContents;

        std::string GetInputFilePath();
        
};

#endif