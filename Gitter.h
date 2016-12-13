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
    //Konstruktoren
    Gitter(int size,vector<vector<double>> base);

    //Getter-Methoden
    int size();

    Cell &cell_at(int xpos, int ypos);

    vector<Cell> row_at(int pos);

    vector<Cell> col_at(int pos);

    vector<vector<Cell>> Data();

    //Relationen
    Cell get_neighbor_up(int posx, int posy);

    Cell get_neighbor_left(int posx, int posy);

    Cell get_neighbor_down(int posx, int posy);

    Cell get_neighbor_right(int posx, int posy);

    vector<pair<int, int>> neighbours(int posx, int posy);

    vector<pair<Atom, vector<double>>> neighbours(int posx, int posy, int index);

    vector<pair<pair<int, int>, int>> neighbours_values(int posx, int posy);

    //Print-Methoden
    string print_coords();

    string print_ids();

    string print_values();

    string print_neighbours_at(int xpos, int ypos);

    //Setter-Methoden
    void label(int xpos, int ypos);

    void set_base(Basis basis);

    //Transformations-Methoden
    /*int use_function(string fkt);*/

    void xmirr();

    void ymirr();

    void centroinv();

private:
    //Eigenschaften
    vector<vector<Cell>> v;
    int groesse;
    vector<vector<double>> base_vectors;

//Interne Methoden
    void coords_pos_fix();

    double distance(vector<double> v1, vector<double> v2);

};


#endif //GITTERGAS_GITTER_H
