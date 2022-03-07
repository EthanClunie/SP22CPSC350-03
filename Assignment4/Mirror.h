#if !defined(MIRROR_H)
#define MIRROR_H

#include "Doughnut.h"

class Mirror
{
    public:
        Mirror();
        ~Mirror();
        
    private:
        int FindNumNeighbors();
};

#endif