//
// Created by Benedikt on 29.11.2016.
//

#ifndef GITTERGAS_BASIS_H
#define GITTERGAS_BASIS_H


#include "Atom.h"
#include <vector>

using namespace std;

class Basis {
public:
    //Konstruktoren
    Basis(vector<pair<Atom, vector<double>>> atoms);

    Basis();

    //Getter-Methoden

    vector<pair<Atom, vector<double>>> &Atome();

private:
    vector<pair<Atom, vector<double>>> atome;
};


#endif //GITTERGAS_BASIS_H
