//
// Created by Benedikt on 29.11.2016.
//

#ifndef GITTERGAS_ATOM_H
#define GITTERGAS_ATOM_H

#include <string>

using namespace std;

class Atom {
public:
    //Konstruktoren
    Atom(string name, string zeichen, int Ordnungszahl);

    Atom();

    //Getter-Methoden
    string get_name();

    string get_zeichen();

    int get_O_Zahl();

    //Relationen

    //Print-Methoden

    //Setter-Methoden
    void set_name(string name);

    void set_zeichen(string zeichen);

    void set_O_Zahl(int Ordnungszahl);


    //Transformations-Methoden

private:
    //Eigenschaften
    string name;
    string zeichen;
    int Ordnungszahl;

    //Interne Methoden
};


#endif //GITTERGAS_ATOM_H
