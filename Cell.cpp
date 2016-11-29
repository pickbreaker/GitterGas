//
// Created by Benedikt on 08.11.2016.
//

#include <cmath>
#include <iostream>
#include "Cell.h"

using namespace std;

//Konstruktoren
Cell::Cell(int nummer, vector<int> Koordinaten) {
    id = nummer;
    value = 0;
    coords = Koordinaten;
};

Cell::Cell(int nummer, int wert, vector<int> Koordinaten) {
    id = nummer;
    value = wert;
    coords = Koordinaten;
}

Cell::Cell() {
    id = -1;
    value = -1;
    coords = vector<int>();
}

//Getter-Methoden
int Cell::get_id() const {
    return id;
}

int Cell::get_value() const {
    return value;
}

vector<int> Cell::get_coords() const {
    return coords;
}

Basis Cell::get_atoms() {
    return base;
}

//Relationen
vector<int> Cell::distance__to(Cell c) {
    vector<int> vector1;
    for (int i = 0; i < c.get_coords().size(); i++) {
        if (i < get_coords().size()) {
            vector1.push_back(c.get_coords()[i] - get_coords()[i]);
        }
    }
    return vector1;
}

double Cell::distance_to(Cell c) {
    double res = 0;
    vector<int> dist = distance__to(c);
    for (int i = 0; i < dist.size(); i++) {
        res += pow((double) dist[i], dist.size());
    }
    res = pow(res, 1.0 / dist.size());
    return res;
}

//Setter-Methoden
void Cell::set_value(int wert) {
    value = wert;
}

void Cell::move_to(vector<int> Koordinaten) {
    coords = Koordinaten;
}

void Cell::set_base(Basis basis) {
    for (int i = 0; i < basis.Atome().size(); ++i) {
        for (int j = 0; j < coords.size(); ++j) {
            try {
                if (j < basis.Atome()[i].second.size()) {
                    basis.Atome()[i].second[j] += coords[j];
                } else {
                    throw "Dimension Mismatch";
                }
            } catch (exception exception1) {
                cout << exception1.what();
            }
        }
    }
    base = basis;
}

//Operatoren
bool Cell::operator==(const Cell &comp) {
    return get_id() == comp.get_id() && get_value() == comp.get_value();
}

bool Cell::operator!=(const Cell &comp) {
    return !operator==(comp);
}

//Transformationen
void Cell::move_by(vector<int> Vektor) {
    for (int i = 0; i < coords.size(); i++) {
        if (i < Vektor.size()) {
            coords[i] = Vektor[i];
        }
    }
}