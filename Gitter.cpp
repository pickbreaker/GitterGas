//
// Created by Benedikt on 08.11.2016.
//

#include "Gitter.h"
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <math.h>


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
    if (posx > -1 && posy > 0 && posx < groesse && posy < groesse + 1) {
        return v[posy - 1][posx];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_left(int posx, int posy) {
    if (posx > 0 && posy > -1 && posx < groesse + 1 && posy < groesse) {
        return v[posy][posx - 1];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_right(int posx, int posy) {
    if (posx > -2 && posy > -1 && posx < groesse - 1 && posy < groesse) {
        return v[posy][posx + 1];
    } else {
        return Cell();
    }
}

Cell Gitter::get_neighbor_down(int posx, int posy) {
    if (posx > -1 && posy > -2 && posx < groesse && posy < groesse - 1) {
        return v[posy + 1][posx];
    } else {
        return Cell();
    }
}

vector<pair<int, int>> Gitter::neighbours(int posx, int posy) {
    vector<pair<int, int>> vector1;
    if (posx > -1 && posy > 0 && posx < groesse && posy < groesse + 1) {
        vector1.push_back(pair<int, int>(posx, posy - 1));
    }
    if (posx > 0 && posy > -1 && posx < groesse + 1 && posy < groesse) {
        vector1.push_back(pair<int, int>(posx - 1, posy));
    }
    if (posx > -2 && posy > -1 && posx < groesse - 1 && posy < groesse) {
        vector1.push_back(pair<int, int>(posx + 1, posy));
    }
    if (posx > -1 && posy > -2 && posx < groesse && posy < groesse - 1) {
        vector1.push_back(pair<int, int>(posx, posy + 1));
    }
    return vector1;
}

vector<pair<Atom, vector<double>>> Gitter::neighbours(int posx, int posy, int index) {
    vector<pair<int, int>> vector1;
    if (posx > -1 && posy > -1 && posx < groesse && posy < groesse) {
        if (posx > -1 && posy > 0 && posx < groesse && posy < groesse + 1) {
            vector1.push_back(pair<int, int>(posx, posy - 1));
        }
        if (posx > 0 && posy > -1 && posx < groesse + 1 && posy < groesse) {
            vector1.push_back(pair<int, int>(posx - 1, posy));
        }
        if (posx > -2 && posy > -1 && posx < groesse - 1 && posy < groesse) {
            vector1.push_back(pair<int, int>(posx + 1, posy));
        }
        if (posx > -1 && posy > -2 && posx < groesse && posy < groesse - 1) {
            vector1.push_back(pair<int, int>(posx, posy + 1));
        }
        if (posx > 0 && posy > 0 && posx < groesse + 1 && posy < groesse + 1) {
            vector1.push_back(pair<int, int>(posx - 1, posy - 1));
        }
        if (posx > -2 && posy > 0 && posx < groesse - 1 && posy < groesse + 1) {
            vector1.push_back(pair<int, int>(posx + 1, posy - 1));
        }
        if (posx > 0 && posy > -2 && posx < groesse + 1 && posy < groesse - 1) {
            vector1.push_back(pair<int, int>(posx - 1, posy + 1));
        }
        if (posx > -2 && posy > -2 && posx < groesse - 1 && posy < groesse - 1) {
            vector1.push_back(pair<int, int>(posx + 1, posy + 1));
        }
        vector<pair<Atom, vector<double>>> vector2;
        for (int i = 0; i < vector1.size(); ++i) {
            for (int j = 0; j < cell_at(vector1[i].first, vector1[i].second).get_atoms().Atome().size(); ++j) {
                if (vector2.size() == 0) {
                    pair<Atom, vector<double>> paar;
                    paar = pair<Atom, vector<double >>(Atom(), vector<double>({-2, -2}));
                    vector2.push_back(paar);
                }
                if (distance(cell_at(posx, posy).get_atoms().Atome()[index].second,
                             cell_at(vector1[i].first, vector1[i].second).get_atoms().Atome()[j].second) <
                    distance(cell_at(posx, posy).get_atoms().Atome()[index].second, vector2[0].second)) {
                    vector2.clear();
                    vector2.push_back(cell_at(vector1[i].first, vector1[i].second).get_atoms().Atome()[j]);
                } else if (distance(cell_at(posx, posy).get_atoms().Atome()[index].second,
                                    cell_at(vector1[i].first, vector1[i].second).get_atoms().Atome()[j].second) ==
                           distance(cell_at(posx, posy).get_atoms().Atome()[index].second, vector2[0].second)) {
                    vector2.push_back(cell_at(vector1[i].first, vector1[i].second).get_atoms().Atome()[j]);
                }

            }

        }
        for (int i = 0; i < cell_at(posx, posy).get_atoms().Atome().size(); i++) {
            if (i != index) {
                if (vector2.size() == 0) {
                    pair<Atom, vector<double>> paar;
                    paar = pair<Atom, vector<double >>(Atom(), vector<double>({-2, -2}));
                    vector2.push_back(paar);
                } else {
                    if (distance(cell_at(posx, posy).get_atoms().Atome()[index].second,
                                 cell_at(posx, posy).get_atoms().Atome()[i].second) <
                        distance(cell_at(posx, posy).get_atoms().Atome()[index].second, vector2[0].second)) {
                        vector2.clear();
                        vector2.push_back(cell_at(posx, posy).get_atoms().Atome()[i]);
                    } else if (distance(cell_at(posx, posy).get_atoms().Atome()[index].second,
                                        cell_at(posx, posy).get_atoms().Atome()[i].second) ==
                               distance(cell_at(posx, posy).get_atoms().Atome()[index].second, vector2[0].second)) {
                        vector2.push_back(cell_at(posx, posy).get_atoms().Atome()[i]);
                    }
                }
            }
        }
        return vector2;
    } else {
        vector<pair<Atom, vector<double>>> vector2;
        return vector2;
    }
}

vector<pair<pair<int, int>, int>> Gitter::neighbours_values(int posx, int posy) {
    vector<pair<pair<int, int>, int>> vector1;
    if (posx > -1 && posy > 0 && posx < groesse && posy < groesse + 1) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx, posy - 1), v[posy - 1][posx].get_value()));
    }
    if (posx > 0 && posy > -1 && posx < groesse + 1 && posy < groesse) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx - 1, posy), v[posy][posx - 1].get_value()));
    }
    if (posx > -2 && posy > -1 && posx < groesse - 1 && posy < groesse) {
        vector1.push_back(pair<pair<int, int>, int>(pair<int, int>(posx + 1, posy), v[posy][posx + 1].get_value()));
    }
    if (posx > -1 && posy > -2 && posx < groesse && posy < groesse - 1) {
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
    if (xpos > -1 && ypos > -1 && xpos < groesse && ypos < groesse) {
        output += to_string(cell_at(xpos, ypos).get_id()) + " \t";
    } else {
        output += "-1 \t";
    }
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

void Gitter::set_base(Basis basis) {
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            cell_at(j, i).set_base(basis);
        }
    }
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

double Gitter::distance(vector<double> v1, vector<double> v2) {
    double dist = 0;
    try {
        for (int i = 0; i < v1.size(); ++i) {
            if (i < v2.size()) {
                dist += (v1[i] - v2[i]) * (v1[i] - v2[i]);
            } else {
                throw "Dimension Mismatch";
            }
        }
        dist = pow(dist, 2);
    } catch (exception exception1) {
        cout << exception1.what() << endl;
    }
}