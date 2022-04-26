/**
 * @file FileProcessor.h
 * @author Ethan Clunie
 * @brief Header file for FileProcessor class. Contains the method definitions for all
 * methods needed to handle any file IO
 * @version 0.1
 * @date 2022-15-01
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
#include "BST.h"

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();

        std::vector<std::string> ReadStandardFile(std::string fileToRead);

        void WriteStandardToFile(std::string contentsToWrite, std::string fileName);

    private:
        std::vector<std::string> exactContents;

        void HandleStandardRead(std::string fileToRead);
        
};

#endif