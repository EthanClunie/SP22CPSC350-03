/*

*/
#include <iostream>

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
    GetNumRowsAndColumns();

    // Allocated array of 3 pointers to char in heap memory
    this->gameGrid = new char* [numRows];
    for (int i = 0; i < this->numRows; ++i) {
        this->gameGrid[i] = new char[this->numColumns];  //Allocate an array of 3 characters
    }

    // assign '~' to element of 2-D array a_cGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < this->numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
		{
			this->gameGrid[iRow][iColumn] = '~';
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
    FileIO fileHandler;

    string userWorldChoice;
    string textSuffix = ".txt";
    double initWorldPopulation;

    cout << "Would you like to provide a map file for the simulated world or a random assignment?" << endl;
    cout << "Provide a file name with .txt. Anything else will be treated as desiring a random assignment: " << endl;
    cin >> userWorldChoice;

    // Checks if the input for userWorldChoice contained .txt. If yes, use it as a map. If not, random game.
    int foundTxt = userWorldChoice.find(textSuffix);
    
    cout << foundTxt << endl;

    if (foundTxt == -1) // Random game assignment
    {

    }
    else                // Use input as map file for simulated world
    {

    }

    cout << "Provide a decimal value for initial population density of the world (0 < population <= 1):" << endl;
    cin >> initWorldPopulation;

    if ((initWorldPopulation <= 0) || !(initWorldPopulation > 1))
    {
        initWorldPopulation = CheckValidInitWorldPop(initWorldPopulation);
    }
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
 * HasStagnated
 * @brief Checks if the current game state has stagnated.
 * True if either: the previous gen is the same as current gen or if everything has done.
 * False if not.
 * 
 * @return true 
 * @return false 
 */
bool Game::HasStagnated()
{

}