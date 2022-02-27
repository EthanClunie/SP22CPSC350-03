/*
Header file for Game class.
Contains the function definitions and any necessary private members
*/

using namespace std;

class Game
{
    public:
        Game();
        ~Game();
        void Play();

    private:
        short numRows;
        short numColumns;

        char **gameGrid;
        char **copyGrid;

        void GetNumRowsAndColumns();
        void InitGrid();
        double CheckValidInitWorldPop(double population);

        short FindNumNeighbors();
        bool HasStagnated();
};