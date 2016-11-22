//
// Created by Benedikt on 08.11.2016.
//

#include "Gitter.h"
#include <stdexcept>
#include <iostream>


using std::cout;
using std::pair;
using std::vector;

Gitter::Gitter(int size) {
    groesse = size;
    for (int j = 0; j < size; j++) {
        vector<Cell> vector1;
        for (int i = 0; i < size; i++) {
            // Cell c(i + j * size);
            Cell c(0);
            vector1.push_back(c);
        }
        v.push_back(vector1);
    }
}

Cell &Gitter::cell_at(int xpos, int ypos) {
    if (ypos > -1 && xpos > -1 && ypos < groesse && xpos < groesse) {
        return v[ypos][xpos];
    } else {
        Cell c = Cell(-1);
        return c;
    }
}

vector<Cell> Gitter::row_at(int pos) {
    return v[pos];
}

int Gitter::size() {
    return groesse;
}

vector<Cell> Gitter::col_at(int pos) {
    vector<Cell> col;
    for (int i = 0; i < groesse; i++) {
        col.push_back(v[i][pos]);
    }
    return col;
}

Cell Gitter::get_neighbor_up(int posx, int posy) {
    if (posy > 0 && posx < groesse && posx > -1 && posy - 1 < groesse) {
        return v[posy - 1][posx];
    } else {
        return Cell(-1);
    }
}

Cell Gitter::get_neighbor_left(int posx, int posy) {
    if (posx > 0 && posy < groesse && posy > -1 && posx - 1 < groesse) {
        return v[posy][posx - 1];
    } else {
        return Cell(-1);
    }
}

Cell Gitter::get_neighbor_down(int posx, int posy) {
    if (posy < groesse - 1 && posx < groesse && posx > -1 && posy + 1 > -1) {
        return v[posy + 1][posx];
    } else {
        return Cell(-1);
    }
}

Cell Gitter::get_neighbor_right(int posx, int posy) {
    if (posx < groesse - 1 && posy < groesse && posy > -1 && posx + 1 > -1) {
        return v[posy][posx + 1];
    } else {
        return Cell(-1);
    }
}

/*int Gitter::use_function(string fkt) {
    if ((int) fkt.find("||") > -1 || (int) fkt.find("&&") > -1 || (int) fkt.find("->") > -1) {
        return 1;
    } else {
        return 2;
    }

}*/

vector<pair<int, int>> Gitter::neighbours(int posx, int posy) {
    vector<pair<int, int>> vector1;
    if (posy > 0 && posx < groesse && posx > -1 && posy - 1 < groesse) {
        vector1.push_back(pair<int, int>(posx, posy - 1));
    }
    if (posx > 0 && posy < groesse && posy > -1 && posx - 1 < groesse) {
        vector1.push_back(pair<int, int>(posx - 1, posy));
    }
    if (posx < groesse - 1 && posy < groesse && posy > -1 && posx + 1 > -1) {
        vector1.push_back(pair<int, int>(posx + 1, posy));
    }
    if (posy < groesse - 1 && posx < groesse && posx > -1 && posy + 1 > -1) {
        vector1.push_back(pair<int, int>(posx, posy + 1));
    }
    return vector1;
}

void Gitter::label(int xpos, int ypos) {
    v[ypos][xpos] = Cell(ypos * groesse + xpos);
}

vector<pair<pair<int, int>, int>> Gitter::neighbours_values(int posx, int posy) {
    vector<pair<pair<int, int>, int>> vector1;
    if (posy > 0 && posx < groesse && posx > -1 && posy - 1 < groesse) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx, posy - 1), v[posy - 1][posx].get_value()));
    }
    if (posx > 0 && posy < groesse && posy > -1 && posx - 1 < groesse) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx - 1, posy), v[posy][posx - 1].get_value()));
    }
    if (posx < groesse - 1 && posy < groesse && posy > -1 && posx + 1 > -1) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx + 1, posy), v[posy][posx + 1].get_value()));
    }
    if (posy < groesse - 1 && posx < groesse && posx > -1 && posy + 1 > -1) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx, posy + 1), v[posy + 1][posx].get_value()));
    }
    return vector1;
}
