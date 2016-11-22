//
// Created by Benedikt on 08.11.2016.
//

#include "Gitter.h"
#include <stdexcept>
#include <iostream>
#include <cstring>


using std::cout;
using std::pair;
using std::vector;

//Konstruktoren
Gitter::Gitter(int size) {
    groesse = size;
    for (int j = 0; j < size; j++) {
        vector<Cell> vector1;
        for (int i = 0; i < size; i++) {
            Cell c;
            vector1.push_back(c);
        }
        v.push_back(vector1);
    }
}

//Getter-Methoden
int Gitter::size() {
    return groesse;
}

Cell &Gitter::cell_at(int xpos, int ypos) {
    if (ypos > -1 && xpos > -1 && ypos < groesse && xpos < groesse) {
        return v[ypos][xpos];
    } else {
        Cell c;
        return c;
    }
}

vector<Cell> Gitter::row_at(int pos) {
    return v[pos];
}


vector<Cell> Gitter::col_at(int pos) {
    vector<Cell> col;
    for (int i = 0; i < groesse; i++) {
        col.push_back(v[i][pos]);
    }
    return col;
}

vector<vector<Cell>> Gitter::Data() {
    return v;
}

//Relationen
Cell Gitter::get_neighbor_up(int posx, int posy) {
    if (posy > 0 && posx < groesse && posx > -1 && posy - 1 < groesse) {
        return v[posy - 1][posx];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_left(int posx, int posy) {
    if (posx > 0 && posy < groesse && posy > -1 && posx - 1 < groesse) {
        return v[posy][posx - 1];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_down(int posx, int posy) {
    if (posy < groesse - 1 && posx < groesse && posx > -1 && posy + 1 > -1) {
        return v[posy + 1][posx];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_right(int posx, int posy) {
    if (posx < groesse - 1 && posy < groesse && posy > -1 && posx + 1 > -1) {
        return v[posy][posx + 1];
    } else {
        return Cell();
    }
}

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

//Print-Methoden
string Gitter::print_coords() {
    string output = "";
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            output += "(";
            output += to_string(cell_at(j, i).get_coords()[0]);
            output += "|";
            output += to_string(cell_at(j, i).get_coords()[1]);
            output += ")\t";
        }
        output += "\n";
    }
    output += "\n";
    return output;
}

string Gitter::print_ids() {
    string output = "";
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            output += to_string(cell_at(j, i).get_id());
            output += "\t";
        }
        output += "\n";
    }
    output += "\n";
    return output;
}

string Gitter::print_values() {
    string output = "";
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            output += to_string(cell_at(j, i).get_value());
            output += "\t";
        }
        output += "\n";
    }
    output += "\n";
    return output;
}

string Gitter::print_neighbours_at(int xpos, int ypos) {
    string output = "";
    output += " \t";
    output += to_string(get_neighbor_up(xpos, ypos).get_id()) + " \t\t\n";
    output += to_string(get_neighbor_left(xpos, ypos).get_id()) + " \t";
    output += to_string(cell_at(xpos, ypos).get_id()) + " \t";
    output += to_string(get_neighbor_right(xpos, ypos).get_id()) + " \t\n\t";
    output += to_string(get_neighbor_down(xpos, ypos).get_id()) + " \t\n";
    return output;
}

//Setter-Methoden
void Gitter::label(int xpos, int ypos) {
    vector<int> vector2;
    vector2.push_back(xpos);
    vector2.push_back(ypos);
    v[ypos][xpos] = Cell(ypos * groesse + xpos, vector2);
}

//Transformations-Methoden
/*int Gitter::use_function(string fkt) {
    if ((int) fkt.find("||") > -1 || (int) fkt.find("&&") > -1 || (int) fkt.find("->") > -1) {
        return 1;
    } else {
        return 2;
    }

}*/

void Gitter::xmirr() {
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            cell_at(j, i).move_to(vector<int>({abs(j - (size() - 1)), i}));
        }
    }
    coords_pos_fix();
}

void Gitter::ymirr() {
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            cell_at(j, i).move_to(vector<int>({j, abs(i - (size() - 1))}));
        }
    }
    coords_pos_fix();
}

void Gitter::centroinv() {
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            cell_at(j, i).move_to(vector<int>({abs(j - (size() - 1)), abs(i - (size() - 1))}));
        }
    }
    coords_pos_fix();
}

void Gitter::coords_pos_fix() {
    Gitter neu(size());
    for (int j = 0; j < size(); j++) {
        for (int i = 0; i < size(); i++) {
            neu.cell_at(cell_at(j, i).get_coords()[0], cell_at(j, i).get_coords()[1]) = cell_at(j, i);
        }
    }
    v = neu.Data();
}