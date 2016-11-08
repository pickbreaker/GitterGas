//
// Created by Benedikt on 08.11.2016.
//

#ifndef GITTERGAS_GITTER_H
#define GITTERGAS_GITTER_H
#include "Cell.h"
#include <vector>
using std::vector;

class Gitter {
public:
    Gitter(int size);
    Cell cell_at(int xpos,int ypos);

private:
    vector <vector <Cell>> v;
};


#endif //GITTERGAS_GITTER_H
