#include <iostream>
#include <vector>
#include "Gitter.h"

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;


int main() {
    cout << "Gewünchte Größe: ";
    int groesse;
    cin >> groesse;
    cout << "Größe: " << groesse << endl;
    cout << "Gitter:" << endl;
    Gitter g(groesse);
    for (int k = 0; k < groesse; k++) {
        for (int l = 0; l < groesse; l++) {
                cout <<  g.cell_at(k, l).get_id() << "\t";
        }
        cout << endl;
    }
    return 0;
}

