/**
 * @file FileHandler.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file for FileHandler class
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileHandler
{
    private:
        ifstream fileReader;
        ofstream fileWriter;

    public:
        FileHandler();
        ~FileHandler();

        void OpenInFile(string fileName);
        string ReadLine();
        void CloseInFile();

        void OpenOutFile(string fileName);
        void WriteLineToFile(string line);
        void CloseOutFile();

        bool IsEndOfFile();
};


#endif