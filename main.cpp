#include <iostream>
#include <vector>
#include "Gitter.h"
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
    srand((unsigned int)time(NULL));
    for (int i = 0; i < gitter.size(); i++) {
        for (int j = 0; j < gitter.size(); j++) {
            gitter.cell_at(i, j).set_value(rand() % (gitter.size() * gitter.size()) + 1);
        }
    }
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

    //ID-Matrix ausgeben
    for (int k = 0; k < groesse; k++) {
        for (int l = 0; l < groesse; l++) {
            cout << g.cell_at(l, k).get_id() << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //Werte-Matrix ausgeben
    for (int k = 0; k < groesse; k++) {
        for (int l = 0; l < groesse; l++) {
            cout << g.cell_at(l, k).get_value() << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //Werte-Matrix verändern und ausgeben
    vector<pair<pair<int, int>, int>> vector1;
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
                g.cell_at(l, k).set_value((int)mean);
            }
            cout << g.cell_at(l, k).get_value() << "\t";
        }
        cout << endl;
    }

    //spezielle Position auslesen
    cout << "X-Position:";
    int xpos;
    cin >> xpos;
    cout << "Y-Position:";
    int ypos;
    cin >> ypos;
    cout << " \t";
    cout << g.get_neighbor_up(xpos, ypos).get_id() << " \t";
    cout << " \t" << endl;
    cout << g.get_neighbor_left(xpos, ypos).get_id() << " \t";
    cout << g.cell_at(xpos, ypos).get_id() << " \t";
    cout << g.get_neighbor_right(xpos, ypos).get_id() << " \t" << endl;
    cout << " \t";
    cout << g.get_neighbor_down(xpos, ypos).get_id() << " ";
    cout << " \t" << endl;
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

    //zufällige Position auslesen
    xpos = rand() % g.size();
    ypos = rand() % g.size();
    cout << "Zufällige Position :(" << xpos << "|" << ypos << ")" << endl;
    cout << " \t";
    cout << g.get_neighbor_up(xpos, ypos).get_id() << " \t";
    cout << " \t" << endl;
    cout << g.get_neighbor_left(xpos, ypos).get_id() << " \t";
    cout << g.cell_at(xpos, ypos).get_id() << " \t";
    cout << g.get_neighbor_right(xpos, ypos).get_id() << " \t" << endl;
    cout << " \t";
    cout << g.get_neighbor_down(xpos, ypos).get_id() << " ";
    cout << " \t" << endl;
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

    //Ende
    return 0;
}

