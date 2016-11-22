//
// Created by Benedikt on 08.11.2016.
//

#ifndef GITTERGAS_CELL_H
#define GITTERGAS_CELL_H


class Cell {
public:
    Cell(int id);

    int get_id();

    void set_value(int wert);

    int get_value();

    Cell(int id, int wert);

private:
    int id;
    int value;
};


#endif //GITTERGAS_CELL_H
