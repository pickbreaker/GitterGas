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
    Cell(int id, vector<double> Koordinaten);

    Cell(int id, int wert, vector<double> Koordinaten);

    Cell();

    //Getter-Methoden
    int get_id() const;

    int get_value() const;

    vector<double> get_coords() const;

    Basis get_atoms();

    //Relationen
    vector<double> distance__to(Cell c);

    double distance_to(Cell c);

    //Setter-Methoden
    void set_value(int wert);

    void move_to(vector<double> Koordinaten);

    void set_base(Basis basis);

    //Operatoren
    bool operator==(const Cell &comp);

    bool operator!=(const Cell &comp);

    //Transformationen
    void move_by(vector<double> Vektor);


private:
    //Eingeschaften
    int id;
    int value;
    vector<double> coords;
    Basis base;
};


#endif //GITTERGAS_CELL_H
