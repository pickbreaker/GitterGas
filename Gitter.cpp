//
// Created by Benedikt on 08.11.2016.
//

#include "Gitter.h"
#include "Cell.h"
#include <vector>

using std::vector;

Gitter::Gitter(int size) {
    for (int j = 0; j < size; j++) {
        vector<Cell> vector1;
        for (int i = 0; i < size; i++) {
            Cell c(i + j * size);
            vector1.push_back(c);
        }
        v.push_back(vector1);
    }
}

Cell Gitter::cell_at(int xpos, int ypos) {
    return v[xpos][ypos];
}