#if !defined(MIRROR_H)
#define MIRROR_H

#include "Game.h"

class Mirror
{
    public:
        Mirror();
        ~Mirror();
        
    private:
        int FindNumNeighbors();
};

#endif