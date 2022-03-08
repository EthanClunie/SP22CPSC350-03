#include <random>
#include <time.h>
#include "GameBoard.h"

using namespace std;

/**
 * GameBoard
 * @brief Construct a new Game Board:: Game Board object
 * 
 */
GameBoard::GameBoard()
{
}

/**
 * ~GameBoard
 * @brief Destroy the Game Board:: Game Board object
 * 
 */
GameBoard::~GameBoard()
{
    for (int i = 0; i < numRows; ++i)
    {
        delete[] someGrid[i];
    }
    delete[] someGrid;
}

/**
 * InitGridOfKnownSize
 * @brief Initializes the game grids based on the number of rows and columns
 * 
 * @param numOfRows 
 * @param numOfCols 
 */
void GameBoard::InitGridOfKnownSize(int numOfRows, int numOfCols)
{
    this->numRows = numOfRows;
    this->numColumns = numOfCols;

    // Allocated array of pointers to char in heap memory
    this->someGrid = new char* [this->numRows];
    for (int iRow = 0; iRow < this->numRows; ++iRow)
    {
        this->someGrid[iRow] = new char[this->numColumns];  // Allocate an array of numRow characters
    }

    // assign '-' to element of 2-D array someGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < this->numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
		{
			this->someGrid[iRow][iColumn] = '-';
		}
	}
}

/**
 * InitGridRand
 * @brief Initializes a grid with randomly populated locations
 * 
 */
void GameBoard::InitGridRand()
{
    InitNumRowsAndColumns();

    // Allocated array of pointers to char in heap memory
    this->someGrid = new char* [numRows];
    for (int iRow = 0; iRow < this->numRows; ++iRow) {
        this->someGrid[iRow] = new char[this->numColumns];  //Allocate an array of numRow characters
    }

    // assign '-' to element of 2-D array a_cGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < this->numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
		{
			this->someGrid[iRow][iColumn] = '-';
		}
	}

    // Obtains a valid input value for the initial world population density
    double initWorldPopulation = -1.0;
    cout << "Provide a decimal value for initial population density of the world (0 < population <= 1):" << endl;
    cin >> initWorldPopulation;
    
    TODO1:
    // handle potential errors w/ input as non-numbers (chars or strings)
    initWorldPopulation = CheckValidInitWorldPop(initWorldPopulation);
    cout << endl;

    DensityPlacement(initWorldPopulation);
}

/**
 * InitFileGrid
 * @brief Initializes the game grids based on the number of rows and columns
 * 
 * @param numOfRows 
 * @param numOfCols 
 */
void GameBoard::InitFileGrid(int numOfRows, int numOfCols)
{
    this->numRows = numOfRows;
    this->numColumns = numOfCols;

    // Allocated array of pointers to char in heap memory
    this->someGrid = new char* [this->numRows];
    for (int iRow = 0; iRow < this->numRows; ++iRow) {
        this->someGrid[iRow] = new char[this->numColumns];  // Allocate an array of numRow characters
    }

    // assign '-' to element of 2-D array a_cGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < this->numRows; ++iRow)
	{
		for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
		{
			this->someGrid[iRow][iColumn] = '-';
		}
	}

}

/**
 * InitNumRowsAndColumns
 * @brief Sets the number of rows and columns of a random board based on user input
 * 
 */
void GameBoard::InitNumRowsAndColumns()
{
    cout << "Please, enter how many rows you would like: ";
    cin >> numRows;

    cout << "Please, enter how many columns you would like: ";
    cin >> numColumns;
}

/**
 * DisplayGrid
 * @brief Displays whatever board this method is called on
 * 
 */
void GameBoard::DisplayGrid()
{
    cout << endl;
	for (int iRow = 0; iRow < this->numRows; iRow++)
	{
		for (int iColumn = 0; iColumn < this->numColumns; iColumn++)
		{
			cout << someGrid[iRow][iColumn];
		}
		cout << endl;
	}
    cout << endl;
}

/**
 * GetNumRows
 * @brief Returns the number of rows a particular board has
 * 
 * @return int 
 */
int GameBoard::GetNumRows()
{
    return this->numRows;
}

/**
 * GetNumCols
 * @brief Returns the number of columns a particular board has
 * 
 * @return int 
 */
int GameBoard::GetNumCols()
{
    return this->numColumns;
}

/**
 * CheckValidInitWorldPop
 * @brief Returns a valid value for the initial population density
 * 
 * @param population: the population density being checked
 * @return double: a valid value for popluation density (0 < pop <= 1)
 */
double GameBoard::CheckValidInitWorldPop(double population)
{
    while ((population <= 0) || (population > 1))
    {
        cout << "Provide a valid initial pop density. Please make sure it is greater than 0 but less than or equal to 1.0:" << endl;
        cin >> population;
    }

    return population;
}

/**
 * DensityPlacement
 * @brief Randomly assigns locations to be populated within a game board
 * 
 * @param popDensity 
 */
void GameBoard::DensityPlacement(double popDensity)
{
    int randomNum;
    srand(time(NULL));

    int maxVal = 100;
    int densityNum = popDensity * 100;

    for (int iRow = 0; iRow < this->numRows; ++iRow)
    {
        for (int iColumn = 0; iColumn < this->numColumns; ++iColumn)
        {
            randomNum = rand() % maxVal;

            if (randomNum < densityNum)
            {
                this->someGrid[iRow][iColumn] = 'X';
            }
            else 
            {
                this->someGrid[iRow][iColumn] = '-';
            }
        }
    }
}

/**
 * ChangeCurrElementPos
 * @brief Changes the character at a given position with a given char
 * 
 * @param row 
 * @param col 
 * @param c 
 */
void GameBoard::ChangeCurrElementPos(int row, int col, char c)
{
    someGrid[row][col] = c;
}

/**
 * GetCharAt
 * @brief Returns the character at some given grid position
 * 
 * @param row 
 * @param col 
 * @return char 
 */
char GameBoard::GetCharAt(int row, int col)
{
    char elem;
    elem = someGrid[row][col];
    return elem;
}