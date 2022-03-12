/**
 * @file GameSim.cpp
 * @authors Ethan Clunie, Samuel Bernsen
 * @brief Contains the implementations for methods defined in the GameSim class.
 * Runs through a single game after determining the user's decision on boundary mode and game type.
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "GameSim.h"

using namespace std;

GameSim::GameSim()
{
    mainBoard = new GameBoards();
    copyBoard = new GameBoards();

    int boardType = mainBoard->DetermineBoardType();
    int boardMode = mainBoard->DetermineBoardMode();
    DetermineDelayType();

    // Checks the boardType integer and sets whether the game will be done
    // using a randomly generated board (0) or a pre-generated map file (1)
    if (boardType == 0)
    {
        isRandomBoardOrMapFile = false;
    }
    else if (boardType == 1)
    {
        isRandomBoardOrMapFile = true;
    }

    // Checks the boardMode integer and sets whether the game mode is
    // classic (1), doughnut (2), or mirror (3)
    if (boardMode == 1)
    {
        bMode = CLASSIC;
        cout << "CLASSIC mode enabled, Line: " << __LINE__ << endl;
    }
    else if (boardMode == 2)
    {
        bMode = DOUGHNUT;
        cout << "DOUGHNUT mode enabled, Line: " << __LINE__ << endl;
    }
    else if (boardMode == 3)
    {
        bMode = MIRROR;
        cout << "MIRROR mode enabled, Line: " << __LINE__ << endl;
    }
}


GameSim::~GameSim()
{
}


void GameSim::Play()
{
    // Create GameBoards object based on board type (random or provided)
    if (isRandomBoardOrMapFile)
    {
        // Creates a board based on a given map file
        cout << "Pre-generated Board. Line: " << __LINE__ << endl;
        mainBoard->CreatePredefinedBoard();
        copyBoard = new GameBoards(*mainBoard);
    }
    else
    {
        // Creates a randomly generated board
        cout << "Random Board. Line: " << __LINE__ << endl;
        mainBoard->CreateRandomBoard();
        copyBoard = new GameBoards(*mainBoard);
    }
    int emergencyExit = 0;
    // Game loops for the different BoundaryModes
    int genNumber = 0;

    do 
    {
        // Displays each generation of the game board
        cout << "Generation Number: " << genNumber << endl;
        mainBoard->DisplayBoard();
        cout << endl;

        switch (bMode)
        {
            case CLASSIC: // Game loop for CLASSIC Mode
                GameLoop();
                break;

            case DOUGHNUT: // Game loop for DOUGHNUT Mode
                gameMode.ChangeDoughnutBoundaries(mainBoard);
                GameLoop();
                break;

            case MIRROR: // Game loop for MIRROR Mode
                gameMode.ChangeMirrorBoundaries(mainBoard);
                GameLoop();
                break;

            default:
                cout << "How the hell are you here?" << endl;
                break;
        }

        SwapBoardsPointers(&mainBoard, &copyBoard);

        // Performs the type of delay/action between generations
        PerfromDelayType(delayType);

        genNumber++;
    } while (!HasStagnated());

    cout << "Exited, LINE: " << __LINE__ << endl;

    // Close the outFile (fileWriter)
    if (delayType == 3)
    {
        CloseOutFile();
    }
}


/**
 * GameLoop
 * @brief Goes through an entire game loop of checking the game rules
 * 
 */
void GameSim::GameLoop()
{
    for (int iRow = 1; iRow < mainBoard->GetNumRows()+1; iRow++)
    {
        for (int iColumn = 1; iColumn < mainBoard->GetNumColumns()+1; iColumn++)
        {
            int numNeighbors = gameMode.GetNumNeighbors(iRow, iColumn, *mainBoard);

                if (numNeighbors <= 1)
            {
                copyBoard->ChangeElementAt(iRow, iColumn, '-');
            }
            else if (numNeighbors == 2)
            {
                copyBoard->ChangeElementAt(iRow, iColumn, mainBoard->GetCharAt(iRow, iColumn));
            }
            else if (numNeighbors == 3)
            {
                copyBoard->ChangeElementAt(iRow, iColumn, 'X');
            }
            else if (numNeighbors >= 4)
            {
                copyBoard->ChangeElementAt(iRow, iColumn, '-');
            }
        }
    }
}


/**
 * SwapBoardsPointers
 * @brief Swaps two GameBoard objects' pointers between each other
 * 
 */
void GameSim::SwapBoardsPointers(GameBoards **Grid1, GameBoards **Grid2)
{
    GameBoards *temp = *Grid1;
    *Grid1 = *Grid2;
    *Grid2 = temp;
}


/**
 * DetermineDelayType
 * @brief Prompts user for their choice of how to progress from each generation to the next
 * 
 */
void GameSim::DetermineDelayType()
{
    do
    {
        cout << "There are three options for the Delay mode:" << endl;
        cout << "Select one of the three by entering their matching value" << endl;
        cout << "\t(1) Brief Pause Between Gens" << endl << "\t(2) Press ENTER for Next Gen" << endl << "\t(3) Save To File" << endl;
        cout << "Your choice: ";

        cin >> delayType;
        cout << endl;
    } while ((delayType < 1) || (delayType > 3));

}


/**
 * PerformDelayType
 * @brief Performs one of the three type of delays/actions between generations 
 * based on user input from DetermineDelayType
 * 
 * @param userDelayType 
 */
void GameSim::PerfromDelayType(int userDelayType)
{
    if (userDelayType == 1)
    {
        DoBriefPause();
    }
    else if (userDelayType == 2)
    {
        PromptEnterBetweenGens();
    }
    else if (userDelayType == 3)
    {
        SaveToFile();
    }
    else
    {
        cout << "How have you managed this? Line: " << __LINE__ << endl;
    }
}


/**
 * @brief Performs a brief, 1 second pause between generations
 * 
 */
void GameSim::DoBriefPause()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // sleep for 1.5 second
}

/**
 * PromptEnterBetweenGens
 * @brief Prompts the user to press ENTER key before proceeding to the next generation(s)
 * 
 */
void GameSim::PromptEnterBetweenGens()
{
    system("read -p 'Press Enter to continue...' var");
}


/**
 * SaveToFile
 * @brief Saves all generations of a run to an outFile
 * 
 */
void GameSim::SaveToFile()
{
    string outputFileName;
    cout << "Provide a valid file name for an output file: ";
    cin >> outputFileName;

    mainBoard->SaveMapToFile(outputFileName);
}


/**
 * CloseOutFile
 * @brief Uses the method for closing the outfile in the FileHandler class
 * 
 */
void GameSim::CloseOutFile()
{
    mainBoard->CloseOutputFile();
}

/**
 * HasStagnated
 * @brief Returns a boolean value determining whether the current board is
 * equivalent to the previous generation. True if yes, false if no.
 * 
 * @return true 
 * @return false 
 */
bool GameSim::HasStagnated()
{
    bool hasStagnated = true;
    
    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 1; iRow < mainBoard->GetNumRows()+1; ++iRow)
    {
        for (int iColumn = 1; iColumn < mainBoard->GetNumColumns()+1; ++iColumn)
        {
            if ((mainBoard->GetCharAt(iRow, iColumn)) != (copyBoard->GetCharAt(iRow, iColumn))) 
            {
                hasStagnated = false;
            }
        }
    }

    return hasStagnated;
}