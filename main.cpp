#include <iostream>
#include <vector>
#include "Gitter.h"
#include "Basis.h"
#include "MathParser.h"
#include <initializer_list>

/*
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::get;*/
using namespace std;

//Gitterzellen durchnummerieren
void set_label(Gitter &gitter) {
    for (int i = 0; i < gitter.size(); i++) {
        for (int j = 0; j < gitter.size(); j++) {
            gitter.label(i, j);
        }
    }
}

//Gitter mit zufälligen Werten füllen
void set_value(Gitter &gitter) {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < gitter.size(); i++) {
        for (int j = 0; j < gitter.size(); j++) {
            gitter.cell_at(i, j).set_value(rand() % (gitter.size() * gitter.size()) + 1);
        }
    }
}

vector<pair<Atom, vector<double>>>
gen_base(vector<pair<Atom, vector<double>>> prev, string name, string zeichen, int o_zahl, double xrel, double yrel) {
    vector<double> coords;
    coords.push_back(xrel);
    coords.push_back(yrel);
    pair<Atom, vector<double>> paar;
    paar.first = Atom(name, zeichen, o_zahl);
    paar.second = coords;
    prev.push_back(paar);
    return prev;
}

int main() {
    //Gitter erstellen
    cout << "Gewünschte Größe: ";
    int groesse;
    vector<vector<double>> vector_base;
    vector<double> vector_base_1;
    vector<double> vector_base_2;
    cin >> groesse;
    cout << "Gitterbasisvektor 1:" << endl;
    cout << "x-Komponente: ";
    string value;
    double eval;
    MathParser parser;
    cin >> value;
    eval=parser.evalExpr(value);
    vector_base_1.push_back(eval);
    cout << "y-Komponente: ";
    cin >> value;
    eval=parser.evalExpr(value);
    vector_base_1.push_back(eval);
    vector_base.push_back(vector_base_1);
    cout << "Gitterbasisvektor 2:" << endl;
    cout << "x-Komponente: ";
    cin >> value;
    eval=parser.evalExpr(value);
    vector_base_2.push_back(eval);
    cout << "y-Komponente: ";
    cin >> value;
    eval=parser.evalExpr(value);
    vector_base_2.push_back(eval);
    vector_base.push_back(vector_base_2);
    cout << "Größe: " << groesse << endl;
    cout << "Gitter:" << endl;
    Gitter g(groesse, vector_base);
    set_label(g);
    set_value(g);
    cout << "Basis erstellen" << endl;
    Basis basis;
    vector<pair<Atom, vector<double>>> vector2;
    vector<pair<Atom, vector<double>>> base;
    char c = 'y';
    while (c == 'y') {
        string string1;
        string string2;
        int integer1;
        double double1;
        double double2;
        cout << "Name des Elements: ";
        cin >> string1;
        cout << "Formelzeichen des Elements: ";
        cin >> string2;
        cout << "Ordnungszahl: ";
        cin >> integer1;
        cout << "X-Position: ";
        cin >> double1;
        cout << "Y-Position: ";
        cin >> double2;
        cout << "Weiteres Element hinzufügen(y/n)? ";
        cin >> c;
        base = gen_base(base, string1, string2, integer1, double1, double2);
    }
    basis = Basis(base);
    g.set_base(basis);
    for (int j = 0; j < g.size(); ++j) {
        for (int i = 0; i < g.size(); ++i) {
            for (int k = 0; k < g.cell_at(j, i).get_atoms().Atome().size(); ++k) {
                cout << g.cell_at(j, i).get_atoms().Atome()[k].first.get_zeichen() << ":"
                     << g.cell_at(j, i).get_atoms().Atome()[k].second[0] << "|"
                     << g.cell_at(j, i).get_atoms().Atome()[k].second[1] << "\t";
            }
            cout << " |\t";
        }
        cout << endl;
    }

    //ID-Matrix ausgeben
    cout << g.print_ids();

    //Werte-Matrix ausgeben
    cout << g.print_values();

    vector<pair<pair<int, int>, int>> vector1;
    double mean = 0;
    //spezielle Position auslesen
    cout << "X-Position:";
    int xpos;
    cin >> xpos;
    cout << "Y-Position:";
    int ypos;
    cin >> ypos;
    int index;
    cout << "Atom-Nr.: ";
    cin >> index;
    cout << g.print_neighbours_at(xpos, ypos);

    //Arithmetisches Mittel der Nachbarwerte ausgeben
    mean = 0;
    vector1 = g.neighbours_values(xpos, ypos);
    for (int i = 0; i < vector1.size(); i++) {
        pair<pair<int, int>, int> entry;
        entry = vector1[i];
        cout << "(" << entry.first.first << "|" << entry.first.second << "): " << entry.second << endl;
        mean += entry.second;
    }
    if (vector1.size() != 0) {
        cout << "Arithmetisches Mittel der Nachbarwerte: " << mean / vector1.size() << endl;
    } else {
        cout << "Keine Nachbarn vorhanden" << endl;
    }

    //Nächstes Atom finden
    vector<pair<Atom, vector<double>>> vector3 = g.neighbours(xpos, ypos, index);
    for (int l = 0; l < vector3.size(); ++l) {
        cout << vector3[l].first.get_name() << "\t" << vector3[l].second[0] + 0.0 << "|" << vector3[l].second[1] + 0.0
             << endl;
    }
    if (vector3.size() > 0) {
        cout << g.cell_at(xpos, ypos).get_atoms().Atome()[index].second[0] << "|"
             << g.cell_at(xpos, ypos).get_atoms().Atome()[index].second[1] << endl;
    }

    //zufällige Position auslesen
    int xrand = rand() % g.size();
    int yrand = rand() % g.size();
    if (xpos != xrand && ypos != yrand) {
        cout << "Zufällige Position :(" << xrand << "|" << yrand << ")" << endl;
        cout << g.print_neighbours_at(xrand, yrand);
        mean = 0;
        vector1 = g.neighbours_values(xrand, yrand);
        for (int i = 0; i < vector1.size(); i++) {
            pair<pair<int, int>, int> entry;
            entry = vector1[i];
            cout << "(" << entry.first.first << "|" << entry.first.second << "): " << entry.second << endl;
            mean += entry.second;
        }
        if (vector1.size() != 0) {
            cout << "Arithmetisches Mittel der Nachbarwerte: " << mean / vector1.size() << endl;
        } else {
            cout << "Keine Nachbarn vorhanden" << endl;
        }
        if (vector3.size() > 0) {
            cout << "Distanz zwischen den Positionen: "
                 << (double) g.cell_at(xrand, yrand).distance_to(g.cell_at(xpos, ypos))
                 << endl;
        }
    } else {
        cout << "Zufällige Position entspricht eingegebener Position!" << endl;
    }

    cout << g.print_ids();
    cout << g.print_coords();
    cout << g.print_values();
/*  Deaktiviert aufgrund Inkompatibilität mit nicht-quadratischen Gittern
    g.xmirr();
    cout << g.print_ids();
    cout << g.print_coords();
    cout << g.print_values();
    g.ymirr();
    cout << g.print_ids();
    cout << g.print_coords();
    cout << g.print_values();
    g.centroinv();
    cout << g.print_ids();
    cout << g.print_coords();
    cout << g.print_values();
*/
    //Ende
    return 0;
}

