//
// Created by Benedikt on 08.11.2016.
//

#include "Cell.h"

Cell::Cell(int nummer) {
    id = nummer;
    value = 0;
};

Cell::Cell(int nummer, int wert) {
    id = nummer;
    value = wert;
}

int Cell::get_id() {
    return id;
}

int Cell::get_value() {
    return value;
}

void Cell::set_value(int wert) {
    value = wert;
}