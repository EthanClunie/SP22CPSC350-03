/*

*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Game.h"
#include "FileIO.h"

using namespace std;

/**
 * Game
 * @brief Construct a new Game::Game object
 * 
 */
Game::Game()
{
    GetNumRowsAndColumns();
    InitGrid();
}

/**
 * ~Game
 * @brief Destroy the Game::Game object
 * 
 */
Game::~Game()
{
    for (int i = 0; i < numRows; ++i)
    {
        delete[] gameGrid[i];
        delete[] copyGrid[i];
    }
    delete[] gameGrid;
    delete[] copyGrid;
}

/**
 * GetNumRowsAndColumns
 * @brief Prompts the user for the number of rows and columns for their grid
 * 
 */
void Game::GetNumRowsAndColumns()
{
    cout << "Please, enter how many rows you would like: ";
    cin >> numRows;

    cout << "Please, enter how many columns you would like: ";
    cin >> numColumns;
}

/**
 * InitGrid
 * @brief Initializes a grid for the game after obtaining input values for row/column sizes
 * 
 */
void Game::InitGrid()
{
    // Allocated array of 3 pointers to char in heap memory
    this->gameGrid = new char* [numRows];
    this->copyGrid = new char* [numRows];
    for (int iRow = 0; iRow < this->numRows; ++iRow) {
        this->gameGrid[iRow] = new char[this->numColumns];  //Allocate an array of 3 characters
        this->copyGrid[iRow] = new char[this->numColumns];
    }

    // assign '~' to element of 2-D array a_cGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < this->numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
		{
			this->gameGrid[iRow][iColumn] = '-';
            this->copyGrid[iRow][iColumn] = '-';
		}
	}
}

/**
 * Play
 * @brief Plays through an entire simuation of the game
 * 
 */
void Game::Play()
{
    // TEST STUFF
    DisplayGrid();

    FileIO fileHandler;

    string userWorldChoice;
    string textSuffix = ".txt";
    double initWorldPopulation;

    cout << "Would you like to provide a map file for the simulated world or a random assignment?" << endl;
    cout << "Provide a file name with \".txt\". Anything else will be treated as desiring a random assignment: " << endl;
    cin >> userWorldChoice;

    // Checks if the input for userWorldChoice contained .txt. If yes, use it as a map. If not, random game.
    int foundTxt = userWorldChoice.find(textSuffix);
    
    cout << foundTxt << endl;

    if (foundTxt == -1)
    {
        // Random game assignment

    }
    else
    {
        // Use input as map file for simulated world

    }

    // Obtains a valid input value for the initial world population density
    cout << "Provide a decimal value for initial population density of the world (0 < population <= 1):" << endl;
    cin >> initWorldPopulation;
    
    TODO1:
    // handle potential errors w/ input
    if ((initWorldPopulation <= 0) || !(initWorldPopulation > 1))
    {
        initWorldPopulation = CheckValidInitWorldPop(initWorldPopulation);
    }

    DensityPlacement(initWorldPopulation);
    DisplayGrid();

    // Checks game rules/end conditions
    if (AllDead() || HasStagnated())
    {
        // Halt the simulation

        

        TODO2:
        // Prompt the user to press "ENTER" to exit
        char exitChar;
        
        while (true)
        {
            cout << "Press the ENTER key to exit the simulation." << endl;
            // cin.ignore();
            cin >> exitChar;

            if (exitChar == 'r')
            {
                break;
            }

        }

    }

    return;
}

/**
 * CheckValidInitWorldPop
 * @brief Returns a valid value for the initial population density
 * 
 * @param population: the population density being checked
 * @return double: a valid value for popluation density (0 < pop <= 1)
 */
double Game::CheckValidInitWorldPop(double population)
{
    while ((population <= 0) || (population > 1))
    {
        cout << "That value is invalid. Please make sure it is greater than 0 but less than or equal to 1.0:" << endl;
        cin >> population;
    }

    return population;
}

/**
 * SwapGridPointers
 * @brief Swaps the pointers between the two grids of the game at the end of each generation
 * 
 */
void Game::SwapGridPointer(char **Grid1, char **Grid2)
{
    char temp = **Grid1;
    **Grid1 = **Grid2;
    **Grid2 = temp;
   
    return;
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
    short numEmptyLocations = 0;
    short totalNumLocations = (numRows * numColumns);

    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 0; iRow < this->numRows; ++iRow)
    {
        for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
        {
            if (this->gameGrid[iRow][iColumn] == '-') 
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
    bool hasStagnated;
    short numSameLocations = 0;
    short totalNumLocations = (numRows * numColumns);

    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 0; iRow < this->numRows; ++iRow)
    {
        for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
        {
            if (this->gameGrid[iRow][iColumn] == this->copyGrid[iRow][iColumn]) 
            {
                ++numSameLocations;
            }
        }
    }

    if (numSameLocations == totalNumLocations)
    {
        hasStagnated = true;
    }
    else
    {
        hasStagnated = false;
    }

    return hasStagnated;
}

/**
 * DensityPlacement
 * @brief Takes in a user input for population density and finds random
 * positions for the initial populated grid locations
 * 
 * @param popDensity 
 */
void Game::DensityPlacement(double popDensity)
{
    int randomNum;
    srand(time(NULL));

    int maxVal = 10;
    int densityNum = popDensity * 10;

    for (int iRow = 0; iRow < this->numRows; ++iRow)
    {
        for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
        {
            randomNum = rand() % maxVal;

            if (randomNum < densityNum)
            {
                this->gameGrid[iRow][iColumn] = 'X';
            }
            else 
            {
                this->gameGrid[iRow][iColumn] = '-';
            }
        }
    }
}

/**
 * DisplayGrid
 * @brief Displays the current grid
 * 
 * @param gridToDisplay 
 */
void Game::DisplayGrid()
{
    cout << endl;
	for (int iRow = 0; iRow < this->numRows; iRow++)
	{
		for (int iColumn = 0; iColumn < this->numColumns; iColumn++)
		{
			cout << this->gameGrid[iRow][iColumn];
		}
		cout << endl;
	}
    cout << endl;
}