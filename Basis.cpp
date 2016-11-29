//
// Created by Benedikt on 29.11.2016.
//

#include "Basis.h"

//Konstruktoren
Basis::Basis(vector<pair<Atom, vector<double>>> atoms) {
    atome = atoms;
}

Basis::Basis() {
    atome = vector<pair<Atom, vector<double>>>({});
}

vector<pair<Atom, vector<double>>> &Basis::Atome() {
    return atome;
}
