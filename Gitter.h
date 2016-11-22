//
// Created by Benedikt on 08.11.2016.
//

#ifndef GITTERGAS_GITTER_H
#define GITTERGAS_GITTER_H

#include "Cell.h"
#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::pair;

class Gitter {
public:
    Gitter(int size);

    Cell &cell_at(int xpos, int ypos);

    vector<Cell> row_at(int pos);

    int size();

    vector<Cell> col_at(int pos);

    Cell get_neighbor_up(int posx, int posy);

    Cell get_neighbor_left(int posx, int posy);

    Cell get_neighbor_down(int posx, int posy);

    void label(int xpos, int ypos);

    Cell get_neighbor_right(int posx, int posy);

    //int use_function(string fkt);

    vector<pair<int, int>> neighbours(int posx, int posy);

    vector<pair<pair<int, int>, int>> neighbours_values(int posx, int posy);


private:
    vector<vector<Cell>> v;
    int groesse;
};


#endif //GITTERGAS_GITTER_H
