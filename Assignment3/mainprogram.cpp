/*
Simulates a single run of the entire Assignment3.
Instantiates a FileProcessor object, translates a provided input file,
and exits.
*/
#include "FileProcessor.h"
#include <iostream>
#include <string>

int main()
{
    string inputFileName;
    string outputFileName;

    cout << "Provide the name of the input (English) txt file: ";
    cin >> inputFileName;
    cout << "Provide the name of the output (Tutnese) txt file: ";
    cin >> outputFileName;

    FileProcessor processor;
    processor.processFile(inputFileName, outputFileName);

    return 0;
}
/*
TODO:
- Just make the code work in general.
    - Figure out the error that's preventing it from properly running processFile()
*/