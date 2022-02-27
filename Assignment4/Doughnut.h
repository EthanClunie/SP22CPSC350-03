#include <string>
#include <vector>
#include "Game.h"

using namespace std;

class Doughnut
{
    public:
        Doughnut::Doughnut();
        Doughnut::~Doughnut();
    private:
        short FindNumNeighbors();
};