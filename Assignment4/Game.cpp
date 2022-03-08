/*

*/
#include <chrono>
#include "FileIO.h"
#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"

using namespace std;

/**
 * Game
 * @brief Construct a new Game::Game object
 * 
 */
Game::Game()
{}

/**
 * ~Game
 * @brief Destroy the Game::Game object
 * 
 */
Game::~Game()
{}

/**
 * InitGridRand
 * @brief Initializes a grid for the game after obtaining input values for row/column sizes
 * 
 */
void Game::InitGridRand()
{
    gameGrid.InitGridRand();
    copyGrid = gameGrid;
}

/**
 * Play
 * @brief Plays through an entire simuation of the game
 * 
 */
void Game::Play()
{
    // copyGrid = gameGrid;
    int gameType = DetermineGameType();

    FileIO fileHandler;

    string userWorldChoice;
    string textSuffix = ".txt";
    int generationNumber = 0;

    cout << "Would you like to provide a map file for the simulated world or a random assignment?" << endl;
    cout << "Provide a file name with \".txt\". Anything else will be treated as desiring a random assignment: " << endl;
    cin >> userWorldChoice;

    // Checks if the input for userWorldChoice contained .txt. If yes, use it as a map. If not, random game.
    int foundTxt = userWorldChoice.find(textSuffix);

    if (foundTxt == -1) // Random game assignment
    {
        // Creates a grid based on user input for row/column amounts
        InitGridRand();
    }
    else // Use input as map file for simulated world
    {
        fileHandler.LoadMapFile(userWorldChoice, gameGrid);
        copyGrid = gameGrid;
    }

    int emergencyBreakOut = 0;
    // Actual game loop beginning. Continues looping until game over
    while (!HasStagnated() || !AllDead()) // Checks game rules/end conditions
    {
        // Displays the current generation
        cout << "Gen ";
        cout << generationNumber << endl;
        gameGrid.DisplayGrid();

        if (emergencyBreakOut >= 20) // In case shit gets bad
        {
            cout << "Hit ceiling run amount (20)." << endl;
            break;
        }

        TODO3:
        if (gameType == 1)
        {
            Classic classicGame;
            classicGame.CreateGridWithBoundaries(gameGrid);
            cout << "TEST4: Element in gameGrid at position (1,1) change to \'j\'." << endl;
            gameGrid.ChangeCurrElementPos(1,1,'j');
            cout << "Changed element: " << gameGrid.GetCharAt(1,1) << endl;
            gameGrid.DisplayGrid();
            
            for (int iRow = 0; iRow < gameGrid.GetNumRows(); ++iRow)
	        {
		        for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); ++iColumn)
		        {
                    int numNeighbors = 0;
                    cout << "Test1: (File: " << __FILE__ << ", Line: " << __LINE__  << ")" << endl;
                    numNeighbors = classicGame.FindNumNeighbors(iRow, iColumn);
                    cout << "NumNeighbors: " << numNeighbors << endl;
                    cout << "Test2: (File: " << __FILE__ << ", Line: " << __LINE__  << ")" << endl;
                    
                    // Handles next-gen changes based on numNeighbors in current generation for each location
                    if (numNeighbors <= 1)
                    {
                        copyGrid.ChangeCurrElementPos(iRow, iColumn, '-');
                        cout << "1 or 0 neighbors" << endl;
                    }
                    else if (numNeighbors == 2)
                    {
                        copyGrid.ChangeCurrElementPos(iRow, iColumn, gameGrid.GetCharAt(iRow, iColumn));
                        cout << "2 neighbors" << endl;
                    }
                    else if (numNeighbors == 3)
                    {
                        copyGrid.ChangeCurrElementPos(iRow, iColumn, 'X');
                        cout << "3 neighbors" << endl;
                    }
                    else if (numNeighbors >= 4)
                    {
                        copyGrid.ChangeCurrElementPos(iRow, iColumn, '-');
                        cout << "4 or more neighbors" << endl;
                    }
                }
            }
            
            SwapGrids(gameGrid, copyGrid);
        }
        else if (gameType == 2)
        {
            // TODO
            // create object of Doughnut type
            while (true)
            {
                ++generationNumber;
                break;
            }
        }

        else if (gameType == 3)
        {
            // TODO
            // create object of Mirror type
            while (true)
            {
                ++generationNumber;
                break;
            }
        }
        else
        {
            cout << "Invalid game mode." << endl;
            gameType = DetermineGameType();
        }
        
        ++generationNumber;
        ++emergencyBreakOut;
    }

    TODO2:
    // Prompt the user to press "ENTER" to exit the program
    while (true)
    {
        string exitChar = " ";
        cout << "Press the ENTER key to exit the simulation." << endl;
        // Read for the ASCII value of the ENTER key, not for '\n' or whitespace
        cin.ignore();
        getline(cin, exitChar);

        if (exitChar.length() < 1) // TODO : hopefully this is the ascii value
        {
            break;
        }

    }

    return;
}

/**
 * SwapGrids
 * @brief Swaps the pointers between the two grids of the game at the end of each generation
 * 
 */
void Game::SwapGrids(GameBoard Grid1, GameBoard Grid2)
{
    GameBoard temp = Grid1;
    Grid1 = Grid2;
    Grid2 = temp;
}

/**
 * AllDead
 * @brief Checks if all grid spaces are "-".
 * If so, return true; else, return false;
 * 
 * @return true 
 * @return false 
 */
bool Game::AllDead()
{
    bool allDead;
    int numEmptyLocations = 0;
    int totalNumLocations = (gameGrid.GetNumRows() * gameGrid.GetNumCols());

    // Checks if all locations are empty
    for (int iRow = 0; iRow < gameGrid.GetNumRows(); ++iRow)
    {
        for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); ++iColumn)
        {
            if (gameGrid.GetCharAt(iRow, iColumn) == '-') 
            {
                ++numEmptyLocations;
            }
        }
    }

    if (numEmptyLocations == totalNumLocations)
    {
        allDead = true;
    }
    else
    {
        allDead = false;
    }

    return allDead;
}

/**
 * HasStagnated
 * @brief Checks if the current game state has stagnated.
 * True if the previous gen is the same as current gen
 * False if not.
 * 
 * @return true 
 * @return false 
 */
bool Game::HasStagnated()
{
    bool hasStagnated = false;
    int numSameLocations = 0;
    int totalNumLocations = (gameGrid.GetNumRows() * gameGrid.GetNumCols());

    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 0; iRow < gameGrid.GetNumRows(); ++iRow)
    {
        for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); ++iColumn)
        {
            if (gameGrid.GetCharAt(iRow, iColumn) == (copyGrid.GetCharAt(iRow, iColumn))) 
            {
                ++numSameLocations;
            }
        }
    }

    hasStagnated = (numSameLocations == totalNumLocations);

    return hasStagnated;
}

/**
 * DetermineGameType
 * @brief Obtains the desired game mode from the user
 * 
 * @return int 
 */
int Game::DetermineGameType()
{
    cout << "Which type of game would you like to play? (respond with the number associated with each mode)" << endl;
    cout << "1: Classic" << endl;
    cout << "2: Doughnut" << endl;
    cout << "3: Mirror" << endl;
    cout << "Your Choice: ";

    int userChoice = 0;
    cin >> userChoice;

    return userChoice;
}