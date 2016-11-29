//
// Created by Benedikt on 08.11.2016.
//

#ifndef GITTERGAS_CELL_H
#define GITTERGAS_CELL_H

#include <vector>
#include "Basis.h"

using namespace std;

class Cell {
public:

    //Konstruktoren
    Cell(int id, vector<int> Koordinaten);

    Cell(int id, int wert, vector<int> Koordinaten);

    Cell();

    //Getter-Methoden
    int get_id() const;

    int get_value() const;

    vector<int> get_coords() const;

    Basis get_atoms();

    //Relationen
    vector<int> distance__to(Cell c);

    double distance_to(Cell c);

    //Setter-Methoden
    void set_value(int wert);

    void move_to(vector<int> Koordinaten);

    void set_base(Basis basis);

    //Operatoren
    bool operator==(const Cell &comp);

    bool operator!=(const Cell &comp);

    //Transformationen
    void move_by(vector<int> Vektor);


private:
    //Eingeschaften
    int id;
    int value;
    vector<int> coords;
    Basis base;
};


#endif //GITTERGAS_CELL_H
