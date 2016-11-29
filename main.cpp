#include <iostream>
#include <vector>
#include "Gitter.h"
#include "Basis.h"
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
    cin >> groesse;
    cout << "Größe: " << groesse << endl;
    cout << "Gitter:" << endl;
    Gitter g(groesse);
    set_label(g);
    set_value(g);
    Basis basis;
    vector<pair<Atom, vector<double>>> vector2;
    basis = Basis(gen_base(gen_base(gen_base(vector2, "Sauerstoff", "O", 8, 0.0, 0.0), "Natrium", "Na", 11, 0.25, 0.25),
                           "Wasserstoff", "H", 1, 1.0 / 16.0, 1.0 / 16.0));
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
    /*  for (int k = 0; k < groesse; k++) {
          for (int l = 0; l < groesse; l++) {
              cout << g.cell_at(l, k).get_id() << "\t";
          }
          cout << endl;
      }
      cout << endl;*/
    cout << g.print_ids();

    //Werte-Matrix ausgeben
    /* for (int k = 0; k < groesse; k++) {
         for (int l = 0; l < groesse; l++) {
             cout << g.cell_at(l, k).get_value() << "\t";
         }
         cout << endl;
     }
     cout << endl;*/
    cout << g.print_values();

    //Werte-Matrix verändern und ausgeben
    /*  vector<pair<pair<int, int>, int>> vector1;
      double mean = 0;
      for (int k = 0; k < groesse; k++) {
          for (int l = 0; l < groesse; l++) {
              vector1 = g.neighbours_values(l, k);
              if (g.size() > 0) {
                  for (int i = 0; i < vector1.size(); i++) {
                      pair<pair<int, int>, int> entry;
                      entry = vector1[i];
                      mean += entry.second;
                  }
                  mean = mean / g.size();
                  g.cell_at(l, k).set_value((int) mean);
              }
              cout << g.cell_at(l, k).get_value() << "\t";
          }
          cout << endl;
      }*/
    vector<pair<pair<int, int>, int>> vector1;
    double mean = 0;
    //spezielle Position auslesen
    cout << "X-Position:";
    int xpos;
    cin >> xpos;
    cout << "Y-Position:";
    int ypos;
    cin >> ypos;
    cout << g.print_neighbours_at(xpos, ypos);
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
    vector<pair<Atom, vector<double>>> vector3 = g.neighbours(xpos, ypos, 1);
    for (int l = 0; l < vector3.size(); ++l) {
        cout << vector3[l].first.get_name() << "\t" << vector3[l].second[0] << "|" << vector3[l].second[1] << endl;
    }

    //zufällige Position auslesen
    int xrand = rand() % g.size();
    int yrand = rand() % g.size();
    if (g.cell_at(xpos, ypos) != g.cell_at(xrand, yrand)) {
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
        cout << "Distanz zwischen den Positionen: "
             << (double) g.cell_at(xrand, yrand).distance_to(g.cell_at(xpos, ypos))
             << endl;

    } else {
        cout << "Zufällige Position entspricht eingegebener Position!" << endl;
    }

    cout << g.print_ids();
    cout << g.print_coords();
    cout << g.print_values();
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

    //Ende
    return 0;
}

