//
// Created by Benedikt on 29.11.2016.
//

#include "Atom.h"
#include <string>

//Konstruktoren
Atom::Atom(string name, string zeichen, int Ordnungszahl) {
    this->name = name;
    this->zeichen = zeichen;
    this->Ordnungszahl = Ordnungszahl;
}

Atom::Atom() {
    name = "unknown";
    zeichen = "?";
    Ordnungszahl = 0;
}

//Getter-Methoden
string Atom::get_name() {
    return name;
}

string Atom::get_zeichen() {
    return zeichen;
}

int Atom::get_O_Zahl() {
    return Ordnungszahl;
}

//Setter-Methoden

void Atom::set_name(string name) {
    this->name = name;
}

void Atom::set_zeichen(string zeichen) {
    this->zeichen = zeichen;
}

void Atom::set_O_Zahl(int Ordnungszahl) {
    this->Ordnungszahl = Ordnungszahl;
}